//
// Created by 毛华伟 on 2020/1/3.
//

#ifndef APP_PLUGIN_H
#define APP_PLUGIN_H


#include <QString>
#include <QDate>
#include <QObject>

class Plugin : public QObject
{
Q_OBJECT
    Q_PROPERTY(QString name READ getName CONSTANT);
    Q_PROPERTY(QString iconLocal READ getIconLocal CONSTANT)
public:
    Plugin();

    void setName(const QString &name);

    void setPath(const QString &path);

    void setVersionName(const QString &versionName);

    void setVersionCode(const QString &versionCode);

    void setDesc(const QString &desc);

    void setIconLocal(const QString &iconLocal);

    void setIconRemotely(const QString &iconRemotely);

    void setDate(const QDate &date);

    void setStatus(const QString &status);

    void setForceUpdate(bool forceUpdate);

    void setEnable(bool enable);

    void setAuthor(const QString &author);


public slots:

    const QString &getAuthor() const;

    bool isEnable() const;

    bool isForceUpdate() const;

    const QString &getStatus() const;

    const QDate &getDate() const;

    const QString &getIconRemotely() const;

    const QString &getIconLocal() const;

    const QString &getDesc() const;

    const QString &getVersionCode() const;

    const QString &getVersionName() const;

    const QString &getPath() const;

    const QString &getName() const;


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
