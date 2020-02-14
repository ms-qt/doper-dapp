//
// Created by 毛华伟 on 2020/1/3.
//

#ifndef APP_APPPLUGINMANAGER_H
#define APP_APPPLUGINMANAGER_H


#include <QObject>
#include <QObject>
#include <QPluginLoader>
#include <QVariant>
#include <QDir>
#include <QCoreApplication>
#include <QDebug>
#include "src/plugin/Plugin.h"
#include "apppluginterface/IAppPluginInterface.h"
#include "apppluginterface/PluginMetaData.h"


class AppPluginManager : public QObject
{
Q_OBJECT
public:
    // 获取实例
    static AppPluginManager *getInstance();

    // 加载插件
    void loader(Plugin *plugin);



private :
    // 私有构造函数
    AppPluginManager();

    // 单实例
    static AppPluginManager *instance;
    // 插件目录
    QDir *pluginsDir;
    // 插件目录字符串
    QString pluginsPath;
    // 所有的插件集合
    QList<Plugin *> qListPlugins;

    // 扫描本地已有插件
    void scanLocalPlugin();

    // 检查是否为插件
    bool checkQLibrary(QString path);

    // 检查是否为自己的插件，防止外部注入
    bool isMePlugin();

signals:

    void sendMessage(PluginMetaData *data);

public slots:

    void receiveMessage(PluginMetaData *data);


private:

    QList<Plugin*> plugins;
public:
    const QList<Plugin *> getPlugins() const;


private:
    QHash<QString, IAppPluginInterface *> pluginsCache;


};

#endif //APP_APPPLUGINMANAGER_H
