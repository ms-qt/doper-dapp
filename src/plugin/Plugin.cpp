//
// Created by 毛华伟 on 2020/1/3.
//

#include "Plugin.h"

Plugin::Plugin()
{

}

const QString &Plugin::getName() const
{
    return name;
}

void Plugin::setName(const QString &name)
{
    Plugin::name = name;
}

const QString &Plugin::getPath() const
{
    return path;
}

void Plugin::setPath(const QString &path)
{
    Plugin::path = path;
}

const QString &Plugin::getVersionName() const
{
    return versionName;
}

void Plugin::setVersionName(const QString &versionName)
{
    Plugin::versionName = versionName;
}

const QString &Plugin::getVersionCode() const
{
    return versionCode;
}

void Plugin::setVersionCode(const QString &versionCode)
{
    Plugin::versionCode = versionCode;
}

const QString &Plugin::getDesc() const
{
    return desc;
}

void Plugin::setDesc(const QString &desc)
{
    Plugin::desc = desc;
}

const QString &Plugin::getIconLocal() const
{
    return iconLocal;
}

void Plugin::setIconLocal(const QString &iconLocal)
{
    Plugin::iconLocal = iconLocal;
}

const QString &Plugin::getIconRemotely() const
{
    return iconRemotely;
}

void Plugin::setIconRemotely(const QString &iconRemotely)
{
    Plugin::iconRemotely = iconRemotely;
}

const QDate &Plugin::getDate() const
{
    return date;
}

void Plugin::setDate(const QDate &date)
{
    Plugin::date = date;
}

const QString &Plugin::getStatus() const
{
    return status;
}

void Plugin::setStatus(const QString &status)
{
    Plugin::status = status;
}

bool Plugin::isForceUpdate() const
{
    return forceUpdate;
}

void Plugin::setForceUpdate(bool forceUpdate)
{
    Plugin::forceUpdate = forceUpdate;
}

bool Plugin::isEnable() const
{
    return enable;
}

void Plugin::setEnable(bool enable)
{
    Plugin::enable = enable;
}

const QString &Plugin::getAuthor() const
{
    return author;
}

void Plugin::setAuthor(const QString &author)
{
    Plugin::author = author;
}
