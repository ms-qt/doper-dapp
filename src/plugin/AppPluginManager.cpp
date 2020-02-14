//
// Created by 毛华伟 on 2020/1/3.
//

#include "AppPluginManager.h"


AppPluginManager *AppPluginManager::instance = nullptr;

AppPluginManager::AppPluginManager()
{
    pluginsPath = qApp->applicationDirPath() + "/plugins";

    qDebug() << "插件目录:" << pluginsPath;

    pluginsDir = new QDir(pluginsPath);

    if (!pluginsDir->exists())
    {
        qDebug() << "插件目录不存在:" << pluginsPath;
        pluginsDir->mkdir(pluginsPath);
    } else
    {
        qDebug() << "插件目录已经存:" << pluginsPath;
    }

    scanLocalPlugin();
}

void AppPluginManager::scanLocalPlugin()
{
    qDebug() << "扫描本地安装插件";

    QDir dir(pluginsPath);
    QStringList nameFilters;
    nameFilters << "*";
    QStringList files = dir.entryList(nameFilters, QDir::Files | QDir::Readable, QDir::Name);


    for (QString it : files)
    {
        qDebug() << " 目录下文件 :" << it;
    }

    qDebug() << " ---------- ";

    for (QString it : files)
    {
        // 检查是否为插件
        if (checkQLibrary(it))
        {
            qDebug() << " 已经安装插件 : " << it;
            qDebug() << " ---------- ";
            QPluginLoader *loader = new QPluginLoader(it);

            // 防止外部插件注入
            IAppPluginInterface *pluginInterface = qobject_cast<IAppPluginInterface *>(loader->instance());

            if (pluginInterface)
            {
                QJsonObject json = loader->metaData().value("MetaData").toObject();

                Plugin *plugin = new Plugin();

                QString name = json.value("name").toString();
                QString author = json.value("author").toString();
                QString date = json.value("date").toString();
                QString versionCode = json.value("versionCode").toString();
                QString versionName = json.value("versionName").toString();
                QString desc = json.value("desc").toString();
                QString iconLocal = json.value("iconLocal").toString();
                QString iconRemotely = json.value("iconRemotely").toString();

                // 实例化插件
                plugin->setAuthor(author);
                plugin->setName(name);

                QDate qDate = QDate::fromString(date, "yyyy/MM/dd");
                plugin->setDate(qDate);
                plugin->setDesc(desc);
                plugin->setIconLocal(iconLocal);
                plugin->setIconRemotely(iconRemotely);


                qDebug() << "  插件名称 : " << name;
                qDebug() << "  插件作者 : " << author;
                qDebug() << "  插件版本名称 : " << versionName;
                qDebug() << "  插件版本号 : " << versionCode;
                qDebug() << "  插件简介 : " << desc;
                qDebug() << "  插件更新时间 : " << date;
                qDebug() << "  本地icon : " << iconLocal;
                qDebug() << "  远程icon : " << iconRemotely;
                qDebug() << "  ---------- ";
                pluginsCache.insert(name, pluginInterface);
                plugins.append(plugin);

                // 关联信号
                connect(pluginInterface, SIGNAL(sendMessage(PluginMetaData * )), this,
                        SLOT(receiveMessage(PluginMetaData * )));

            }
            qDebug() << " ---------- ";
        }
    }
}

bool AppPluginManager::checkQLibrary(QString path)
{
    return QLibrary::isLibrary(path);
}

bool AppPluginManager::isMePlugin()
{
    return false;
}

void AppPluginManager::loader(Plugin *plugin)
{

    qDebug() << " AppPluginManager::loader ";
    qDebug() << " 插件名称 : " << plugin->getName();

    IAppPluginInterface *pluginInterface = pluginsCache.value(plugin->getName());

    if (pluginInterface)
    {
        pluginInterface->loader();


        PluginMetaData *data1 = new PluginMetaData();
        QString *str = new QString("框架给插件返回TOKEN : 123456");
        data1->setData(str);

        emit pluginInterface->sendMessage(data1);

    } else
    {
        delete pluginInterface;
        pluginInterface = Q_NULLPTR;
    }
}


AppPluginManager *AppPluginManager::getInstance()
{
    if (instance == nullptr)
    {
        instance = new AppPluginManager();
    }
    return instance;
}

const QList<Plugin *> AppPluginManager::getPlugins() const
{
    return plugins;
}

void AppPluginManager::receiveMessage(PluginMetaData *data)
{
    qDebug() << " AppPluginManager::receiveMessage ";

    // 此处为二级指针，去除一级指针的内容需要添加 * 
    qDebug() << " plugin send message to : " << *data->getData();
}