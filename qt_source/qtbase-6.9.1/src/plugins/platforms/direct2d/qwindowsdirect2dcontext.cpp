// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include <QtCore/qt_windows.h>
#include "qwindowsdirect2dcontext.h"
#include "qwindowsdirect2dhelpers.h"
#include "qwindowsdirect2dintegration.h"

#include <QtCore/private/qcomptr_p.h>

#include <d3d11_1.h>
#include <d2d1_1.h>
#include <d2d1_1helper.h>
#include <dxgi1_2.h>
#include <dwrite.h>

QT_BEGIN_NAMESPACE

class QWindowsDirect2DContextPrivate
{
public:
    bool init()
    {
        HRESULT hr;

        D3D_FEATURE_LEVEL level;

        D3D_DRIVER_TYPE typeAttempts[] = {
            D3D_DRIVER_TYPE_HARDWARE,
            D3D_DRIVER_TYPE_WARP
        };
        const int ntypes = int(sizeof(typeAttempts) / sizeof(typeAttempts[0]));

        for (int i = 0; i < ntypes; i++) {
            hr = D3D11CreateDevice(nullptr,
                                   typeAttempts[i],
                                   nullptr,
                                   D3D11_CREATE_DEVICE_SINGLETHREADED | D3D11_CREATE_DEVICE_BGRA_SUPPORT,
                                   nullptr,
                                   0,
                                   D3D11_SDK_VERSION,
                                   &d3dDevice,
                                   &level,
                                   &d3dDeviceContext);

            if (SUCCEEDED(hr))
                break;
        }

        if (FAILED(hr)) {
            qWarning("%s: Could not create Direct3D Device: %#lx", __FUNCTION__, hr);
            return false;
        }

        ComPtr<IDXGIDevice1> dxgiDevice;
        ComPtr<IDXGIAdapter> dxgiAdapter;

        hr = d3dDevice.As(&dxgiDevice);
        if (FAILED(hr)) {
            qWarning("%s: DXGI Device interface query failed on D3D Device: %#lx", __FUNCTION__, hr);
            return false;
        }

        // Ensure that DXGI doesn't queue more than one frame at a time.
        dxgiDevice->SetMaximumFrameLatency(1);

        hr = dxgiDevice->GetAdapter(&dxgiAdapter);
        if (FAILED(hr)) {
            qWarning("%s: Failed to probe DXGI Device for parent DXGI Adapter: %#lx", __FUNCTION__, hr);
            return false;
        }

        hr = dxgiAdapter->GetParent(IID_PPV_ARGS(&dxgiFactory));
        if (FAILED(hr)) {
            qWarning("%s: Failed to probe DXGI Adapter for parent DXGI Factory: %#lx", __FUNCTION__, hr);
            return false;
        }

        D2D1_FACTORY_OPTIONS options = {};

#ifdef QT_D2D_DEBUG_OUTPUT
        qDebug("Turning on Direct2D debugging messages");
        options.debugLevel = D2D1_DEBUG_LEVEL_INFORMATION;
#endif // QT_D2D_DEBUG_OUTPUT

        hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, options, d2dFactory.GetAddressOf());
        if (FAILED(hr)) {
            qWarning("%s: Could not create Direct2D Factory: %#lx", __FUNCTION__, hr);
            return false;
        }

        hr = d2dFactory->CreateDevice(dxgiDevice.Get(), &d2dDevice);
        if (FAILED(hr)) {
            qWarning("%s: Could not create D2D Device: %#lx", __FUNCTION__, hr);
            return false;
        }

        hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory),
                                 static_cast<IUnknown **>(&directWriteFactory));
        if (FAILED(hr)) {
            qWarning("%s: Could not create DirectWrite factory: %#lx", __FUNCTION__, hr);
            return false;
        }

        hr = directWriteFactory->GetGdiInterop(&directWriteGdiInterop);
        if (FAILED(hr)) {
            qWarning("%s: Could not create DirectWrite GDI Interop: %#lx", __FUNCTION__, hr);
            return false;
        }

        return true;
    }

    ComPtr<ID3D11Device>  d3dDevice;
    ComPtr<ID2D1Factory1> d2dFactory;
    ComPtr<ID2D1Device>   d2dDevice;
    ComPtr<IDXGIFactory2>  dxgiFactory;
    ComPtr<ID3D11DeviceContext> d3dDeviceContext;
    ComPtr<IDWriteFactory> directWriteFactory;
    ComPtr<IDWriteGdiInterop> directWriteGdiInterop;
};

QWindowsDirect2DContext::QWindowsDirect2DContext()
    : d_ptr(new QWindowsDirect2DContextPrivate)
{
}

QWindowsDirect2DContext::~QWindowsDirect2DContext() = default;

bool QWindowsDirect2DContext::init()
{
    Q_D(QWindowsDirect2DContext);
    return d->init();
}

QWindowsDirect2DContext *QWindowsDirect2DContext::instance()
{
    return QWindowsDirect2DIntegration::instance()->direct2DContext();
}

ID3D11Device *QWindowsDirect2DContext::d3dDevice() const
{
    Q_D(const QWindowsDirect2DContext);
    return d->d3dDevice.Get();
}

ID2D1Device *QWindowsDirect2DContext::d2dDevice() const
{
    Q_D(const QWindowsDirect2DContext);
    return d->d2dDevice.Get();
}

ID2D1Factory1 *QWindowsDirect2DContext::d2dFactory() const
{
    Q_D(const QWindowsDirect2DContext);
    return d->d2dFactory.Get();
}

IDXGIFactory2 *QWindowsDirect2DContext::dxgiFactory() const
{
    Q_D(const QWindowsDirect2DContext);
    return d->dxgiFactory.Get();
}

ID3D11DeviceContext *QWindowsDirect2DContext::d3dDeviceContext() const
{
    Q_D(const QWindowsDirect2DContext);
    return d->d3dDeviceContext.Get();
}

IDWriteFactory *QWindowsDirect2DContext::dwriteFactory() const
{
    Q_D(const QWindowsDirect2DContext);
    return d->directWriteFactory.Get();
}

IDWriteGdiInterop *QWindowsDirect2DContext::dwriteGdiInterop() const
{
    Q_D(const QWindowsDirect2DContext);
    return d->directWriteGdiInterop.Get();
}

QT_END_NAMESPACE
