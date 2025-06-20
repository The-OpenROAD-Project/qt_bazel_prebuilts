// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:critical reason:network-protocol

//#define QNETWORKACCESSHTTPBACKEND_DEBUG

#include "qnetworkreplyhttpimpl_p.h"
#include "qnetworkaccessmanager_p.h"
#include "qnetworkaccesscache_p.h"
#include "qabstractnetworkcache.h"
#include "qnetworkrequest.h"
#include "qnetworkreply.h"
#include "qnetworkrequest_p.h"
#include "qnetworkcookie.h"
#include "qnetworkcookie_p.h"
#include "QtCore/qdatetime.h"
#include "QtCore/qelapsedtimer.h"
#include "QtNetwork/qsslconfiguration.h"
#include "qhttpthreaddelegate_p.h"
#include "qhsts_p.h"
#include "qthread.h"
#include "QtCore/qcoreapplication.h"

#include <QtCore/private/qthread_p.h>
#include <QtCore/private/qtools_p.h>

#include "qnetworkcookiejar.h"
#include "qnetconmonitor_p.h"

#include "qnetworkreplyimpl_p.h"

#include <string.h>             // for strchr

QT_BEGIN_NAMESPACE

using namespace Qt::StringLiterals;
using namespace QtMiscUtils;
using namespace std::chrono_literals;

class QNetworkProxy;

static inline QByteArray rangeName() { return "Range"_ba; }
static inline QByteArray cacheControlName() { return "Cache-Control"_ba; }
static constexpr QByteArrayView bytesEqualPrefix() noexcept { return "bytes="; }

// ### merge with nextField in cookiejar.cpp
static QHash<QByteArray, QByteArray> parseHttpOptionHeader(QByteArrayView header)
{
    // The HTTP header is of the form:
    // header          = #1(directives)
    // directives      = token | value-directive
    // value-directive = token "=" (token | quoted-string)
    QHash<QByteArray, QByteArray> result;

    int pos = 0;
    while (true) {
        // skip spaces
        pos = nextNonWhitespace(header, pos);
        if (pos == header.size())
            return result;      // end of parsing

        // pos points to a non-whitespace
        int comma = header.indexOf(',', pos);
        int equal = header.indexOf('=', pos);
        if (comma == pos || equal == pos)
            // huh? Broken header.
            return result;

        // The key name is delimited by either a comma, an equal sign or the end
        // of the header, whichever comes first
        int end = comma;
        if (end == -1)
            end = header.size();
        if (equal != -1 && end > equal)
            end = equal;        // equal sign comes before comma/end
        const auto key = header.sliced(pos, end - pos).trimmed();
        pos = end + 1;

        if (uint(equal) < uint(comma)) {
            // case: token "=" (token | quoted-string)
            // skip spaces
            pos = nextNonWhitespace(header, pos);
            if (pos == header.size())
                // huh? Broken header
                return result;

            QByteArray value;
            value.reserve(header.size() - pos);
            if (header.at(pos) == '"') {
                // case: quoted-string
                // quoted-string  = ( <"> *(qdtext | quoted-pair ) <"> )
                // qdtext         = <any TEXT except <">>
                // quoted-pair    = "\" CHAR
                ++pos;
                while (pos < header.size()) {
                    char c = header.at(pos);
                    if (c == '"') {
                        // end of quoted text
                        break;
                    } else if (c == '\\') {
                        ++pos;
                        if (pos >= header.size())
                            // broken header
                            return result;
                        c = header.at(pos);
                    }

                    value += c;
                    ++pos;
                }
            } else {
                const auto isSeparator = [](char c) {
                    static const char separators[] = "()<>@,;:\\\"/[]?={}";
                    return isLWS(c) || strchr(separators, c) != nullptr;
                };

                // case: token
                while (pos < header.size()) {
                    char c = header.at(pos);
                    if (isSeparator(c))
                        break;
                    value += c;
                    ++pos;
                }
            }

            result.insert(key.toByteArray().toLower(), value);

            // find the comma now:
            comma = header.indexOf(',', pos);
            if (comma == -1)
                return result;  // end of parsing
            pos = comma + 1;
        } else {
            // case: token
            // key is already set
            result.insert(key.toByteArray().toLower(), QByteArray());
        }
    }
}

QNetworkReplyHttpImpl::QNetworkReplyHttpImpl(QNetworkAccessManager* const manager,
                                             const QNetworkRequest& request,
                                             QNetworkAccessManager::Operation& operation,
                                             QIODevice* outgoingData)
    : QNetworkReply(*new QNetworkReplyHttpImplPrivate, manager)
{
    Q_D(QNetworkReplyHttpImpl);
    Q_ASSERT(manager);
    d->manager = manager;
    d->managerPrivate = manager->d_func();
    d->request = request;
    d->originalRequest = request;
    d->operation = operation;
    d->outgoingData = outgoingData;
    d->url = request.url();
#ifndef QT_NO_SSL
    if (request.url().scheme() == "https"_L1)
        d->sslConfiguration.reset(new QSslConfiguration(request.sslConfiguration()));
#endif

    QObjectPrivate::connect(this, &QNetworkReplyHttpImpl::redirectAllowed, d,
            &QNetworkReplyHttpImplPrivate::followRedirect, Qt::QueuedConnection);

    // FIXME Later maybe set to Unbuffered, especially if it is zerocopy or from cache?
    QIODevice::open(QIODevice::ReadOnly);


    // Internal code that does a HTTP reply for the synchronous Ajax
    // in Qt WebKit.
    QVariant synchronousHttpAttribute = request.attribute(
            static_cast<QNetworkRequest::Attribute>(QNetworkRequest::SynchronousRequestAttribute));
    if (synchronousHttpAttribute.isValid()) {
        d->synchronous = synchronousHttpAttribute.toBool();
        if (d->synchronous && outgoingData) {
            // The synchronous HTTP is a corner case, we will put all upload data in one big QByteArray in the outgoingDataBuffer.
            // Yes, this is not the most efficient thing to do, but on the other hand synchronous XHR needs to die anyway.
            d->outgoingDataBuffer = std::make_shared<QRingBuffer>();
            qint64 previousDataSize = 0;
            do {
                previousDataSize = d->outgoingDataBuffer->size();
                d->outgoingDataBuffer->append(d->outgoingData->readAll());
            } while (d->outgoingDataBuffer->size() != previousDataSize);
            d->_q_startOperation();
            return;
        }
    }


    if (outgoingData) {
        // there is data to be uploaded, e.g. HTTP POST.

        if (!d->outgoingData->isSequential()) {
            // fixed size non-sequential (random-access)
            // just start the operation
            QMetaObject::invokeMethod(this, "_q_startOperation", Qt::QueuedConnection);
            // FIXME make direct call?
        } else {
            bool bufferingDisallowed =
                    request.attribute(QNetworkRequest::DoNotBufferUploadDataAttribute,
                                  false).toBool();

            if (bufferingDisallowed) {
                // if a valid content-length header for the request was supplied, we can disable buffering
                // if not, we will buffer anyway

                const auto sizeOpt = QNetworkHeadersPrivate::toInt(
                        request.headers().value(QHttpHeaders::WellKnownHeader::ContentLength));
                 if (sizeOpt) {
                    QMetaObject::invokeMethod(this, "_q_startOperation", Qt::QueuedConnection);
                    // FIXME make direct call?
                } else {
                    d->state = d->Buffering;
                    QMetaObject::invokeMethod(this, "_q_bufferOutgoingData", Qt::QueuedConnection);
                }
            } else {
                // _q_startOperation will be called when the buffering has finished.
                d->state = d->Buffering;
                QMetaObject::invokeMethod(this, "_q_bufferOutgoingData", Qt::QueuedConnection);
            }
        }
    } else {
        // No outgoing data (POST, ..)
        d->_q_startOperation();
    }
}

QNetworkReplyHttpImpl::~QNetworkReplyHttpImpl()
{
    // This will do nothing if the request was already finished or aborted
    emit abortHttpRequest();
}

void QNetworkReplyHttpImpl::close()
{
    Q_D(QNetworkReplyHttpImpl);

    if (d->state == QNetworkReplyPrivate::Aborted ||
        d->state == QNetworkReplyPrivate::Finished)
        return;

    // According to the documentation close only stops the download
    // by closing we can ignore the download part and continue uploading.
    QNetworkReply::close();

    // call finished which will emit signals
    // FIXME shouldn't this be emitted Queued?
    d->error(OperationCanceledError, tr("Operation canceled"));
    d->finished();
}

void QNetworkReplyHttpImpl::abort()
{
    Q_D(QNetworkReplyHttpImpl);
    // FIXME
    if (d->state == QNetworkReplyPrivate::Finished || d->state == QNetworkReplyPrivate::Aborted)
        return;

    QNetworkReply::close();

    if (d->state != QNetworkReplyPrivate::Finished) {
        // call finished which will emit signals
        // FIXME shouldn't this be emitted Queued?
        d->error(OperationCanceledError, tr("Operation canceled"));
        d->finished();
    }

    d->state = QNetworkReplyPrivate::Aborted;

    emit abortHttpRequest();
}

qint64 QNetworkReplyHttpImpl::bytesAvailable() const
{
    Q_D(const QNetworkReplyHttpImpl);

    // if we load from cache device
    if (d->cacheLoadDevice) {
        return QNetworkReply::bytesAvailable() + d->cacheLoadDevice->bytesAvailable();
    }

    // zerocopy buffer
    if (d->downloadZerocopyBuffer) {
        return QNetworkReply::bytesAvailable() + d->downloadBufferCurrentSize - d->downloadBufferReadPosition;
    }

    if (d->decompressHelper.isValid()) {
        if (d->decompressHelper.isCountingBytes())
            return QNetworkReply::bytesAvailable() + d->decompressHelper.uncompressedSize();
        if (d->decompressHelper.hasData())
            return QNetworkReply::bytesAvailable() + 1;
    }

    // normal buffer
    return QNetworkReply::bytesAvailable();
}

bool QNetworkReplyHttpImpl::isSequential () const
{
    // FIXME In the cache of a cached load or the zero-copy buffer we could actually be non-sequential.
    // FIXME however this requires us to implement stuff like seek() too.
    return true;
}

qint64 QNetworkReplyHttpImpl::size() const
{
    // FIXME At some point, this could return a proper value, e.g. if we're non-sequential.
    return QNetworkReply::size();
}

