// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qsurfaceformat.h"

#include <QtCore/qatomic.h>
#include <QtCore/QDebug>
#include <QOpenGLContext>
#include <QtGui/qcolorspace.h>
#include <QtGui/qguiapplication.h>

#ifdef major
#undef major
#endif

#ifdef minor
#undef minor
#endif

QT_BEGIN_NAMESPACE

class QSurfaceFormatPrivate
{
public:
    explicit QSurfaceFormatPrivate(QSurfaceFormat::FormatOptions _opts = { })
        : ref(1)
        , opts(_opts)
        , redBufferSize(-1)
        , greenBufferSize(-1)
        , blueBufferSize(-1)
        , alphaBufferSize(-1)
        , depthSize(-1)
        , stencilSize(-1)
        , swapBehavior(QSurfaceFormat::DefaultSwapBehavior)
        , numSamples(-1)
        , renderableType(QSurfaceFormat::DefaultRenderableType)
        , profile(QSurfaceFormat::NoProfile)
        , major(2)
        , minor(0)
        , swapInterval(1) // default to vsync
    {
    }

    QSurfaceFormatPrivate(const QSurfaceFormatPrivate *other)
        : ref(1),
          opts(other->opts),
          redBufferSize(other->redBufferSize),
          greenBufferSize(other->greenBufferSize),
          blueBufferSize(other->blueBufferSize),
          alphaBufferSize(other->alphaBufferSize),
          depthSize(other->depthSize),
          stencilSize(other->stencilSize),
          swapBehavior(other->swapBehavior),
          numSamples(other->numSamples),
          renderableType(other->renderableType),
          profile(other->profile),
          major(other->major),
          minor(other->minor),
          swapInterval(other->swapInterval),
          colorSpace(other->colorSpace)
    {
    }

    QAtomicInt ref;
    QSurfaceFormat::FormatOptions opts;
    int redBufferSize;
    int greenBufferSize;
    int blueBufferSize;
    int alphaBufferSize;
    int depthSize;
    int stencilSize;
    QSurfaceFormat::SwapBehavior swapBehavior;
    int numSamples;
    QSurfaceFormat::RenderableType renderableType;
    QSurfaceFormat::OpenGLContextProfile profile;
    int major;
    int minor;
    int swapInterval;
    QColorSpace colorSpace;
};

/*!
    \class QSurfaceFormat
    \since 5.0
    \brief The QSurfaceFormat class represents the format of a QSurface.
    \inmodule QtGui

    The format includes the size of the color buffers, red, green, and blue;
    the size of the alpha buffer; the size of the depth and stencil buffers;
    and number of samples per pixel for multisampling. In addition, the format
    contains surface configuration parameters such as OpenGL profile and
    version for rendering, whether or not to enable stereo buffers, and swap
    behaviour.

    \note When troubleshooting context or window format issues, it can be
    helpful to enable the logging category \c{qt.qpa.gl}. Depending on the
    platform, this may print useful debug information when it comes to OpenGL
    initialization and the native visual or framebuffer configurations which
    QSurfaceFormat gets mapped to.
*/

/*!
    \enum QSurfaceFormat::FormatOption

    This enum contains format options for use with QSurfaceFormat.

    \value StereoBuffers Used to request stereo buffers in the surface format.
    \value DebugContext Used to request a debug context with extra debugging information.
    \value DeprecatedFunctions Used to request that deprecated functions be included
        in the OpenGL context profile. If not specified, you should get a forward compatible context
        without support functionality marked as deprecated. This requires OpenGL version 3.0 or higher.
    \value ResetNotification Enables notifications about resets of the OpenGL context. The status is then
        queryable via the context's \l{QOpenGLContext::isValid()}{isValid()} function. Note that not setting
        this flag does not guarantee that context state loss never occurs. Additionally, some implementations
        may choose to report context loss regardless of this flag. Platforms that support dynamically enabling
        the monitoring of the loss of context, such as, Windows with WGL, or Linux/X11 (xcb) with GLX, will
        monitor the status in every call to \l{QOpenGLContext::makeCurrent()}{makeCurrent()}. See
        \l{QOpenGLContext::isValid()}{isValid()} for more information on this.
    \value ProtectedContent Enables access to protected content. This allows the GPU to operate on protected
        resources (surfaces, buffers, textures), for example DRM-protected video content.
        Currently only implemented for EGL.
*/

