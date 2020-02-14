//
// Created by 毛华伟 on 2020/1/20.
// App UI 代理，主要解决头文件互相依赖(递归BUG)
//

#ifndef DOPER_DAPP_UIMODELPROXY_H
#define DOPER_DAPP_UIMODELPROXY_H


#include <QObject>
#include <thread>

class UIModelProxy : public QObject
{
Q_OBJECT
public:

    static UIModelProxy *GetInstance();

    static void DeleteInstance();


private:
    UIModelProxy();

    ~UIModelProxy();

    static UIModelProxy *instance;

signals:

    // 开始登录
    void startLogin();

    // 登录成功
    void loginSuccess();

    // 进入房间 通知面板进入主控面板
    void enterRoom(QString roomId);

    // 进入任务 通知面板进入主控面板
    void enterTask(QString taskId);

    // 打开主控面板
    void openMainControllerPanel();

    // 通讯录发送发送消息
    void sendMessage(QString userId);


};


#endif //DOPER_DAPP_UIMODELPROXY_H
