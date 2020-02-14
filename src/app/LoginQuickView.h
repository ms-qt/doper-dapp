//
// Created by 毛华伟 on 2020/1/16.
//
#pragma execution_character_set("utf-8")
#ifndef DOPER_DAPP_LOGINQUICKVIEW_H
#define DOPER_DAPP_LOGINQUICKVIEW_H

#include <QQuickView>
#include <QDesktopWidget>
#include <QApplication>
#include <QQmlEngine>
#include <QQmlContext>
#include<QDebug>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QFile>
#include <QTextStream>

#include "src/image/QrCodeImageProvider.h"
#include "src/db/CertificateDB.h"
#include "src/im/IMModel.h"
#include "UIModelProxy.h"
#include "src/app/base/BaseQQuickView.h"

class LoginQuickView : public QQuickView
{
Q_OBJECT
public:
    LoginQuickView();

    ~LoginQuickView();


    // 设置提示文字
    void setHintText(QString text);

    // 设置用户名
    void setUsername(QString username);

    // 设置密码
    void setPassword(QString password);

    // 设置保存密码
    void setSavePassword(bool savepassword);

    // 设置自动登录
    void setAutoLogin(bool autologin);


public slots:


    // 登录成功
    void loginSuccess();

    //开始登录
    void startLogin();


    // 显示加载中
    void homeShowDialog();

    // 隐藏加载中
    void homeHideDialog();


    void qrCodeShowDialog();

    void qrCodeHideDialog();

    void activated(QSystemTrayIcon::ActivationReason reason);

private:


    // 提示文字
    QObject *textHintObject;
    // 登录表单信息
    QObject *columnLayoutLoginHomeFromInfo;
    // 登录界面的加载中...
    QObject *loadingLoginHomeObject;
    // 二维码界面加载中Dialog
    QObject *loadingQrCodeObject;


    // 退出选项
    QAction *actionExit;
    // 托盘
    QSystemTrayIcon *systemTrayIcon;
    // 菜单
    QMenu *menu;


};


#endif //DOPER_DAPP_LOGINQUICKVIEW_H
