//
// Created by 毛华伟 on 2020/1/7.
//

#pragma execution_character_set("utf-8")
#ifndef APP_APPQUICKVIEW_H
#define APP_APPQUICKVIEW_H


#include <QObject>
#include <QQuickView>
#include <QQmlContext>
#include <QVariant>
#include <QDesktopWidget>
#include <QRect>
#include <QApplication>
#include <QTimer>
#include <QSqlDatabase>
#include <QDebug>
#include <QDir>
#include <QStandardPaths>
#include <QSqlError>


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
#include "src/db/CertificateDB.h"
#include "src/app/base/BaseQQuickView.h"
#include "src/image/ImageAsyncImageProvider.h"

#include "src/utils/UUIDUtils.h"
#include "src/conversation/conversation.h"

#include "src/model/db/mainleftmenu/MainLeftMenu.h"

// 主控面板
class MainQuickView : public BaseQQuickView
{
Q_OBJECT
public:
    MainQuickView();

    // 显示加载中
    void showDialog();

    // 隐藏加载中
    void hideDialog();

    // 设置提示文字
    void setHintText(QString text);


public slots :

    void enterRoom(QString roomId);

    void enterTask(QString taskId);

    void openMainControllerPanel();

    void sendMessage(QString userId);

private:

};

#endif //APP_APPQUICKVIEW_H