/*!
    \enum QSurfaceFormat::SwapBehavior

    This enum is used by QSurfaceFormat to specify the swap behaviour of a surface. The swap behaviour
    is mostly transparent to the application, but it affects factors such as rendering latency and
    throughput.

    \value DefaultSwapBehavior The default, unspecified swap behaviour of the platform.
    \value SingleBuffer Used to request single buffering, which might result in flickering
        when OpenGL rendering is done directly to screen without an intermediate offscreen
        buffer.
    \value DoubleBuffer This is typically the default swap behaviour on desktop platforms,
        consisting of one back buffer and one front buffer. Rendering is done to the back
        buffer, and then the back buffer and front buffer are swapped, or the contents of
        the back buffer are copied to the front buffer, depending on the implementation.
    \value TripleBuffer This swap behaviour is sometimes used in order to decrease the
        risk of skipping a frame when the rendering rate is just barely keeping up with
        the screen refresh rate. Depending on the platform it might also lead to slightly
        more efficient use of the GPU due to improved pipelining behaviour. Triple buffering
        comes at the cost of an extra frame of memory usage and latency, and might not be
        supported depending on the underlying platform.
*/

/*!
    \enum QSurfaceFormat::RenderableType

    This enum specifies the rendering backend for the surface.

    \value DefaultRenderableType The default, unspecified rendering method
    \value OpenGL Desktop OpenGL rendering
    \value OpenGLES OpenGL ES 2.0 rendering
    \value OpenVG Open Vector Graphics rendering
*/

/*!
    \enum QSurfaceFormat::OpenGLContextProfile

    This enum is used to specify the OpenGL context profile, in
    conjunction with QSurfaceFormat::setMajorVersion() and
    QSurfaceFormat::setMinorVersion().

    Profiles are exposed in OpenGL 3.2 and above, and are used
    to choose between a restricted core profile, and a compatibility
    profile which might contain deprecated support functionality.

    Note that the core profile might still contain functionality that
    is deprecated and scheduled for removal in a higher version. To
    get access to the deprecated functionality for the core profile
    in the set OpenGL version you can use the QSurfaceFormat format option
    QSurfaceFormat::DeprecatedFunctions.

    \value NoProfile            OpenGL version is lower than 3.2. For 3.2 and newer this is same as CoreProfile.
    \value CoreProfile          Functionality deprecated in OpenGL version 3.0 is not available.
    \value CompatibilityProfile Functionality from earlier OpenGL versions is available.
*/

/*!
    \enum QSurfaceFormat::ColorSpace
    \deprecated [6.0] Use setColorSpace(QColorSpace) instead

    This enum is used to specify the preferred color space, controlling if the
    window's associated default framebuffer is able to do updates and blending
    in a given encoding instead of the standard linear operations.

    \value DefaultColorSpace The default, unspecified color space.

    \value sRGBColorSpace When \c{GL_ARB_framebuffer_sRGB} or
    \c{GL_EXT_framebuffer_sRGB} is supported by the platform and this value is
    set, the window will be created with an sRGB-capable default
    framebuffer. Note that some platforms may return windows with a sRGB-capable
    default framebuffer even when not requested explicitly.
 */

/*!
    Constructs a default initialized QSurfaceFormat.

    \note By default OpenGL 2.0 is requested since this provides the highest
    grade of portability between platforms and OpenGL implementations.
*/
QSurfaceFormat::QSurfaceFormat() : d(new QSurfaceFormatPrivate)
{
}

/*!
    Constructs a QSurfaceFormat with the given format \a options.
*/
QSurfaceFormat::QSurfaceFormat(QSurfaceFormat::FormatOptions options) :
    d(new QSurfaceFormatPrivate(options))
{
}

