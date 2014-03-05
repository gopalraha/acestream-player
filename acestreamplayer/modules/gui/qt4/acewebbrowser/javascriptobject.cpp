#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <p2p_object.h>

#include "acewebbrowser/javascriptobject.hpp"

#include <QDebug>

using namespace AceWebBrowser;

JavaScriptObject::JavaScriptObject(QObject *parent) :
    QObject(parent)
  , mPlayerInFullscreen(false)
  , mFlashEnabled(true)
  , mBrowserIsVisible(false)
  , mHostUserAgent("")
{
}

void JavaScriptObject::setIsInFullscreen(bool value)
{
    if(value != mPlayerInFullscreen) {
        mPlayerInFullscreen = value;
    }
}

void JavaScriptObject::setFlashEnabled(bool value)
{
    if(value != mFlashEnabled) {
        mFlashEnabled = value;
    }
}

void JavaScriptObject::setVisiability(bool value)
{
    if(value != mBrowserIsVisible) {
        mBrowserIsVisible = value;
    }
}

void JavaScriptObject::setHostUserAgent(const QString &value)
{
    if(value != mHostUserAgent) {
        mHostUserAgent = value;
    }
}

void JavaScriptObject::browserClose()
{
    emit jsoCloseBrowser();
}

void JavaScriptObject::linkOpen(QString url, bool openInNewWindow)
{
    emit jsoLinkOpen(url, openInNewWindow);
}

void JavaScriptObject::linkOpenLater(QString url, bool high_priority)
{
    emit jsoLinkOpenLater(url, high_priority);
}

void JavaScriptObject::fillPlayerSize()
{
    emit jsoFillPlayerSize();
}

void JavaScriptObject::playerPlay()
{
    emit jsoPlayerPlay();
}

void JavaScriptObject::playerPause()
{
    emit jsoPlayerPause();
}

void JavaScriptObject::playerStop()
{
    emit jsoPlayerStop();
}

bool JavaScriptObject::playerIsFullscreen()
{
    return mPlayerInFullscreen;
}

bool JavaScriptObject::browserIsVisible()
{
    return mBrowserIsVisible;
}

QString JavaScriptObject::pluginVersion()
{
    return ""P2P_STD_VERSION"";
}

bool JavaScriptObject::flashEnabled()
{
    return mFlashEnabled;
}

QString JavaScriptObject::getHostUserAgent()
{
    return mHostUserAgent;
}

void JavaScriptObject::debug(QString msg)
{
    qDebug() << "[JavaScriptObject] " << msg;
}

void JavaScriptObject::handlePlayerSizeChanged(const QSize &size)
{
    mPlayerSize = size;
}

void JavaScriptObject::handleBrowserSizeChanged(const QSize &size)
{
    mBrowserSize = size;
}

void JavaScriptObject::playerSetFullscreen(bool fullscreen)
{
    emit jsoPlayerSetFullscreen(fullscreen);
}

void JavaScriptObject::browserSetSize(unsigned int width, unsigned int height)
{
    emit jsoBrowserSetSize(QSize(width, height));
}