qint64 QNetworkReplyHttpImpl::readData(char* data, qint64 maxlen)
{
    Q_D(QNetworkReplyHttpImpl);

    // cacheload device
    if (d->cacheLoadDevice) {
        // FIXME bytesdownloaded, position etc?

        qint64 ret = d->cacheLoadDevice->read(data, maxlen);
        return ret;
    }

    // zerocopy buffer
    if (d->downloadZerocopyBuffer) {
        // FIXME bytesdownloaded, position etc?

        qint64 howMuch = qMin(maxlen, (d->downloadBufferCurrentSize - d->downloadBufferReadPosition));
        memcpy(data, d->downloadZerocopyBuffer + d->downloadBufferReadPosition, howMuch);
        d->downloadBufferReadPosition += howMuch;
        return howMuch;

    }

    if (d->decompressHelper.isValid() && (d->decompressHelper.hasData() || !isFinished())) {
        if (maxlen == 0 || !d->decompressHelper.hasData())
            return 0;
        const qint64 bytesRead = d->decompressHelper.read(data, maxlen);
        if (!d->decompressHelper.isValid()) {
            d->error(QNetworkReplyImpl::NetworkError::UnknownContentError,
                     QCoreApplication::translate("QHttp", "Decompression failed: %1")
                             .arg(d->decompressHelper.errorString()));
            d->decompressHelper.clear();
            return -1;
        }
        if (d->cacheSaveDevice) {
            // Need to write to the cache now that we have the data
            d->cacheSaveDevice->write(data, bytesRead);
            // ... and if we've read everything then the cache can be closed.
            if (isFinished() && !d->decompressHelper.hasData())
                d->completeCacheSave();
        }
        // In case of buffer size restriction we need to emit that it has been emptied
        qint64 wasBuffered = d->bytesBuffered;
        d->bytesBuffered = 0;
        if (readBufferSize())
            emit readBufferFreed(wasBuffered);
        return bytesRead;
    }

    // normal buffer
    if (d->state == d->Finished || d->state == d->Aborted)
        return -1;

    qint64 wasBuffered = d->bytesBuffered;
    d->bytesBuffered = 0;
    if (readBufferSize())
        emit readBufferFreed(wasBuffered);
    return 0;
}

void QNetworkReplyHttpImpl::setReadBufferSize(qint64 size)
{
    QNetworkReply::setReadBufferSize(size);
    emit readBufferSizeChanged(size);
    return;
}

bool QNetworkReplyHttpImpl::canReadLine () const
{
    Q_D(const QNetworkReplyHttpImpl);

    if (QNetworkReply::canReadLine())
        return true;

    if (d->cacheLoadDevice)
        return d->cacheLoadDevice->canReadLine();

    if (d->downloadZerocopyBuffer)
        return memchr(d->downloadZerocopyBuffer + d->downloadBufferReadPosition, '\n', d->downloadBufferCurrentSize - d->downloadBufferReadPosition);

    return false;
}

#ifndef QT_NO_SSL
void QNetworkReplyHttpImpl::ignoreSslErrors()
{
    Q_D(QNetworkReplyHttpImpl);
    Q_ASSERT(d->managerPrivate);

    if (d->managerPrivate->stsEnabled && d->managerPrivate->stsCache.isKnownHost(url())) {
        // We cannot ignore any Security Transport-related errors for this host.
        return;
    }

    d->pendingIgnoreAllSslErrors = true;
}

void QNetworkReplyHttpImpl::ignoreSslErrorsImplementation(const QList<QSslError> &errors)
{
    Q_D(QNetworkReplyHttpImpl);
    Q_ASSERT(d->managerPrivate);

    if (d->managerPrivate->stsEnabled && d->managerPrivate->stsCache.isKnownHost(url())) {
        // We cannot ignore any Security Transport-related errors for this host.
        return;
    }

    // the pending list is set if QNetworkReply::ignoreSslErrors(const QList<QSslError> &errors)
    // is called before QNetworkAccessManager::get() (or post(), etc.)
    d->pendingIgnoreSslErrorsList = errors;
}

void QNetworkReplyHttpImpl::setSslConfigurationImplementation(const QSslConfiguration &newconfig)
{
    // Setting a SSL configuration on a reply is not supported. The user needs to set
    // her/his QSslConfiguration on the QNetworkRequest.
    Q_UNUSED(newconfig);
}

void QNetworkReplyHttpImpl::sslConfigurationImplementation(QSslConfiguration &configuration) const
{
    Q_D(const QNetworkReplyHttpImpl);
    if (d->sslConfiguration.data())
        configuration = *d->sslConfiguration;
    else
        configuration = request().sslConfiguration();
}
#endif

QNetworkReplyHttpImplPrivate::QNetworkReplyHttpImplPrivate()
    : QNetworkReplyPrivate()
    , manager(nullptr)
    , managerPrivate(nullptr)
    , synchronous(false)
    , state(Idle)
    , statusCode(0)
    , uploadByteDevicePosition(false)
    , uploadDeviceChoking(false)
    , outgoingData(nullptr)
    , bytesUploaded(-1)
    , cacheLoadDevice(nullptr)
    , loadingFromCache(false)
    , cacheSaveDevice(nullptr)
    , cacheEnabled(false)
    , resumeOffset(0)
    , bytesDownloaded(0)
    , bytesBuffered(0)
    , transferTimeout(nullptr)
    , downloadBufferReadPosition(0)
    , downloadBufferCurrentSize(0)
    , downloadZerocopyBuffer(nullptr)
    , pendingDownloadDataEmissions(std::make_shared<QAtomicInt>())
    , pendingDownloadProgressEmissions(std::make_shared<QAtomicInt>())
    #ifndef QT_NO_SSL
    , pendingIgnoreAllSslErrors(false)
    #endif

{
}

QNetworkReplyHttpImplPrivate::~QNetworkReplyHttpImplPrivate()
{
}

/*
    For a given httpRequest
    1) If AlwaysNetwork, return
    2) If we have a cache entry for this url populate headers so the server can return 304
    3) Calculate if response_is_fresh and if so send the cache and set loadedFromCache to true
 */
bool QNetworkReplyHttpImplPrivate::loadFromCacheIfAllowed(QHttpNetworkRequest &httpRequest)
{
    QNetworkRequest::CacheLoadControl CacheLoadControlAttribute =
        (QNetworkRequest::CacheLoadControl)request.attribute(QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::PreferNetwork).toInt();

    auto requestHeaders = request.headers();
    if (CacheLoadControlAttribute == QNetworkRequest::AlwaysNetwork) {
        // If the request does not already specify preferred cache-control
        // force reload from the network and tell any caching proxy servers to reload too
        if (!requestHeaders.contains(QHttpHeaders::WellKnownHeader::CacheControl)) {
            const auto noCache = "no-cache"_ba;
            httpRequest.setHeaderField(cacheControlName(), noCache);
            httpRequest.setHeaderField("Pragma"_ba, noCache);
        }
        return false;
    }

    // The disk cache API does not currently support partial content retrieval.
    // That is why we don't use the disk cache for any such requests.
    if (requestHeaders.contains(QHttpHeaders::WellKnownHeader::Range))
        return false;

    QAbstractNetworkCache *nc = managerPrivate->networkCache;
    if (!nc)
        return false;                 // no local cache

    QNetworkCacheMetaData metaData = nc->metaData(httpRequest.url());
    if (!metaData.isValid())
        return false;                 // not in cache

    if (!metaData.saveToDisk())
        return false;

    QHttpHeaders cacheHeaders = metaData.headers();

    const auto sizeOpt = QNetworkHeadersPrivate::toInt(
            cacheHeaders.value(QHttpHeaders::WellKnownHeader::ContentLength));
    if (sizeOpt) {
        std::unique_ptr<QIODevice> data(nc->data(httpRequest.url()));
        if (!data || data->size() < sizeOpt.value())
            return false; // The data is smaller than the content-length specified
    }

    auto value = cacheHeaders.value(QHttpHeaders::WellKnownHeader::ETag);
    if (!value.empty())
        httpRequest.setHeaderField("If-None-Match"_ba, value.toByteArray());

    QDateTime lastModified = metaData.lastModified();
    if (lastModified.isValid())
        httpRequest.setHeaderField("If-Modified-Since"_ba, QNetworkHeadersPrivate::toHttpDate(lastModified));

    value = cacheHeaders.value(QHttpHeaders::WellKnownHeader::CacheControl);
    if (!value.empty()) {
        QHash<QByteArray, QByteArray> cacheControl = parseHttpOptionHeader(value);
        if (cacheControl.contains("no-cache"_ba))
            return false;
    }

    QDateTime currentDateTime = QDateTime::currentDateTimeUtc();
    QDateTime expirationDate = metaData.expirationDate();

    bool response_is_fresh;
    if (!expirationDate.isValid()) {
        /*
         * age_value
         *      is the value of Age: header received by the cache with
         *              this response.
         * date_value
         *      is the value of the origin server's Date: header
         * request_time
         *      is the (local) time when the cache made the request
         *              that resulted in this cached response
         * response_time
         *      is the (local) time when the cache received the
         *              response
         * now
         *      is the current (local) time
         */
        const auto ageOpt = QNetworkHeadersPrivate::toInt(
                cacheHeaders.value(QHttpHeaders::WellKnownHeader::Age));
        const qint64 age_value = ageOpt.value_or(0);

        QDateTime dateHeader;
        qint64 date_value = 0;
        value = cacheHeaders.value(QHttpHeaders::WellKnownHeader::Date);
        if (!value.empty()) {
            dateHeader = QNetworkHeadersPrivate::fromHttpDate(value);
            date_value = dateHeader.toSecsSinceEpoch();
        }

        qint64 now = currentDateTime.toSecsSinceEpoch();
        qint64 request_time = now;
        qint64 response_time = now;

        // Algorithm from RFC 2616 section 13.2.3
        qint64 apparent_age = qMax<qint64>(0, response_time - date_value);
        qint64 corrected_received_age = qMax(apparent_age, age_value);
        qint64 response_delay = response_time - request_time;
        qint64 corrected_initial_age = corrected_received_age + response_delay;
        qint64 resident_time = now - response_time;
        qint64 current_age   = corrected_initial_age + resident_time;

        qint64 freshness_lifetime = 0;

        // RFC 2616 13.2.4 Expiration Calculations
        if (lastModified.isValid() && dateHeader.isValid()) {
            qint64 diff = lastModified.secsTo(dateHeader);
            freshness_lifetime = diff / 10;
            const auto warningHeader = "Warning"_ba;
            if (httpRequest.headerField(warningHeader).isEmpty()) {
                QDateTime dt = currentDateTime.addSecs(current_age);
                if (currentDateTime.daysTo(dt) > 1)
                    httpRequest.setHeaderField(warningHeader, "113"_ba);
            }
        }

        // the cache-saving code below sets the freshness_lifetime with (dateHeader - last_modified) / 10
        // if "last-modified" is present, or to Expires otherwise
        response_is_fresh = (freshness_lifetime > current_age);
    } else {
        // expiration date was calculated earlier (e.g. when storing object to the cache)
        response_is_fresh = currentDateTime.secsTo(expirationDate) >= 0;
    }

    if (!response_is_fresh)
        return false;

#if defined(QNETWORKACCESSHTTPBACKEND_DEBUG)
    qDebug() << "response_is_fresh" << CacheLoadControlAttribute;
#endif
    return sendCacheContents(metaData);
}

