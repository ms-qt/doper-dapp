//
// Created by 毛华伟 on 2020/1/19.
//

#include "AppQuickViewManager.h"

AppQuickViewManager *AppQuickViewManager::instance = nullptr;


AppQuickViewManager::AppQuickViewManager()
{
    initdb();
}

AppQuickViewManager::~AppQuickViewManager()
{
}

AppQuickViewManager *AppQuickViewManager::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new AppQuickViewManager();
    }
    return instance;
}

void AppQuickViewManager::DeleteInstance()
{
    if (instance != nullptr)
    {
        delete instance;
    }
}

void AppQuickViewManager::initdb()
{
    // 初始化数据库
    QSqlDatabase database = QSqlDatabase::database();
    if (!database.isValid())
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
        if (!database.isValid())
            qFatal("Cannot add database: %s", qPrintable(database.lastError().text()));
    }

    const QDir writeDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (!writeDir.mkpath("."))
        qFatal("Failed to create writable directory at %s", qPrintable(writeDir.absolutePath()));

    const QString fileName = writeDir.absolutePath() + "/app-database.sqlite3";

    qDebug() << "数据库位置 :  " << fileName;

    database.setDatabaseName(fileName);
    if (!database.open())
    {
        qFatal("Cannot open database: %s", qPrintable(database.lastError().text()));
        QFile::remove(fileName);
    }
}

LoginQuickView *AppQuickViewManager::getLoginQuickView()
{
    if (loginQuickView == nullptr)
    {
        loginQuickView = new LoginQuickView();
    }

    return loginQuickView;
}

NotificationQuickView *AppQuickViewManager::getNotificationQuickView()
{

    if (notificationQuickView == nullptr)
    {
        notificationQuickView = new NotificationQuickView();
    }

    return notificationQuickView;
}

MainQuickView * AppQuickViewManager::getMainQuickView()
{
	if (appQuickView == nullptr) {
		appQuickView = new MainQuickView();
	}
	return appQuickView;
}


void AppQuickViewManager::init()
{

    getLoginQuickView();
    getNotificationQuickView();
	getMainQuickView();
	
}   