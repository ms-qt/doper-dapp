//
// Created by 毛华伟 on 2020/1/3.
//

#ifndef APP_PLUGIN_H
#define APP_PLUGIN_H


#include <QString>
#include <QDate>

class Plugin
{
public:
    Plugin();


    const QString &getName() const;

    void setName(const QString &name);

    const QString &getPath() const;

    void setPath(const QString &path);

    const QString &getVersionName() const;

    void setVersionName(const QString &versionName);

    const QString &getVersionCode() const;

    void setVersionCode(const QString &versionCode);

    const QString &getDesc() const;

    void setDesc(const QString &desc);

    const QString &getIconLocal() const;

    void setIconLocal(const QString &iconLocal);

    const QString &getIconRemotely() const;

    void setIconRemotely(const QString &iconRemotely);

    const QDate &getDate() const;

    void setDate(const QDate &date);

    const QString &getStatus() const;

    void setStatus(const QString &status);

    bool isForceUpdate() const;

    void setForceUpdate(bool forceUpdate);

    bool isEnable() const;

    void setEnable(bool enable);

    const QString &getAuthor() const;

    void setAuthor(const QString &author);


private:
    // 插件名称
    QString name;
    // 插件位置
    QString path;
    // 插件版本名称
    QString versionName;
    // 插件版本号
    QString versionCode;
    // 插件描述
    QString desc;
    // icon 本地地址
    QString iconLocal;
    // icon 远程地址
    QString iconRemotely;
    // 最后更新时间
    QDate date;
    // dev  release test
    QString status;
    // 是否强制跟新
    bool forceUpdate;
    // 是否启用
    bool enable;
    // 作者
    QString author;
};


#endif //APP_PLUGIN_H