QHttpNetworkRequest::Priority QNetworkReplyHttpImplPrivate::convert(QNetworkRequest::Priority prio)
{
    switch (prio) {
    case QNetworkRequest::LowPriority:
        return QHttpNetworkRequest::LowPriority;
    case QNetworkRequest::HighPriority:
        return QHttpNetworkRequest::HighPriority;
    case QNetworkRequest::NormalPriority:
        return QHttpNetworkRequest::NormalPriority;
    }
    Q_UNREACHABLE_RETURN(QHttpNetworkRequest::NormalPriority);
}

void QNetworkReplyHttpImplPrivate::postRequest(const QNetworkRequest &newHttpRequest)
{
    Q_Q(QNetworkReplyHttpImpl);

    QThread *thread = nullptr;
    if (synchronous) {
        // A synchronous HTTP request uses its own thread
        thread = new QThread();
        thread->setObjectName(QStringLiteral("Qt HTTP synchronous thread"));
        QObject::connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
        thread->start();
    } else {
        // We use the manager-global thread.
        // At some point we could switch to having multiple threads if it makes sense.
        thread = managerPrivate->createThread();
    }

    QUrl url = newHttpRequest.url();
    httpRequest.setUrl(url);
    httpRequest.setRedirectCount(newHttpRequest.maximumRedirectsAllowed());

    QString scheme = url.scheme();
    bool ssl = (scheme == "https"_L1 || scheme == "preconnect-https"_L1);
    q->setAttribute(QNetworkRequest::ConnectionEncryptedAttribute, ssl);
    httpRequest.setSsl(ssl);

    bool preConnect = (scheme == "preconnect-http"_L1 || scheme == "preconnect-https"_L1);
    httpRequest.setPreConnect(preConnect);

#ifndef QT_NO_NETWORKPROXY
    QNetworkProxy transparentProxy, cacheProxy;

    // FIXME the proxy stuff should be done in the HTTP thread
    const auto proxies = managerPrivate->queryProxy(QNetworkProxyQuery(newHttpRequest.url()));
    for (const QNetworkProxy &p : proxies) {
        // use the first proxy that works
        // for non-encrypted connections, any transparent or HTTP proxy
        // for encrypted, only transparent proxies
        if (!ssl
            && (p.capabilities() & QNetworkProxy::CachingCapability)
            && (p.type() == QNetworkProxy::HttpProxy ||
                p.type() == QNetworkProxy::HttpCachingProxy)) {
            cacheProxy = p;
            transparentProxy = QNetworkProxy::NoProxy;
            break;
        }
        if (p.isTransparentProxy()) {
            transparentProxy = p;
            cacheProxy = QNetworkProxy::NoProxy;
            break;
        }
    }

    // check if at least one of the proxies
    if (transparentProxy.type() == QNetworkProxy::DefaultProxy &&
        cacheProxy.type() == QNetworkProxy::DefaultProxy) {
        // unsuitable proxies
        QMetaObject::invokeMethod(q, "_q_error", synchronous ? Qt::DirectConnection : Qt::QueuedConnection,
                                  Q_ARG(QNetworkReply::NetworkError, QNetworkReply::ProxyNotFoundError),
                                  Q_ARG(QString, QNetworkReplyHttpImpl::tr("No suitable proxy found")));
        QMetaObject::invokeMethod(q, "_q_finished", synchronous ? Qt::DirectConnection : Qt::QueuedConnection);
        return;
    }
#endif

    auto redirectPolicy = QNetworkRequest::NoLessSafeRedirectPolicy;
    const QVariant value = newHttpRequest.attribute(QNetworkRequest::RedirectPolicyAttribute);
    if (value.isValid())
        redirectPolicy = qvariant_cast<QNetworkRequest::RedirectPolicy>(value);

    httpRequest.setRedirectPolicy(redirectPolicy);

    httpRequest.setPriority(convert(newHttpRequest.priority()));
    loadingFromCache = false;

    switch (operation) {
    case QNetworkAccessManager::GetOperation:
        httpRequest.setOperation(QHttpNetworkRequest::Get);
        // If the request has a body, createUploadByteDevice() and don't use caching
        if (outgoingData) {
            invalidateCache();
            createUploadByteDevice();
        } else if (loadFromCacheIfAllowed(httpRequest)) {
            return; // no need to send the request! :)
        }
        break;

    case QNetworkAccessManager::HeadOperation:
        httpRequest.setOperation(QHttpNetworkRequest::Head);
        if (loadFromCacheIfAllowed(httpRequest))
            return; // no need to send the request! :)
        break;

    case QNetworkAccessManager::PostOperation:
        invalidateCache();
        httpRequest.setOperation(QHttpNetworkRequest::Post);
        createUploadByteDevice();
        break;

    case QNetworkAccessManager::PutOperation:
        invalidateCache();
        httpRequest.setOperation(QHttpNetworkRequest::Put);
        createUploadByteDevice();
        break;

    case QNetworkAccessManager::DeleteOperation:
        invalidateCache();
        httpRequest.setOperation(QHttpNetworkRequest::Delete);
        break;

    case QNetworkAccessManager::CustomOperation:
        invalidateCache(); // for safety reasons, we don't know what the operation does
        httpRequest.setOperation(QHttpNetworkRequest::Custom);
        createUploadByteDevice();
        httpRequest.setCustomVerb(newHttpRequest.attribute(
                QNetworkRequest::CustomVerbAttribute).toByteArray());
        break;

    default:
        break;                  // can't happen
    }

    QHttpHeaders newRequestHeaders = newHttpRequest.headers();
    if (resumeOffset != 0) {
        if (newRequestHeaders.contains(QHttpHeaders::WellKnownHeader::Range)) {
            // Need to adjust resume offset for user specified range

            // We've already verified that requestRange starts with "bytes=", see canResume.
            const auto rangeHeader = newRequestHeaders.value(QHttpHeaders::WellKnownHeader::Range);
            const auto requestRange = QByteArrayView(rangeHeader).mid(bytesEqualPrefix().size());

            newRequestHeaders.removeAll(QHttpHeaders::WellKnownHeader::Range);

            int index = requestRange.indexOf('-');

            quint64 requestStartOffset = requestRange.left(index).toULongLong();
            quint64 requestEndOffset = requestRange.mid(index + 1).toULongLong();

            // In case an end offset is not given it is skipped from the request range
            QByteArray newRange = bytesEqualPrefix() + QByteArray::number(resumeOffset + requestStartOffset) +
                           '-' + (requestEndOffset ? QByteArray::number(requestEndOffset) : QByteArray());

            httpRequest.setHeaderField(rangeName(), newRange);
        } else {
            httpRequest.setHeaderField(rangeName(), bytesEqualPrefix() + QByteArray::number(resumeOffset) + '-');
        }
    }

    for (int i = 0; i < newRequestHeaders.size(); i++) {
        const auto name = newRequestHeaders.nameAt(i);
        const auto value = newRequestHeaders.valueAt(i);
        httpRequest.setHeaderField(QByteArray(name.data(), name.size()), value.toByteArray());
    }

    if (newHttpRequest.attribute(QNetworkRequest::HttpPipeliningAllowedAttribute).toBool())
        httpRequest.setPipeliningAllowed(true);

    if (auto allowed = request.attribute(QNetworkRequest::Http2AllowedAttribute);
        allowed.isValid() && allowed.canConvert<bool>()) {
        httpRequest.setHTTP2Allowed(allowed.value<bool>());
    }
    auto h2cAttribute = request.attribute(QNetworkRequest::Http2CleartextAllowedAttribute);
    // ### Qt7: Stop checking the environment variable
    if (h2cAttribute.toBool()
        || (!h2cAttribute.isValid() && qEnvironmentVariableIsSet("QT_NETWORK_H2C_ALLOWED"))) {
        httpRequest.setH2cAllowed(true);
    }

    if (request.attribute(QNetworkRequest::Http2DirectAttribute).toBool()) {
        // Intentionally mutually exclusive - cannot be both direct and 'allowed'
        httpRequest.setHTTP2Direct(true);
        httpRequest.setHTTP2Allowed(false);
    }

    if (static_cast<QNetworkRequest::LoadControl>
        (newHttpRequest.attribute(QNetworkRequest::AuthenticationReuseAttribute,
                             QNetworkRequest::Automatic).toInt()) == QNetworkRequest::Manual)
        httpRequest.setWithCredentials(false);

    if (request.attribute(QNetworkRequest::EmitAllUploadProgressSignalsAttribute).toBool())
        emitAllUploadProgressSignals = true;

    httpRequest.setPeerVerifyName(newHttpRequest.peerVerifyName());

    if (scheme.startsWith(("unix"_L1))) {
        if (QVariant path = newHttpRequest.attribute(QNetworkRequest::FullLocalServerNameAttribute);
            path.isValid() && path.canConvert<QString>()) {
            httpRequest.setFullLocalServerName(path.toString());
        }
    }

    // Create the HTTP thread delegate
    QHttpThreadDelegate *delegate = new QHttpThreadDelegate;
    // Propagate Http/2 settings:
    delegate->http2Parameters = request.http2Configuration();
    delegate->http1Parameters = request.http1Configuration();

    if (request.attribute(QNetworkRequest::ConnectionCacheExpiryTimeoutSecondsAttribute).isValid())
        delegate->connectionCacheExpiryTimeoutSeconds = request.attribute(QNetworkRequest::ConnectionCacheExpiryTimeoutSecondsAttribute).toInt();

    // For the synchronous HTTP, this is the normal way the delegate gets deleted
    // For the asynchronous HTTP this is a safety measure, the delegate deletes itself when HTTP is finished
    QMetaObject::Connection threadFinishedConnection =
            QObject::connect(thread, SIGNAL(finished()), delegate, SLOT(deleteLater()));

    // QTBUG-88063: When 'delegate' is deleted the connection will be added to 'thread''s orphaned
    // connections list. This orphaned list will be cleaned up next time 'thread' emits a signal,
    // unfortunately that's the finished signal. It leads to a soft-leak so we do this to disconnect
    // it on deletion so that it cleans up the orphan immediately.
    QObject::connect(delegate, &QObject::destroyed, delegate, [threadFinishedConnection]() {
        if (bool(threadFinishedConnection))
            QObject::disconnect(threadFinishedConnection);
    });

    // Set the properties it needs
    delegate->httpRequest = httpRequest;
#ifndef QT_NO_NETWORKPROXY
    delegate->cacheProxy = cacheProxy;
    delegate->transparentProxy = transparentProxy;
#endif
    delegate->ssl = ssl;
#ifndef QT_NO_SSL
    if (ssl)
        delegate->incomingSslConfiguration.reset(new QSslConfiguration(newHttpRequest.sslConfiguration()));
#endif

    // Do we use synchronous HTTP?
    delegate->synchronous = synchronous;

    // The authentication manager is used to avoid the BlockingQueuedConnection communication
    // from HTTP thread to user thread in some cases.
    delegate->authenticationManager = managerPrivate->authenticationManager;

    if (!synchronous) {
        // Tell our zerocopy policy to the delegate
        QVariant downloadBufferMaximumSizeAttribute = newHttpRequest.attribute(QNetworkRequest::MaximumDownloadBufferSizeAttribute);
        if (downloadBufferMaximumSizeAttribute.isValid()) {
            delegate->downloadBufferMaximumSize = downloadBufferMaximumSizeAttribute.toLongLong();
        } else {
            // If there is no MaximumDownloadBufferSizeAttribute set (which is for the majority
            // of QNetworkRequest) then we can assume we'll do it anyway for small HTTP replies.
            // This helps with performance and memory fragmentation.
            delegate->downloadBufferMaximumSize = 128*1024;
        }


        // These atomic integers are used for signal compression
        delegate->pendingDownloadData = pendingDownloadDataEmissions;
        delegate->pendingDownloadProgress = pendingDownloadProgressEmissions;

        // Connect the signals of the delegate to us
        QObject::connect(delegate, SIGNAL(downloadData(QByteArray)),
                q, SLOT(replyDownloadData(QByteArray)),
                Qt::QueuedConnection);
        QObject::connect(delegate, SIGNAL(downloadFinished()),
                q, SLOT(replyFinished()),
                Qt::QueuedConnection);
        QObject::connect(delegate, &QHttpThreadDelegate::socketStartedConnecting,
                q, &QNetworkReply::socketStartedConnecting, Qt::QueuedConnection);
        QObject::connect(delegate, &QHttpThreadDelegate::requestSent,
                q, &QNetworkReply::requestSent, Qt::QueuedConnection);
        connect(delegate, &QHttpThreadDelegate::downloadMetaData, this,
                &QNetworkReplyHttpImplPrivate::replyDownloadMetaData, Qt::QueuedConnection);
        QObject::connect(delegate, SIGNAL(downloadProgress(qint64,qint64)),
                q, SLOT(replyDownloadProgressSlot(qint64,qint64)),
                Qt::QueuedConnection);
        QObject::connect(delegate, SIGNAL(error(QNetworkReply::NetworkError,QString)),
                q, SLOT(httpError(QNetworkReply::NetworkError,QString)),
                Qt::QueuedConnection);
        QObject::connect(delegate, SIGNAL(redirected(QUrl,int,int)),
                q, SLOT(onRedirected(QUrl,int,int)),
                Qt::QueuedConnection);

#ifndef QT_NO_SSL
        QObject::connect(delegate, SIGNAL(sslConfigurationChanged(QSslConfiguration)),
                q, SLOT(replySslConfigurationChanged(QSslConfiguration)),
                Qt::QueuedConnection);
#endif
        // Those need to report back, therefore BlockingQueuedConnection
        QObject::connect(delegate, SIGNAL(authenticationRequired(QHttpNetworkRequest,QAuthenticator*)),
                q, SLOT(httpAuthenticationRequired(QHttpNetworkRequest,QAuthenticator*)),
                Qt::BlockingQueuedConnection);
#ifndef QT_NO_NETWORKPROXY
        QObject::connect(delegate, SIGNAL(proxyAuthenticationRequired(QNetworkProxy,QAuthenticator*)),
                 q, SLOT(proxyAuthenticationRequired(QNetworkProxy,QAuthenticator*)),
                 Qt::BlockingQueuedConnection);
#endif
#ifndef QT_NO_SSL
        QObject::connect(delegate, SIGNAL(encrypted()), q, SLOT(replyEncrypted()),
                Qt::BlockingQueuedConnection);
        QObject::connect(delegate, SIGNAL(sslErrors(QList<QSslError>,bool*,QList<QSslError>*)),
                q, SLOT(replySslErrors(QList<QSslError>,bool*,QList<QSslError>*)),
                Qt::BlockingQueuedConnection);
        QObject::connect(delegate, SIGNAL(preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator*)),
                         q, SLOT(replyPreSharedKeyAuthenticationRequiredSlot(QSslPreSharedKeyAuthenticator*)),
                         Qt::BlockingQueuedConnection);
#endif
        // This signal we will use to start the request.
        QObject::connect(q, SIGNAL(startHttpRequest()), delegate, SLOT(startRequest()));
        QObject::connect(q, SIGNAL(abortHttpRequest()), delegate, SLOT(abortRequest()));

        // To throttle the connection.
        QObject::connect(q, SIGNAL(readBufferSizeChanged(qint64)), delegate, SLOT(readBufferSizeChanged(qint64)));
        QObject::connect(q, SIGNAL(readBufferFreed(qint64)), delegate, SLOT(readBufferFreed(qint64)));

        if (uploadByteDevice) {
            QNonContiguousByteDeviceThreadForwardImpl *forwardUploadDevice =
                    new QNonContiguousByteDeviceThreadForwardImpl(uploadByteDevice->atEnd(), uploadByteDevice->size());
            forwardUploadDevice->setParent(delegate); // needed to make sure it is moved on moveToThread()
            delegate->httpRequest.setUploadByteDevice(forwardUploadDevice);

            // If the device in the user thread claims it has more data, keep the flow to HTTP thread going
            QObject::connect(uploadByteDevice.get(), SIGNAL(readyRead()),
                             q, SLOT(uploadByteDeviceReadyReadSlot()),
                             Qt::QueuedConnection);

            // From user thread to http thread:
            QObject::connect(q, SIGNAL(haveUploadData(qint64,QByteArray,bool,qint64)),
                             forwardUploadDevice, SLOT(haveDataSlot(qint64,QByteArray,bool,qint64)), Qt::QueuedConnection);
            QObject::connect(uploadByteDevice.get(), SIGNAL(readyRead()),
                             forwardUploadDevice, SIGNAL(readyRead()),
                             Qt::QueuedConnection);

            // From http thread to user thread:
            QObject::connect(forwardUploadDevice, SIGNAL(wantData(qint64)),
                             q, SLOT(wantUploadDataSlot(qint64)));
            QObject::connect(forwardUploadDevice,SIGNAL(processedData(qint64,qint64)),
                             q, SLOT(sentUploadDataSlot(qint64,qint64)));
            QObject::connect(forwardUploadDevice, SIGNAL(resetData(bool*)),
                    q, SLOT(resetUploadDataSlot(bool*)),
                    Qt::BlockingQueuedConnection); // this is the only one with BlockingQueued!
        }
    } else if (synchronous) {
        QObject::connect(q, SIGNAL(startHttpRequestSynchronously()), delegate, SLOT(startRequestSynchronously()), Qt::BlockingQueuedConnection);

        if (uploadByteDevice) {
            // For the synchronous HTTP use case the use thread (this one here) is blocked
            // so we cannot use the asynchronous upload architecture.
            // We therefore won't use the QNonContiguousByteDeviceThreadForwardImpl but directly
            // use the uploadByteDevice provided to us by the QNetworkReplyImpl.
            // The code that is in start() makes sure it is safe to use from a thread
            // since it only wraps a QRingBuffer
            delegate->httpRequest.setUploadByteDevice(uploadByteDevice.get());
        }
    }


    // Move the delegate to the http thread
    delegate->moveToThread(thread);
    // This call automatically moves the uploadDevice too for the asynchronous case.

    // Prepare timers for progress notifications
    downloadProgressSignalChoke.start();
    uploadProgressSignalChoke.invalidate();

    // Send an signal to the delegate so it starts working in the other thread
    if (synchronous) {
        emit q->startHttpRequestSynchronously(); // This one is BlockingQueuedConnection, so it will return when all work is done

        replyDownloadMetaData
                (delegate->incomingHeaders,
                    delegate->incomingStatusCode,
                    delegate->incomingReasonPhrase,
                    delegate->isPipeliningUsed,
                    QSharedPointer<char>(),
                    delegate->incomingContentLength,
                    delegate->removedContentLength,
                    delegate->isHttp2Used,
                    delegate->isCompressed);
        replyDownloadData(delegate->synchronousDownloadData);

        if (delegate->incomingErrorCode != QNetworkReply::NoError)
            httpError(delegate->incomingErrorCode, delegate->incomingErrorDetail);

        thread->quit();
        thread->wait(QDeadlineTimer(5000));
        if (thread->isFinished())
            delete thread;
        else
            QObject::connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

        finished();
    } else {
        emit q->startHttpRequest(); // Signal to the HTTP thread and go back to user.
    }
}

