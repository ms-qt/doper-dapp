//
// Created by 毛华伟 on 2020/1/16.
//

#pragma once


#ifndef DOPER_DAPP_APPQUICKVIEWMANAGER_H
#define DOPER_DAPP_APPQUICKVIEWMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QStandardPaths>
#include <QSqlError>
#include <thread>
#include "src/app/NotificationQuickView.h"
#include "src/app/LoginQuickView.h"
#include "src/app/MainQuickView.h"

// 窗口管理器

class AppQuickViewManager
{
public:
    // 获取单实例
    static AppQuickViewManager *GetInstance();

    // 释放单实例，进程退出时调用
    static void DeleteInstance();


    void init();

private:
    AppQuickViewManager();

    ~AppQuickViewManager();

    void initdb();


private:
    static AppQuickViewManager *instance;

public:

    LoginQuickView *getLoginQuickView();

    NotificationQuickView *getNotificationQuickView();

    MainQuickView *getMainQuickView();

private:

    LoginQuickView *loginQuickView = nullptr;
    NotificationQuickView *notificationQuickView = nullptr;
    MainQuickView *appQuickView = nullptr;

};

#endif //DOPER_DAPP_APPQUICKVIEWMANAGER_H