/*!
    \internal
*/
void QSurfaceFormat::detach()
{
    if (d->ref.loadRelaxed() != 1) {
        QSurfaceFormatPrivate *newd = new QSurfaceFormatPrivate(d);
        if (!d->ref.deref())
            delete d;
        d = newd;
    }
}

/*!
    Constructs a copy of \a other.
*/
QSurfaceFormat::QSurfaceFormat(const QSurfaceFormat &other)
{
    d = other.d;
    d->ref.ref();
}

/*!
    Assigns \a other to this object.
*/
QSurfaceFormat &QSurfaceFormat::operator=(const QSurfaceFormat &other)
{
    if (d != other.d) {
        other.d->ref.ref();
        if (!d->ref.deref())
            delete d;
        d = other.d;
    }
    return *this;
}

/*!
    Destroys the QSurfaceFormat.
*/
QSurfaceFormat::~QSurfaceFormat()
{
    if (!d->ref.deref())
        delete d;
}

/*!
    \fn bool QSurfaceFormat::stereo() const

    Returns \c true if stereo buffering is enabled; otherwise returns
    false. Stereo buffering is disabled by default.

    \sa setStereo()
*/

/*!
    If \a enable is true enables stereo buffering; otherwise disables
    stereo buffering.

    Stereo buffering is disabled by default.

    Stereo buffering provides extra color buffers to generate left-eye
    and right-eye images.

    \sa stereo()
*/
void QSurfaceFormat::setStereo(bool enable)
{
    QSurfaceFormat::FormatOptions newOptions = d->opts;
    newOptions.setFlag(QSurfaceFormat::StereoBuffers, enable);

    if (int(newOptions) != int(d->opts)) {
        detach();
        d->opts = newOptions;
    }
}

/*!
    Returns the number of samples per pixel when multisampling is
    enabled, or \c -1 when multisampling is disabled. The default
    return value is \c -1.

    \sa setSamples()
*/
int QSurfaceFormat::samples() const
{
   return d->numSamples;
}

/*!
    Set the preferred number of samples per pixel when multisampling
    is enabled to \a numSamples. By default, multisampling is disabled.

    \sa samples()
*/
void QSurfaceFormat::setSamples(int numSamples)
{
    if (d->numSamples != numSamples) {
        detach();
        d->numSamples = numSamples;
    }
}

/*!
    \since 5.3

    Sets the format options to \a options.

    To verify that an option was respected, compare the actual format to the
    requested format after surface/context creation.

    \sa options(), testOption()
*/
void QSurfaceFormat::setOptions(QSurfaceFormat::FormatOptions options)
{
    if (int(d->opts) != int(options)) {
        detach();
        d->opts = options;
    }
}

/*!
    \since 5.3

    Sets the format option \a option if \a on is true; otherwise, clears the option.

    To verify that an option was respected, compare the actual format to the
    requested format after surface/context creation.

    \sa setOptions(), options(), testOption()
*/
void QSurfaceFormat::setOption(QSurfaceFormat::FormatOption option, bool on)
{
    if (testOption(option) == on)
        return;
    detach();
    if (on)
        d->opts |= option;
    else
        d->opts &= ~option;
}

/*!
    \since 5.3

    Returns true if the format option \a option is set; otherwise returns false.

    \sa options()
*/
bool QSurfaceFormat::testOption(QSurfaceFormat::FormatOption option) const
{
    return d->opts & option;
}

/*!
    \since 5.3

    Returns the currently set format options.

    \sa setOption(), setOptions(), testOption()
*/
QSurfaceFormat::FormatOptions QSurfaceFormat::options() const
{
    return d->opts;
}

/*!
    Set the minimum depth buffer size to \a size.

    \sa depthBufferSize()
*/
void QSurfaceFormat::setDepthBufferSize(int size)
{
    if (d->depthSize != size) {
        detach();
        d->depthSize = size;
    }
}

/*!
    Returns the depth buffer size.

    \sa setDepthBufferSize()
*/
int QSurfaceFormat::depthBufferSize() const
{
   return d->depthSize;
}