void QNetworkReplyHttpImplPrivate::invalidateCache()
{
    QAbstractNetworkCache *nc = managerPrivate->networkCache;
    if (nc)
        nc->remove(httpRequest.url());
}

void QNetworkReplyHttpImplPrivate::initCacheSaveDevice()
{
    Q_Q(QNetworkReplyHttpImpl);

    // The disk cache does not support partial content, so don't even try to
    // save any such content into the cache.
    if (q->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt() == 206) {
        cacheEnabled = false;
        return;
    }

    // save the meta data
    QNetworkCacheMetaData metaData;
    metaData.setUrl(url);
    metaData = fetchCacheMetaData(metaData);

    // save the redirect request also in the cache
    QVariant redirectionTarget = q->attribute(QNetworkRequest::RedirectionTargetAttribute);
    if (redirectionTarget.isValid()) {
        QNetworkCacheMetaData::AttributesMap attributes = metaData.attributes();
        attributes.insert(QNetworkRequest::RedirectionTargetAttribute, redirectionTarget);
        metaData.setAttributes(attributes);
    }

    cacheSaveDevice = managerPrivate->networkCache->prepare(metaData);

    if (cacheSaveDevice)
        q->connect(cacheSaveDevice, SIGNAL(aboutToClose()), SLOT(_q_cacheSaveDeviceAboutToClose()));

    if (!cacheSaveDevice || !cacheSaveDevice->isOpen()) {
        if (Q_UNLIKELY(cacheSaveDevice && !cacheSaveDevice->isOpen()))
            qCritical("QNetworkReplyImpl: network cache returned a device that is not open -- "
                  "class %s probably needs to be fixed",
                  managerPrivate->networkCache->metaObject()->className());

        managerPrivate->networkCache->remove(url);
        cacheSaveDevice = nullptr;
        cacheEnabled = false;
    }
}

