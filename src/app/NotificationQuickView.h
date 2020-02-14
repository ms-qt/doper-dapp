//
// Created by 毛华伟 on 2020/1/16.
//
#pragma execution_character_set("utf-8")
#ifndef DOPER_DAPP_NOTIFICATIONQUICKVIEW_H
#define DOPER_DAPP_NOTIFICATIONQUICKVIEW_H

#include <QQuickView>
#include <QDesktopWidget>
#include <QApplication>
#include <QThread>
#include <QQmlContext>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QQmlEngine>

#include "src/notifications/manager.h"
#include "src/model/db/task/TaskModel.h"
#include "src/model/db/task/TaskListModel.h"
#include "src/model/db/message/MessageListModel.h"
#include "src/model/db/message/MessagTextModel.h"
#include "src/model/db/room/RoomListModel.h"
#include "src/model/db/room/RoomP2PModel.h"
#include "src/model/db/message/MessageBeanText.h"
#include "src/model/db/user/UserModel.h"
#include "src/app/UIModelProxy.h"
#include "src/systemfeatures/Clipboard.h"
#include "src/image/ImageProvider.h"
#include "src/image/ImageAsyncImageProvider.h"
#include "src/db/CertificateDB.h"
#include "src/app/base/BaseQQuickView.h"

class NotificationQuickView : public BaseQQuickView
{

Q_OBJECT
public:

    NotificationQuickView();

    ~NotificationQuickView();


public slots:

    void loginSuccess();

    void activated(QSystemTrayIcon::ActivationReason reason);

    void openMainControllerPaneltriggered(bool checked);

private:

    // 退出选项
    QAction *actionExit;
    // 在线
    QAction *actionOnLine;
    // 打开通知米那般
    QAction *actionOpenNotificationPanel;
    // 打开主控面板
    QAction *actionOpenMainControllPanel;
    // 隐身
    QAction *actionStealth;
    // 离线
    QAction *actionOffline;
    // 离开
    QAction *actionLeave;

    // 托盘
    QSystemTrayIcon *systemTrayIcon;
    // 菜单
    QMenu *menu;

    // 剪切板
    Clipboard *clipboard;
    ImageProvider *imageProvider;
    AsyncImageProvider *asyncImageProvider;


};


#endif //DOPER_DAPP_NOTIFICATIONQUICKVIEW_H