/*!
    Set the swap \a behavior of the surface.

    The swap behavior specifies whether single, double, or triple
    buffering is desired. The default, DefaultSwapBehavior,
    gives the default swap behavior of the platform.
*/
void QSurfaceFormat::setSwapBehavior(SwapBehavior behavior)
{
    if (d->swapBehavior != behavior) {
        detach();
        d->swapBehavior = behavior;
    }
}

/*!
    Returns the configured swap behaviour.

    \sa setSwapBehavior()
*/
QSurfaceFormat::SwapBehavior QSurfaceFormat::swapBehavior() const
{
    return d->swapBehavior;
}

/*!
    Returns \c true if the alpha buffer size is greater than zero.

    This means that the surface might be used with per pixel
    translucency effects.
*/
bool QSurfaceFormat::hasAlpha() const
{
    return d->alphaBufferSize > 0;
}

/*!
    Set the preferred stencil buffer size to \a size bits.

    \sa stencilBufferSize()
*/
void QSurfaceFormat::setStencilBufferSize(int size)
{
    if (d->stencilSize != size) {
        detach();
        d->stencilSize = size;
    }
}

/*!
    Returns the stencil buffer size in bits.

    \sa setStencilBufferSize()
*/
int QSurfaceFormat::stencilBufferSize() const
{
   return d->stencilSize;
}

/*!
    Get the size in bits of the red channel of the color buffer.
*/
int QSurfaceFormat::redBufferSize() const
{
    return d->redBufferSize;
}

/*!
    Get the size in bits of the green channel of the color buffer.
*/
int QSurfaceFormat::greenBufferSize() const
{
    return d->greenBufferSize;
}

/*!
    Get the size in bits of the blue channel of the color buffer.
*/
int QSurfaceFormat::blueBufferSize() const
{
    return d->blueBufferSize;
}

/*!
    Get the size in bits of the alpha channel of the color buffer.
*/
int QSurfaceFormat::alphaBufferSize() const
{
    return d->alphaBufferSize;
}

/*!
    Set the desired \a size in bits of the red channel of the color buffer.
*/
void QSurfaceFormat::setRedBufferSize(int size)
{
    if (d->redBufferSize != size) {
        detach();
        d->redBufferSize = size;
    }
}

/*!
    Set the desired \a size in bits of the green channel of the color buffer.
*/
void QSurfaceFormat::setGreenBufferSize(int size)
{
    if (d->greenBufferSize != size) {
        detach();
        d->greenBufferSize = size;
    }
}

/*!
    Set the desired \a size in bits of the blue channel of the color buffer.
*/
void QSurfaceFormat::setBlueBufferSize(int size)
{
    if (d->blueBufferSize != size) {
        detach();
        d->blueBufferSize = size;
    }
}

/*!
    Set the desired \a size in bits of the alpha channel of the color buffer.
*/
void QSurfaceFormat::setAlphaBufferSize(int size)
{
    if (d->alphaBufferSize != size) {
        detach();
        d->alphaBufferSize = size;
    }
}

/*!
    Sets the desired renderable \a type.

    Chooses between desktop OpenGL, OpenGL ES, and OpenVG.
*/
void QSurfaceFormat::setRenderableType(RenderableType type)
{
    if (d->renderableType != type) {
        detach();
        d->renderableType = type;
    }
}

/*!
    Gets the renderable type.

    Chooses between desktop OpenGL, OpenGL ES, and OpenVG.
*/
QSurfaceFormat::RenderableType QSurfaceFormat::renderableType() const
{
    return d->renderableType;
}

/*!
    Sets the desired OpenGL context \a profile.

    This setting is ignored if the requested OpenGL version is
    less than 3.2.
*/
void QSurfaceFormat::setProfile(OpenGLContextProfile profile)
{
    if (d->profile != profile) {
        detach();
        d->profile = profile;
    }
}

/*!
    Get the configured OpenGL context profile.

    This setting is ignored if the requested OpenGL version is
    less than 3.2.
*/
QSurfaceFormat::OpenGLContextProfile QSurfaceFormat::profile() const
{
    return d->profile;
}