void QNetworkReplyHttpImplPrivate::replyDownloadData(QByteArray d)
{
    Q_Q(QNetworkReplyHttpImpl);

    // If we're closed just ignore this data
    if (!q->isOpen())
        return;

    // cache this, we need it later and it's invalidated when dealing with compressed data
    auto dataSize = d.size();

    if (cacheEnabled && isCachingAllowed() && !cacheSaveDevice)
        initCacheSaveDevice();

    if (decompressHelper.isValid()) {
        qint64 uncompressedBefore = -1;
        if (decompressHelper.isCountingBytes())
            uncompressedBefore = decompressHelper.uncompressedSize();

        decompressHelper.feed(std::move(d));

        if (!decompressHelper.isValid()) {
            error(QNetworkReplyImpl::NetworkError::UnknownContentError,
                  QCoreApplication::translate("QHttp", "Decompression failed: %1")
                          .arg(decompressHelper.errorString()));
            decompressHelper.clear();
            return;
        }

        if (!isHttpRedirectResponse()) {
            if (decompressHelper.isCountingBytes())
                bytesDownloaded += (decompressHelper.uncompressedSize() - uncompressedBefore);
            setupTransferTimeout();
        }

        if (synchronous) {
            d = QByteArray();
            const qsizetype increments = 16 * 1024;
            qint64 bytesRead = 0;
            while (decompressHelper.hasData()) {
                quint64 nextSize = quint64(d.size()) + quint64(increments);
                if (nextSize > quint64(std::numeric_limits<QByteArray::size_type>::max())) {
                    error(QNetworkReplyImpl::NetworkError::UnknownContentError,
                          QCoreApplication::translate("QHttp",
                                                      "Data downloaded is too large to store"));
                    decompressHelper.clear();
                    return;
                }
                d.resize(nextSize);
                bytesRead += decompressHelper.read(d.data() + bytesRead, increments);
                if (!decompressHelper.isValid()) {
                    error(QNetworkReplyImpl::NetworkError::UnknownContentError,
                          QCoreApplication::translate("QHttp", "Decompression failed: %1")
                                  .arg(decompressHelper.errorString()));
                    decompressHelper.clear();
                    return;
                }
            }
            d.resize(bytesRead);
            // we're synchronous so we're not calling this function again; reset the decompressHelper
            decompressHelper.clear();
        }
    }

    // This is going to look a little strange. When downloading data while a
    // HTTP redirect is happening (and enabled), we write the redirect
    // response to the cache. However, we do not append it to our internal
    // buffer as that will contain the response data only for the final
    // response
    // Note: For compressed data this is done in readData()
    if (cacheSaveDevice && !decompressHelper.isValid()) {
        cacheSaveDevice->write(d);
    }

    // if decompressHelper is valid then we have compressed data, and this is handled above
    if (!decompressHelper.isValid() && !isHttpRedirectResponse()) {
        buffer.append(d);
        bytesDownloaded += dataSize;
        setupTransferTimeout();
    }
    bytesBuffered += dataSize;

    int pendingSignals = pendingDownloadDataEmissions->fetchAndSubAcquire(1) - 1;
    if (pendingSignals > 0) {
        // Some more signal emissions to this slot are pending.
        // Instead of writing the downstream data, we wait
        // and do it in the next call we get
        // (signal comppression)
        return;
    }

    if (isHttpRedirectResponse())
        return;

    // This can occur when downloading compressed data as some of the data may be the content
    // encoding's header. Don't emit anything for this.
    if (lastReadyReadEmittedSize == bytesDownloaded) {
        if (readBufferMaxSize)
            emit q->readBufferFreed(dataSize);
        return;
    }
    lastReadyReadEmittedSize = bytesDownloaded;

    const auto totalSizeOpt = QNetworkHeadersPrivate::toInt(
            headers().value(QHttpHeaders::WellKnownHeader::ContentLength));

    emit q->readyRead();
    // emit readyRead before downloadProgress in case this will cause events to be
    // processed and we get into a recursive call (as in QProgressDialog).
    if (downloadProgressSignalChoke.isValid() &&
        downloadProgressSignalChoke.elapsed() >= progressSignalInterval
        && (!decompressHelper.isValid() || decompressHelper.isCountingBytes())) {
        downloadProgressSignalChoke.start();
        emit q->downloadProgress(bytesDownloaded, totalSizeOpt.value_or(-1));
    }
}

void QNetworkReplyHttpImplPrivate::replyFinished()
{
    // We are already loading from cache, we still however
    // got this signal because it was posted already
    if (loadingFromCache)
        return;

    finished();
}

QNetworkAccessManager::Operation QNetworkReplyHttpImplPrivate::getRedirectOperation(QNetworkAccessManager::Operation currentOp, int httpStatus)
{
    // HTTP status code can be used to decide if we can redirect with a GET
    // operation or not. See http://www.ietf.org/rfc/rfc2616.txt [Sec 10.3] for
    // more details

    // We MUST keep using the verb that was used originally when being redirected with 307 or 308.
    if (httpStatus == 307 || httpStatus == 308)
        return currentOp;

    switch (currentOp) {
    case QNetworkAccessManager::HeadOperation:
        return QNetworkAccessManager::HeadOperation;
    default:
        break;
    }
    // Use GET for everything else.
    return QNetworkAccessManager::GetOperation;
}

bool QNetworkReplyHttpImplPrivate::isHttpRedirectResponse() const
{
    return httpRequest.isFollowRedirects() && QHttpNetworkReply::isHttpRedirect(statusCode);
}

QNetworkRequest QNetworkReplyHttpImplPrivate::createRedirectRequest(const QNetworkRequest &originalRequest,
                                                                    const QUrl &url,
                                                                    int maxRedirectsRemaining)
{
    QNetworkRequest newRequest(originalRequest);
    newRequest.setUrl(url);
    newRequest.setMaximumRedirectsAllowed(maxRedirectsRemaining);

    return newRequest;
}

void QNetworkReplyHttpImplPrivate::onRedirected(const QUrl &redirectUrl, int httpStatus, int maxRedirectsRemaining)
{
    Q_Q(QNetworkReplyHttpImpl);
    Q_ASSERT(manager);
    Q_ASSERT(managerPrivate);

    if (isFinished)
        return;

    const QString schemeBefore(url.scheme());
    if (httpRequest.isFollowRedirects()) // update the reply's url as it could've changed
        url = redirectUrl;

    const bool wasLocalSocket = schemeBefore.startsWith("unix"_L1);
    if (!wasLocalSocket && managerPrivate->stsEnabled && managerPrivate->stsCache.isKnownHost(url)) {
        // RFC6797, 8.3:
        // The UA MUST replace the URI scheme with "https" [RFC2818],
        // and if the URI contains an explicit port component of "80",
        // then the UA MUST convert the port component to be "443", or
        // if the URI contains an explicit port component that is not
        // equal to "80", the port component value MUST be preserved;
        // otherwise, if the URI does not contain an explicit port
        // component, the UA MUST NOT add one.
        url.setScheme("https"_L1);
        if (url.port() == 80)
            url.setPort(443);
    }

    // Just to be on the safe side for local sockets, any changes to the scheme
    // are considered less safe
    const bool changingLocalScheme = wasLocalSocket && url.scheme() != schemeBefore;
    const bool isLessSafe = changingLocalScheme
            || (schemeBefore == "https"_L1 && url.scheme() == "http"_L1);
    if (httpRequest.redirectPolicy() == QNetworkRequest::NoLessSafeRedirectPolicy && isLessSafe) {
        error(QNetworkReply::InsecureRedirectError,
              QCoreApplication::translate("QHttp", "Insecure redirect"));
        return;
    }

    // If the original operation was a GET with a body and the status code is
    // 308 then keep the message body
    const bool getOperationKeepsBody = (operation == QNetworkAccessManager::GetOperation)
                                    && httpStatus == 308;

    redirectRequest = createRedirectRequest(originalRequest, url, maxRedirectsRemaining);
    operation = getRedirectOperation(operation, httpStatus);

    // Clear stale headers, the relevant ones get set again later
    httpRequest.clearHeaders();
    auto newHeaders = redirectRequest.headers();
    if ((operation == QNetworkAccessManager::GetOperation
        || operation == QNetworkAccessManager::HeadOperation) && !getOperationKeepsBody) {
        // possibly changed from not-GET/HEAD to GET/HEAD, make sure to get rid of upload device
        uploadByteDevice.reset();
        uploadByteDevicePosition = 0;
        if (outgoingData) {
            QObject::disconnect(outgoingData, SIGNAL(readyRead()), q,
                                SLOT(_q_bufferOutgoingData()));
            QObject::disconnect(outgoingData, SIGNAL(readChannelFinished()), q,
                                SLOT(_q_bufferOutgoingDataFinished()));
        }
        outgoingData = nullptr;
        outgoingDataBuffer.reset();
        // We need to explicitly unset these headers so they're not reapplied to the httpRequest
        newHeaders.removeAll(QHttpHeaders::WellKnownHeader::ContentLength);
        newHeaders.removeAll(QHttpHeaders::WellKnownHeader::ContentType);
    }

    if (const QNetworkCookieJar *const cookieJar = manager->cookieJar()) {
        auto cookies = cookieJar->cookiesForUrl(url);
        if (!cookies.empty()) {
            auto cookieHeader = QNetworkHeadersPrivate::fromCookieList(cookies);
            newHeaders.replaceOrAppend(QHttpHeaders::WellKnownHeader::Cookie, cookieHeader);
        }
    }

    redirectRequest.setHeaders(std::move(newHeaders));

    if (httpRequest.redirectPolicy() != QNetworkRequest::UserVerifiedRedirectPolicy)
        followRedirect();

    emit q->redirected(url);
}

void QNetworkReplyHttpImplPrivate::followRedirect()
{
    Q_Q(QNetworkReplyHttpImpl);
    Q_ASSERT(managerPrivate);

    decompressHelper.clear();
    clearHeaders();

    if (managerPrivate->thread)
        managerPrivate->thread->disconnect();

    QMetaObject::invokeMethod(
            q, [this]() { postRequest(redirectRequest); }, Qt::QueuedConnection);
}

static constexpr QLatin1StringView locationHeader() noexcept { return "location"_L1; }

void QNetworkReplyHttpImplPrivate::checkForRedirect(const int statusCode)
{
    Q_Q(QNetworkReplyHttpImpl);
    switch (statusCode) {
    case 301:                   // Moved Permanently
    case 302:                   // Found
    case 303:                   // See Other
    case 307:                   // Temporary Redirect
    case 308:                   // Permanent Redirect
        // What do we do about the caching of the HTML note?
        // The response to a 303 MUST NOT be cached, while the response to
        // all of the others is cacheable if the headers indicate it to be
        QByteArrayView header = q->headers().value(locationHeader());
        QUrl url = QUrl(QString::fromUtf8(header));
        if (!url.isValid())
            url = QUrl(QLatin1StringView(header));
        q->setAttribute(QNetworkRequest::RedirectionTargetAttribute, url);
    }
}

void QNetworkReplyHttpImplPrivate::replyDownloadMetaData(const QHttpHeaders &hm,
                                                         int sc, const QString &rp, bool pu,
                                                         QSharedPointer<char> db,
                                                         qint64 contentLength,
                                                         qint64 removedContentLength,
                                                         bool h2Used, bool isCompressed)
{
    Q_Q(QNetworkReplyHttpImpl);
    Q_UNUSED(contentLength);

    statusCode = sc;
    reasonPhrase = rp;

#ifndef QT_NO_SSL
    // We parse this header only if we're using secure transport:
    //
    // RFC6797, 8.1
    // If an HTTP response is received over insecure transport, the UA MUST
    // ignore any present STS header field(s).
    if (url.scheme() == "https"_L1 && managerPrivate->stsEnabled)
        managerPrivate->stsCache.updateFromHeaders(hm, url);
#endif
    // Download buffer
    if (!db.isNull()) {
        downloadBufferPointer = db;
        downloadZerocopyBuffer = downloadBufferPointer.data();
        downloadBufferCurrentSize = 0;
        q->setAttribute(QNetworkRequest::DownloadBufferAttribute, QVariant::fromValue<QSharedPointer<char> > (downloadBufferPointer));
    }

    q->setAttribute(QNetworkRequest::HttpPipeliningWasUsedAttribute, pu);
    q->setAttribute(QNetworkRequest::Http2WasUsedAttribute, h2Used);

    // A user having manually defined which encodings they accept is, for
    // somwehat unknown (presumed legacy compatibility) reasons treated as
    // disabling our decompression:
    const bool autoDecompress = !request.headers().contains(QHttpHeaders::WellKnownHeader::AcceptEncoding);
    const bool shouldDecompress = isCompressed && autoDecompress;
    // reconstruct the HTTP header
    auto h = q->headers();
    for (qsizetype i = 0; i < hm.size(); ++i) {
        const auto key = hm.nameAt(i);
        const auto originValue = hm.valueAt(i);

        // Reset any previous "location" header set in the reply. In case of
        // redirects, we don't want to 'append' multiple location header values,
        // rather we keep only the latest one
        if (key.compare(locationHeader(), Qt::CaseInsensitive) == 0)
            h.removeAll(key);

        if (shouldDecompress && !decompressHelper.isValid() && key == "content-encoding"_L1) {
            if (!synchronous) // with synchronous all the data is expected to be handled at once
                decompressHelper.setCountingBytesEnabled(true);

            if (!decompressHelper.setEncoding(originValue)) {
                error(QNetworkReplyImpl::NetworkError::UnknownContentError,
                      QCoreApplication::translate("QHttp", "Failed to initialize decompression: %1")
                              .arg(decompressHelper.errorString()));
                return;
            }
            decompressHelper.setDecompressedSafetyCheckThreshold(
                    request.decompressedSafetyCheckThreshold());
        }

        h.append(key, originValue);
    }
    q->setHeaders(std::move(h));

    q->setAttribute(QNetworkRequest::HttpStatusCodeAttribute, statusCode);
    q->setAttribute(QNetworkRequest::HttpReasonPhraseAttribute, reasonPhrase);
    if (removedContentLength != -1)
        q->setAttribute(QNetworkRequest::OriginalContentLengthAttribute, removedContentLength);

    // is it a redirection?
    if (!isHttpRedirectResponse())
        checkForRedirect(statusCode);

    if (statusCode >= 500 && statusCode < 600) {
        QAbstractNetworkCache *nc = managerPrivate->networkCache;
        if (nc) {
            QNetworkCacheMetaData metaData = nc->metaData(httpRequest.url());
            auto value = metaData.headers().value(QHttpHeaders::WellKnownHeader::CacheControl);
            bool mustReValidate = false;
            if (!value.empty()) {
                QHash<QByteArray, QByteArray> cacheControl = parseHttpOptionHeader(value);
                if (cacheControl.contains("must-revalidate"_ba))
                    mustReValidate = true;
            }
            if (!mustReValidate && sendCacheContents(metaData))
                return;
        }
    }

    if (statusCode == 304) {
#if defined(QNETWORKACCESSHTTPBACKEND_DEBUG)
        qDebug() << "Received a 304 from" << request.url();
#endif
        QAbstractNetworkCache *nc = managerPrivate->networkCache;
        if (nc) {
            QNetworkCacheMetaData oldMetaData = nc->metaData(httpRequest.url());
            QNetworkCacheMetaData metaData = fetchCacheMetaData(oldMetaData);
            if (oldMetaData != metaData)
                nc->updateMetaData(metaData);
            if (sendCacheContents(metaData))
                return;
        }
    }


    if (statusCode != 304 && statusCode != 303) {
        if (!isCachingEnabled())
            setCachingEnabled(true);
    }

    _q_metaDataChanged();
}

void QNetworkReplyHttpImplPrivate::replyDownloadProgressSlot(qint64 bytesReceived,  qint64 bytesTotal)
{
    Q_Q(QNetworkReplyHttpImpl);

    // If we're closed just ignore this data
    if (!q->isOpen())
        return;

    // we can be sure here that there is a download buffer

    int pendingSignals = (int)pendingDownloadProgressEmissions->fetchAndAddAcquire(-1) - 1;
    if (pendingSignals > 0) {
        // Let's ignore this signal and look at the next one coming in
        // (signal comppression)
        return;
    }

    if (!q->isOpen())
        return;

    if (cacheEnabled && isCachingAllowed() && bytesReceived == bytesTotal) {
        // Write everything in one go if we use a download buffer. might be more performant.
        initCacheSaveDevice();
        // need to check again if cache enabled and device exists
        if (cacheSaveDevice && cacheEnabled)
            cacheSaveDevice->write(downloadZerocopyBuffer, bytesTotal);
        // FIXME where is it closed?
    }

    if (isHttpRedirectResponse())
        return;

    bytesDownloaded = bytesReceived;
    setupTransferTimeout();

    downloadBufferCurrentSize = bytesReceived;

    // Only emit readyRead when actual data is there
    // emit readyRead before downloadProgress in case this will cause events to be
    // processed and we get into a recursive call (as in QProgressDialog).
    if (bytesDownloaded > 0)
        emit q->readyRead();
    if (downloadProgressSignalChoke.isValid() &&
        downloadProgressSignalChoke.elapsed() >= progressSignalInterval) {
        downloadProgressSignalChoke.start();
        emit q->downloadProgress(bytesDownloaded, bytesTotal);
    }
}

void QNetworkReplyHttpImplPrivate::httpAuthenticationRequired(const QHttpNetworkRequest &request,
                                                           QAuthenticator *auth)
{
    managerPrivate->authenticationRequired(auth, q_func(), synchronous, url, &urlForLastAuthentication, request.withCredentials());
}

#ifndef QT_NO_NETWORKPROXY
void QNetworkReplyHttpImplPrivate::proxyAuthenticationRequired(const QNetworkProxy &proxy,
                                                        QAuthenticator *authenticator)
{
    managerPrivate->proxyAuthenticationRequired(request.url(), proxy, synchronous, authenticator, &lastProxyAuthentication);
}
#endif

void QNetworkReplyHttpImplPrivate::httpError(QNetworkReply::NetworkError errorCode,
                                          const QString &errorString)
{
#if defined(QNETWORKACCESSHTTPBACKEND_DEBUG)
    qDebug() << "http error!" << errorCode << errorString;
#endif

    // FIXME?
    error(errorCode, errorString);
}

#ifndef QT_NO_SSL
void QNetworkReplyHttpImplPrivate::replyEncrypted()
{
    Q_Q(QNetworkReplyHttpImpl);
    emit q->encrypted();
}

void QNetworkReplyHttpImplPrivate::replySslErrors(
        const QList<QSslError> &list, bool *ignoreAll, QList<QSslError> *toBeIgnored)
{
    Q_Q(QNetworkReplyHttpImpl);
    emit q->sslErrors(list);
    // Check if the callback set any ignore and return this here to http thread
    if (pendingIgnoreAllSslErrors)
        *ignoreAll = true;
    if (!pendingIgnoreSslErrorsList.isEmpty())
        *toBeIgnored = pendingIgnoreSslErrorsList;
}

void QNetworkReplyHttpImplPrivate::replySslConfigurationChanged(const QSslConfiguration &newSslConfiguration)
{
    // Receiving the used SSL configuration from the HTTP thread
    if (sslConfiguration.data())
        *sslConfiguration = newSslConfiguration;
    else
        sslConfiguration.reset(new QSslConfiguration(newSslConfiguration));
}

void QNetworkReplyHttpImplPrivate::replyPreSharedKeyAuthenticationRequiredSlot(QSslPreSharedKeyAuthenticator *authenticator)
{
    Q_Q(QNetworkReplyHttpImpl);
    emit q->preSharedKeyAuthenticationRequired(authenticator);
}
#endif

// Coming from QNonContiguousByteDeviceThreadForwardImpl in HTTP thread
void QNetworkReplyHttpImplPrivate::resetUploadDataSlot(bool *r)
{
    *r = uploadByteDevice->reset();
    if (*r) {
        // reset our own position which is used for the inter-thread communication
        uploadByteDevicePosition = 0;
    }
}

// Coming from QNonContiguousByteDeviceThreadForwardImpl in HTTP thread
void QNetworkReplyHttpImplPrivate::sentUploadDataSlot(qint64 pos, qint64 amount)
{
    if (!uploadByteDevice) // uploadByteDevice is no longer available
        return;

    if (uploadByteDevicePosition + amount != pos) {
        // Sanity check, should not happen.
        error(QNetworkReply::UnknownNetworkError, QString());
        return;
    }
    uploadByteDevice->advanceReadPointer(amount);
    uploadByteDevicePosition += amount;
}

// Coming from QNonContiguousByteDeviceThreadForwardImpl in HTTP thread
void QNetworkReplyHttpImplPrivate::wantUploadDataSlot(qint64 maxSize)
{
    Q_Q(QNetworkReplyHttpImpl);

    if (!uploadByteDevice) // uploadByteDevice is no longer available
        return;

    // call readPointer
    qint64 currentUploadDataLength = 0;
    char *data = const_cast<char*>(uploadByteDevice->readPointer(maxSize, currentUploadDataLength));

    if (currentUploadDataLength == 0) {
        uploadDeviceChoking = true;
        // No bytes from upload byte device. There will be bytes later, it will emit readyRead()
        // and our uploadByteDeviceReadyReadSlot() is called.
        return;
    } else {
        uploadDeviceChoking = false;
    }

    // Let's make a copy of this data
    QByteArray dataArray(data, currentUploadDataLength);

    // Communicate back to HTTP thread
    emit q->haveUploadData(uploadByteDevicePosition, dataArray, uploadByteDevice->atEnd(), uploadByteDevice->size());
}

void QNetworkReplyHttpImplPrivate::uploadByteDeviceReadyReadSlot()
{
    // Start the flow between this thread and the HTTP thread again by triggering a upload.
    // However only do this when we were choking before, else the state in
    // QNonContiguousByteDeviceThreadForwardImpl gets messed up.
    if (uploadDeviceChoking) {
        uploadDeviceChoking = false;
        wantUploadDataSlot(1024);
    }
}


/*
    A simple web page that can be used to test us: http://www.procata.com/cachetest/
 */