/*!
    Sets the desired \a major OpenGL version.
*/
void QSurfaceFormat::setMajorVersion(int major)
{
    if (d->major != major) {
        detach();
        d->major = major;
    }
}

/*!
    Returns the major OpenGL version.

    The default version is 2.0.
*/
int QSurfaceFormat::majorVersion() const
{
    return d->major;
}

/*!
    Sets the desired \a minor OpenGL version.

    The default version is 2.0.
*/
void QSurfaceFormat::setMinorVersion(int minor)
{
    if (d->minor != minor) {
        detach();
        d->minor = minor;
    }
}

/*!
    Returns the minor OpenGL version.
*/
int QSurfaceFormat::minorVersion() const
{
    return d->minor;
}

/*!
    Returns a std::pair<int, int> representing the OpenGL version.

    Useful for version checks, for example format.version() >= std::pair(3, 2)
*/
std::pair<int, int> QSurfaceFormat::version() const
{
    return std::pair(d->major, d->minor);
}

/*!
    Sets the desired \a major and \a minor OpenGL versions.

    The default version is 2.0.
*/
void QSurfaceFormat::setVersion(int major, int minor)
{
    if (d->minor != minor || d->major != major) {
        detach();
        d->minor = minor;
        d->major = major;
    }
}

/*!
    Sets the preferred swap interval. The swap interval specifies the
    minimum number of video frames that are displayed before a buffer
    swap occurs. This can be used to sync the GL drawing into a window
    to the vertical refresh of the screen.

    Setting an \a interval value of 0 will turn the vertical refresh
    syncing off, any value higher than 0 will turn the vertical
    syncing on. Setting \a interval to a higher value, for example 10,
    results in having 10 vertical retraces between every buffer swap.

    The default interval is 1.

    Changing the swap interval may not be supported by the underlying
    platform. In this case, the request will be silently ignored.

    \since 5.3

    \sa swapInterval()
 */
void QSurfaceFormat::setSwapInterval(int interval)
{
    if (d->swapInterval != interval) {
        detach();
        d->swapInterval = interval;
    }
}

/*!
    Returns the swap interval.

    \since 5.3

    \sa setSwapInterval()
*/
int QSurfaceFormat::swapInterval() const
{
    return d->swapInterval;
}

/*!
    Sets the preferred \a colorSpace.

    For example, this allows requesting windows with default framebuffers that
    are sRGB-capable on platforms that support it.

    \note When the requested color space is not supported by the platform, the
    request is ignored. Query the QSurfaceFormat after window creation to verify
    if the color space request could be honored or not.

    \note This setting controls if the default framebuffer of the window is
    capable of updates and blending in a given color space. It does not change
    applications' output by itself. The applications' rendering code will still
    have to opt in via the appropriate OpenGL calls to enable updates and
    blending to be performed in the given color space instead of using the
    standard linear operations.

    \since 6.0

    \sa colorSpace()
 */
void QSurfaceFormat::setColorSpace(const QColorSpace &colorSpace)
{
    if (d->colorSpace != colorSpace) {
        detach();
        d->colorSpace = colorSpace;
    }
}

#if QT_DEPRECATED_SINCE(6, 0)
/*!
    \overload
    \deprecated [6.0] Use setColorSpace(QColorSpace) instead.

    Sets the colorspace to one of the predefined values.

    \since 5.10

    \sa colorSpace()
 */
void QSurfaceFormat::setColorSpace(ColorSpace colorSpace)
{
    switch (colorSpace) {
    case DefaultColorSpace:
        setColorSpace(QColorSpace());
        break;
    case sRGBColorSpace:
        setColorSpace(QColorSpace::SRgb);
        break;
    }
}
#endif // QT_DEPRECATED_SINCE(6, 0)

/*!
    \return the color space.

    \since 5.10

    \sa setColorSpace()
*/
const QColorSpace &QSurfaceFormat::colorSpace() const
{
    return d->colorSpace;
}