bool QNetworkReplyHttpImplPrivate::sendCacheContents(const QNetworkCacheMetaData &metaData)
{
    Q_Q(QNetworkReplyHttpImpl);

    setCachingEnabled(false);
    if (!metaData.isValid())
        return false;

    QAbstractNetworkCache *nc = managerPrivate->networkCache;
    Q_ASSERT(nc);
    QIODevice *contents = nc->data(url);
    if (!contents) {
#if defined(QNETWORKACCESSHTTPBACKEND_DEBUG)
        qDebug() << "Cannot send cache, the contents are 0" << url;
#endif
        return false;
    }
    contents->setParent(q);

    QNetworkCacheMetaData::AttributesMap attributes = metaData.attributes();
    int status = attributes.value(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    if (status < 100)
        status = 200;           // fake it

    statusCode = status;

    q->setAttribute(QNetworkRequest::HttpStatusCodeAttribute, status);
    q->setAttribute(QNetworkRequest::HttpReasonPhraseAttribute, attributes.value(QNetworkRequest::HttpReasonPhraseAttribute));
    q->setAttribute(QNetworkRequest::SourceIsFromCacheAttribute, true);

    QHttpHeaders cachedHeaders = metaData.headers();
    QHttpHeaders h = headers();
    QUrl redirectUrl;
    for (qsizetype i = 0; i < cachedHeaders.size(); ++i) {
        const auto name = cachedHeaders.nameAt(i);
        const auto value = cachedHeaders.valueAt(i);

        if (httpRequest.isFollowRedirects()
            && !name.compare(locationHeader(), Qt::CaseInsensitive)) {
            redirectUrl = QUrl::fromEncoded(value);
        }

        h.replaceOrAppend(name, value);
    }
    setHeaders(std::move(h));

    if (!isHttpRedirectResponse())
        checkForRedirect(status);

    cacheLoadDevice = contents;
    q->connect(cacheLoadDevice, SIGNAL(readyRead()), SLOT(_q_cacheLoadReadyRead()));
    q->connect(cacheLoadDevice, SIGNAL(readChannelFinished()), SLOT(_q_cacheLoadReadyRead()));

    // This needs to be emitted in the event loop because it can be reached at
    // the direct code path of qnam.get(...) before the user has a chance
    // to connect any signals.
    QMetaObject::invokeMethod(q, "_q_metaDataChanged", Qt::QueuedConnection);
    QMetaObject::invokeMethod(q, "_q_cacheLoadReadyRead", Qt::QueuedConnection);


#if defined(QNETWORKACCESSHTTPBACKEND_DEBUG)
    qDebug() << "Successfully sent cache:" << url << contents->size() << "bytes";
#endif

    // Do redirect processing
    if (httpRequest.isFollowRedirects() && QHttpNetworkReply::isHttpRedirect(status)) {
        QMetaObject::invokeMethod(q, "onRedirected", Qt::QueuedConnection,
                                  Q_ARG(QUrl, redirectUrl),
                                  Q_ARG(int, status),
                                  Q_ARG(int, httpRequest.redirectCount() - 1));
    }

    // Set the following flag so we can ignore some signals from HTTP thread
    // that would still come
    loadingFromCache = true;
    return true;
}

static auto caseInsensitiveCompare(QByteArrayView value)
{
    return [value](QByteArrayView element)
    {
        return value.compare(element, Qt::CaseInsensitive) == 0;
    };
}

static bool isHopByHop(QByteArrayView header)
{
    constexpr QByteArrayView headers[] = { "connection",
                                           "keep-alive",
                                           "proxy-authenticate",
                                           "proxy-authorization",
                                           "te",
                                           "trailers",
                                           "transfer-encoding",
                                           "upgrade"};
    return std::any_of(std::begin(headers), std::end(headers), caseInsensitiveCompare(header));
}

QNetworkCacheMetaData QNetworkReplyHttpImplPrivate::fetchCacheMetaData(const QNetworkCacheMetaData &oldMetaData) const
{
    Q_Q(const QNetworkReplyHttpImpl);

    QNetworkCacheMetaData metaData = oldMetaData;
    QHttpHeaders cacheHeaders = metaData.headers();

    const auto newHeaders = q->headers();
    for (qsizetype i = 0; i < newHeaders.size(); ++i) {
        const auto name = newHeaders.nameAt(i);
        const auto value = newHeaders.valueAt(i);

        if (isHopByHop(name))
            continue;

        if (name.compare("set-cookie", Qt::CaseInsensitive) == 0)
            continue;

        // for 4.6.0, we were planning to not store the date header in the
        // cached resource; through that we planned to reduce the number
        // of writes to disk when using a QNetworkDiskCache (i.e. don't
        // write to disk when only the date changes).
        // However, without the date we cannot calculate the age of the page
        // anymore.
        //if (header == "date")
            //continue;

        // Don't store Warning 1xx headers
        if (name.compare("warning", Qt::CaseInsensitive) == 0) {
            if (value.size() == 3
                && value[0] == '1'
                && isAsciiDigit(value[1])
                && isAsciiDigit(value[2]))
                continue;
        }

        if (cacheHeaders.contains(name)) {
            // Match the behavior of Firefox and assume Cache-Control: "no-transform"
            constexpr QByteArrayView headers[]=
                    {"content-encoding", "content-range", "content-type"};
            if (std::any_of(std::begin(headers), std::end(headers), caseInsensitiveCompare(name)))
                continue;
        }

        // IIS has been known to send "Content-Length: 0" on 304 responses, so
        // ignore this too
        if (statusCode == 304 && name.compare("content-length", Qt::CaseInsensitive) == 0)
            continue;

#if defined(QNETWORKACCESSHTTPBACKEND_DEBUG)
        QByteArrayView n = newHeaders.value(name);
        QByteArrayView o = cacheHeaders.value(name);
        if (n != o && name.compare("date", Qt::CaseInsensitive) != 0) {
            qDebug() << "replacing" << name;
            qDebug() << "new" << n;
            qDebug() << "old" << o;
        }
#endif
        cacheHeaders.replaceOrAppend(name, value);
    }
    metaData.setHeaders(cacheHeaders);

    bool checkExpired = true;

    QHash<QByteArray, QByteArray> cacheControl;
    auto value = cacheHeaders.value(QHttpHeaders::WellKnownHeader::CacheControl);
    if (!value.empty()) {
        cacheControl = parseHttpOptionHeader(value);
        QByteArray maxAge = cacheControl.value("max-age"_ba);
        if (!maxAge.isEmpty()) {
            checkExpired = false;
            QDateTime dt = QDateTime::currentDateTimeUtc();
            dt = dt.addSecs(maxAge.toInt());
            metaData.setExpirationDate(dt);
        }
    }
    if (checkExpired) {
        if (const auto value = cacheHeaders.value(
                    QHttpHeaders::WellKnownHeader::Expires); !value.isEmpty()) {
            QDateTime expiredDateTime = QNetworkHeadersPrivate::fromHttpDate(value);
            metaData.setExpirationDate(expiredDateTime);
        }
    }

    if (const auto value = cacheHeaders.value(
                QHttpHeaders::WellKnownHeader::LastModified); !value.isEmpty()) {
        metaData.setLastModified(QNetworkHeadersPrivate::fromHttpDate(value));
    }


    bool canDiskCache;
    // only cache GET replies by default, all other replies (POST, PUT, DELETE)
    //  are not cacheable by default (according to RFC 2616 section 9)
    if (httpRequest.operation() == QHttpNetworkRequest::Get) {

        canDiskCache = true;
        // HTTP/1.1. Check the Cache-Control header
        if (cacheControl.contains("no-store"_ba))
            canDiskCache = false;

    // responses to POST might be cacheable
    } else if (httpRequest.operation() == QHttpNetworkRequest::Post) {

        canDiskCache = false;
        // some pages contain "expires:" and "cache-control: no-cache" field,
        // so we only might cache POST requests if we get "cache-control: max-age ..."
        if (cacheControl.contains("max-age"_ba))
            canDiskCache = true;

    // responses to PUT and DELETE are not cacheable
    } else {
        canDiskCache = false;
    }

    metaData.setSaveToDisk(canDiskCache);
    QNetworkCacheMetaData::AttributesMap attributes;
    if (statusCode != 304) {
        // update the status code
        attributes.insert(QNetworkRequest::HttpStatusCodeAttribute, statusCode);
        attributes.insert(QNetworkRequest::HttpReasonPhraseAttribute, reasonPhrase);
    } else {
        // this is a redirection, keep the attributes intact
        attributes = oldMetaData.attributes();
    }
    metaData.setAttributes(attributes);
    return metaData;
}

bool QNetworkReplyHttpImplPrivate::canResume() const
{
    Q_Q(const QNetworkReplyHttpImpl);

    // Only GET operation supports resuming.
    if (operation != QNetworkAccessManager::GetOperation)
        return false;

    const auto h = q->headers();

    // Can only resume if server/resource supports Range header.
    const auto acceptRanges = h.value(QHttpHeaders::WellKnownHeader::AcceptRanges);
    if (acceptRanges.empty() || acceptRanges == "none")
        return false;

    // We only support resuming for byte ranges.
    const auto range = h.value(QHttpHeaders::WellKnownHeader::Range);
    if (!range.empty()) {
        if (!range.startsWith(bytesEqualPrefix()))
            return false;
    }

    // If we're using a download buffer then we don't support resuming/migration
    // right now. Too much trouble.
    if (downloadZerocopyBuffer)
        return false;

    return true;
}

void QNetworkReplyHttpImplPrivate::setResumeOffset(quint64 offset)
{
    resumeOffset = offset;
}

void QNetworkReplyHttpImplPrivate::_q_startOperation()
{
    // Ensure this function is only being called once, and not at all if we were
    // cancelled
    if (state >= Working)
        return;

    state = Working;

    postRequest(request);

    setupTransferTimeout();
    if (synchronous) {
        state = Finished;
        q_func()->setFinished(true);
    }
}

void QNetworkReplyHttpImplPrivate::_q_cacheLoadReadyRead()
{
    Q_Q(QNetworkReplyHttpImpl);

    if (state != Working)
        return;
    if (!cacheLoadDevice || !q->isOpen() || !cacheLoadDevice->bytesAvailable())
        return;

    // FIXME Optimize to use zerocopy download buffer if it is a QBuffer.
    // Needs to be done where sendCacheContents() (?) of HTTP is emitting
    // metaDataChanged ?

    const auto totalSizeOpt = QNetworkHeadersPrivate::toInt(
            headers().value(QHttpHeaders::WellKnownHeader::ContentLength));

    // emit readyRead before downloadProgress in case this will cause events to be
    // processed and we get into a recursive call (as in QProgressDialog).

    if (!(isHttpRedirectResponse())) {
        // This readyRead() goes to the user. The user then may or may not read() anything.
        emit q->readyRead();

        if (downloadProgressSignalChoke.isValid() &&
            downloadProgressSignalChoke.elapsed() >= progressSignalInterval) {
            downloadProgressSignalChoke.start();
            emit q->downloadProgress(bytesDownloaded, totalSizeOpt.value_or(-1));
        }
    }

    // A signal we've emitted might be handled by a slot that aborts,
    // so we need to check for that and bail out if it's happened:
    if (!q->isOpen())
        return;

    // If there are still bytes available in the cacheLoadDevice then the user did not read
    // in response to the readyRead() signal. This means we have to load from the cacheLoadDevice
    // and buffer that stuff. This is needed to be able to properly emit finished() later.
    while (cacheLoadDevice->bytesAvailable() && !isHttpRedirectResponse())
        buffer.append(cacheLoadDevice->readAll());

    if (cacheLoadDevice->isSequential()) {
        // check if end and we can read the EOF -1
        char c;
        qint64 actualCount = cacheLoadDevice->read(&c, 1);
        if (actualCount < 0) {
            cacheLoadDevice->deleteLater();
            cacheLoadDevice = nullptr;
            QMetaObject::invokeMethod(q, "_q_finished", Qt::QueuedConnection);
        } else if (actualCount == 1) {
            // This is most probably not happening since most QIODevice returned something proper for bytesAvailable()
            // and had already been "emptied".
            cacheLoadDevice->ungetChar(c);
        }
    } else if ((!cacheLoadDevice->isSequential() && cacheLoadDevice->atEnd())) {
        // This codepath is in case the cache device is a QBuffer, e.g. from QNetworkDiskCache.
        cacheLoadDevice->deleteLater();
        cacheLoadDevice = nullptr;
        QMetaObject::invokeMethod(q, "_q_finished", Qt::QueuedConnection);
    }
}


void QNetworkReplyHttpImplPrivate::_q_bufferOutgoingDataFinished()
{
    Q_Q(QNetworkReplyHttpImpl);

    // make sure this is only called once, ever.
    //_q_bufferOutgoingData may call it or the readChannelFinished emission
    if (state != Buffering)
        return;

    // disconnect signals
    QObject::disconnect(outgoingData, SIGNAL(readyRead()), q, SLOT(_q_bufferOutgoingData()));
    QObject::disconnect(outgoingData, SIGNAL(readChannelFinished()), q, SLOT(_q_bufferOutgoingDataFinished()));

    // finally, start the request
    QMetaObject::invokeMethod(q, "_q_startOperation", Qt::QueuedConnection);
}

void QNetworkReplyHttpImplPrivate::_q_cacheSaveDeviceAboutToClose()
{
    // do not keep a dangling pointer to the device around (device
    // is closing because e.g. QAbstractNetworkCache::remove() was called).
    cacheSaveDevice = nullptr;
}

void QNetworkReplyHttpImplPrivate::_q_bufferOutgoingData()
{
    Q_Q(QNetworkReplyHttpImpl);

    if (!outgoingDataBuffer) {
        // first call, create our buffer
        outgoingDataBuffer = std::make_shared<QRingBuffer>();

        QObject::connect(outgoingData, SIGNAL(readyRead()), q, SLOT(_q_bufferOutgoingData()));
        QObject::connect(outgoingData, SIGNAL(readChannelFinished()), q, SLOT(_q_bufferOutgoingDataFinished()));
    }

    qint64 bytesBuffered = 0;
    qint64 bytesToBuffer = 0;

    // read data into our buffer
    forever {
        bytesToBuffer = outgoingData->bytesAvailable();
        // unknown? just try 2 kB, this also ensures we always try to read the EOF
        if (bytesToBuffer <= 0)
            bytesToBuffer = 2*1024;

        char *dst = outgoingDataBuffer->reserve(bytesToBuffer);
        bytesBuffered = outgoingData->read(dst, bytesToBuffer);

        if (bytesBuffered == -1) {
            // EOF has been reached.
            outgoingDataBuffer->chop(bytesToBuffer);

            _q_bufferOutgoingDataFinished();
            break;
        } else if (bytesBuffered == 0) {
            // nothing read right now, just wait until we get called again
            outgoingDataBuffer->chop(bytesToBuffer);

            break;
        } else {
            // don't break, try to read() again
            outgoingDataBuffer->chop(bytesToBuffer - bytesBuffered);
        }
    }
}

void QNetworkReplyHttpImplPrivate::_q_transferTimedOut()
{
    Q_Q(QNetworkReplyHttpImpl);
    q->abort();
}

void QNetworkReplyHttpImplPrivate::setupTransferTimeout()
{
    Q_Q(QNetworkReplyHttpImpl);
    if (!transferTimeout) {
      transferTimeout = new QTimer(q);
      QObject::connect(transferTimeout, SIGNAL(timeout()),
                       q, SLOT(_q_transferTimedOut()),
                       Qt::QueuedConnection);
    }
    transferTimeout->stop();
    if (request.transferTimeoutAsDuration() > 0ms) {
        transferTimeout->setSingleShot(true);
        transferTimeout->setInterval(request.transferTimeoutAsDuration());
        QMetaObject::invokeMethod(transferTimeout, "start",
                                  Qt::QueuedConnection);

    }
}

// need to have this function since the reply is a private member variable
// and the special backends need to access this.
void QNetworkReplyHttpImplPrivate::emitReplyUploadProgress(qint64 bytesSent, qint64 bytesTotal)
{
    Q_Q(QNetworkReplyHttpImpl);
    if (isFinished)
        return;

    setupTransferTimeout();

    if (!emitAllUploadProgressSignals) {
        //choke signal emissions, except the first and last signals which are unconditional
        if (uploadProgressSignalChoke.isValid()) {
            if (bytesSent != bytesTotal && uploadProgressSignalChoke.elapsed() < progressSignalInterval) {
                return;
            }
        }
        uploadProgressSignalChoke.start();
    }
    emit q->uploadProgress(bytesSent, bytesTotal);
}

QNonContiguousByteDevice* QNetworkReplyHttpImplPrivate::createUploadByteDevice()
{
    Q_Q(QNetworkReplyHttpImpl);

    if (outgoingDataBuffer)
        uploadByteDevice = QNonContiguousByteDeviceFactory::createShared(outgoingDataBuffer);
    else if (outgoingData) {
        uploadByteDevice = QNonContiguousByteDeviceFactory::createShared(outgoingData);
    } else {
        return nullptr;
    }

    // We want signal emissions only for normal asynchronous uploads
    if (!synchronous)
        QObject::connect(uploadByteDevice.get(), SIGNAL(readProgress(qint64,qint64)),
                         q, SLOT(emitReplyUploadProgress(qint64,qint64)));

    return uploadByteDevice.get();
}

void QNetworkReplyHttpImplPrivate::_q_finished()
{
    // This gets called queued, just forward to real call then
    finished();
}

void QNetworkReplyHttpImplPrivate::finished()
{
    Q_Q(QNetworkReplyHttpImpl);
    if (transferTimeout)
      transferTimeout->stop();
    if (state == Finished || state == Aborted)
        return;

    const auto totalSizeOpt = QNetworkHeadersPrivate::toInt(
            headers().value(QHttpHeaders::WellKnownHeader::ContentLength));
    const qint64 totalSize = totalSizeOpt.value_or(-1);

    // if we don't know the total size of or we received everything save the cache.
    // If the data is compressed then this is done in readData()
    if ((totalSize == -1 || bytesDownloaded == totalSize)
        && !decompressHelper.isValid()) {
        completeCacheSave();
    }

    // We check for errorCode too as in case of SSL handshake failure, we still
    // get the HTTP redirect status code (301, 303 etc)
    if (isHttpRedirectResponse() && errorCode == QNetworkReply::NoError)
        return;

    state = Finished;
    q->setFinished(true);

    if (totalSize == -1) {
        emit q->downloadProgress(bytesDownloaded, bytesDownloaded);
    } else {
        emit q->downloadProgress(bytesDownloaded, totalSize);
    }

    if (bytesUploaded == -1 && (outgoingData || outgoingDataBuffer))
        emit q->uploadProgress(0, 0);

    emit q->readChannelFinished();
    emit q->finished();
}

void QNetworkReplyHttpImplPrivate::_q_error(QNetworkReplyImpl::NetworkError code, const QString &errorMessage)
{
    this->error(code, errorMessage);
}


void QNetworkReplyHttpImplPrivate::error(QNetworkReplyImpl::NetworkError code, const QString &errorMessage)
{
    Q_Q(QNetworkReplyHttpImpl);
    // Can't set and emit multiple errors.
    if (errorCode != QNetworkReply::NoError) {
        // But somewhat unavoidable if we have cancelled the request:
        if (errorCode != QNetworkReply::OperationCanceledError)
            qWarning("QNetworkReplyImplPrivate::error: Internal problem, this method must only be called once.");
        return;
    }

    errorCode = code;
    q->setErrorString(errorMessage);

    // note: might not be a good idea, since users could decide to delete us
    // which would delete the backend too...
    // maybe we should protect the backend
    emit q->errorOccurred(code);
}

void QNetworkReplyHttpImplPrivate::_q_metaDataChanged()
{
    // FIXME merge this with replyDownloadMetaData(); ?

    Q_Q(QNetworkReplyHttpImpl);
    // 1. do we have cookies?
    // 2. are we allowed to set them?
    Q_ASSERT(manager);

    const auto cookiesOpt = QNetworkHeadersPrivate::toSetCookieList(
            headers().values(QHttpHeaders::WellKnownHeader::SetCookie));
    const auto cookies = cookiesOpt.value_or(QList<QNetworkCookie>());
    if (!cookies.empty()
        && request.attribute(QNetworkRequest::CookieSaveControlAttribute,
                                QNetworkRequest::Automatic).toInt() == QNetworkRequest::Automatic) {
        QNetworkCookieJar *jar = manager->cookieJar();
        if (jar) {
            jar->setCookiesFromUrl(cookies, url);
        }
    }
    emit q->metaDataChanged();
}

void QNetworkReplyHttpImplPrivate::createCache()
{
    // check if we can save and if we're allowed to
    if (!managerPrivate->networkCache
        || !request.attribute(QNetworkRequest::CacheSaveControlAttribute, true).toBool())
        return;
    cacheEnabled = true;
}

bool QNetworkReplyHttpImplPrivate::isCachingEnabled() const
{
    return (cacheEnabled && managerPrivate->networkCache != nullptr);
}

void QNetworkReplyHttpImplPrivate::setCachingEnabled(bool enable)
{
    if (!enable && !cacheEnabled)
        return;                 // nothing to do
    if (enable && cacheEnabled)
        return;                 // nothing to do either!

    if (enable) {
        if (Q_UNLIKELY(bytesDownloaded)) {
            qDebug() << "setCachingEnabled: " << bytesDownloaded << " bytesDownloaded";
            // refuse to enable in this case
            qCritical("QNetworkReplyImpl: backend error: caching was enabled after some bytes had been written");
            return;
        }

        createCache();
    } else {
        // someone told us to turn on, then back off?
        // ok... but you should make up your mind
        qDebug("QNetworkReplyImpl: setCachingEnabled(true) called after setCachingEnabled(false)");
        managerPrivate->networkCache->remove(url);
        cacheSaveDevice = nullptr;
        cacheEnabled = false;
    }
}

bool QNetworkReplyHttpImplPrivate::isCachingAllowed() const
{
    return operation == QNetworkAccessManager::GetOperation || operation == QNetworkAccessManager::HeadOperation;
}

void QNetworkReplyHttpImplPrivate::completeCacheSave()
{
    if (cacheEnabled && errorCode != QNetworkReplyImpl::NoError) {
        managerPrivate->networkCache->remove(url);
    } else if (cacheEnabled && cacheSaveDevice) {
        managerPrivate->networkCache->insert(cacheSaveDevice);
    }
    cacheSaveDevice = nullptr;
    cacheEnabled = false;
}

QT_END_NAMESPACE

#include "moc_qnetworkreplyhttpimpl_p.cpp"