Q_GLOBAL_STATIC(QSurfaceFormat, qt_default_surface_format)

/*!
    Sets the global default surface \a format.

    This format is used by default in QOpenGLContext, QWindow, QOpenGLWidget and
    similar classes.

    It can always be overridden on a per-instance basis by using the class in
    question's own setFormat() function. However, it is often more convenient to
    set the format for all windows once at the start of the application. It also
    guarantees proper behavior in cases where shared contexts are required,
    because setting the format via this function guarantees that all contexts
    and surfaces, even the ones created internally by Qt, will use the same
    format.

    \note When setting Qt::AA_ShareOpenGLContexts, it is strongly recommended to
    place the call to this function before the construction of the
    QGuiApplication or QApplication. Otherwise \a format will not be applied to
    the global share context and therefore issues may arise with context sharing
    afterwards.

    \since 5.4
    \sa defaultFormat()
 */
void QSurfaceFormat::setDefaultFormat(const QSurfaceFormat &format)
{
#ifndef QT_NO_OPENGL
    if (qApp) {
        QOpenGLContext *globalContext = QOpenGLContext::globalShareContext();
        if (globalContext && globalContext->isValid()) {
            qWarning("Warning: Setting a new default format with a different version or profile "
                     "after the global shared context is created may cause issues with context "
                     "sharing.");
        }
    }
#endif
    *qt_default_surface_format() = format;
}

/*!
    Returns the global default surface format.

    When setDefaultFormat() is not called, this is a default-constructed QSurfaceFormat.

    \since 5.4
    \sa setDefaultFormat()
 */
QSurfaceFormat QSurfaceFormat::defaultFormat()
{
    return *qt_default_surface_format();
}

/*!
    \fn bool QSurfaceFormat::operator==(const QSurfaceFormat& lhs, const QSurfaceFormat& rhs)

    Returns \c true if all the options of the two QSurfaceFormat objects
    \a lhs and \a rhs are equal.
*/

/*!
    \fn bool QSurfaceFormat::operator!=(const QSurfaceFormat& lhs, const QSurfaceFormat& rhs)

    Returns \c false if all the options of the two QSurfaceFormat objects
    \a lhs and \a rhs are equal; otherwise returns \c true.
*/

/*!
    \internal
*/
bool QSurfaceFormat::equals(const QSurfaceFormat& other) const noexcept
{
    return (d == other.d) || ((int) d->opts == (int) other.d->opts
        && d->stencilSize == other.d->stencilSize
        && d->redBufferSize == other.d->redBufferSize
        && d->greenBufferSize == other.d->greenBufferSize
        && d->blueBufferSize == other.d->blueBufferSize
        && d->alphaBufferSize == other.d->alphaBufferSize
        && d->depthSize == other.d->depthSize
        && d->numSamples == other.d->numSamples
        && d->swapBehavior == other.d->swapBehavior
        && d->profile == other.d->profile
        && d->major == other.d->major
        && d->minor == other.d->minor
        && d->swapInterval == other.d->swapInterval);
}

#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug dbg, const QSurfaceFormat &f)
{
    const QSurfaceFormatPrivate * const d = f.d;
    QDebugStateSaver saver(dbg);

    dbg.nospace() << "QSurfaceFormat("
                  << "version " << d->major << '.' << d->minor
                  << ", options " << d->opts
                  << ", depthBufferSize " << d->depthSize
                  << ", redBufferSize " << d->redBufferSize
                  << ", greenBufferSize " << d->greenBufferSize
                  << ", blueBufferSize " << d->blueBufferSize
                  << ", alphaBufferSize " << d->alphaBufferSize
                  << ", stencilBufferSize " << d->stencilSize
                  << ", samples " << d->numSamples
                  << ", swapBehavior " << d->swapBehavior
                  << ", swapInterval " << d->swapInterval
                  << ", colorSpace " << d->colorSpace
                  << ", profile  " << d->profile
                  << ')';

    return dbg;
}
#endif

QT_END_NAMESPACE

#include "moc_qsurfaceformat.cpp"
