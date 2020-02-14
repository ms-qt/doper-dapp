//
// Created by 毛华伟 on 2020/1/8.
//

#include "IM.h"
#include "IMProxy.h"

#include "src/tool/ThreadTool.h"

IMProxy::IMProxy()
{
}


void IMProxy::login(QString username, QString password, bool savePassword, bool autoLogin, LoginCallBack *callBack)
{
    qDebug() << "IMProxy::login";
    emit   UIModelProxy::GetInstance()->startLogin();

    std::string res = folly::toJson(
            folly::dynamic::object
                    ("login_type", "login-username")
                    ("username", username.toStdString())
                    ("password", password.toStdString())
                    ("save_password", savePassword)
                    ("auto_login", autoLogin)
                    ("user_id", "maohuawei")
                    ("access_token", "1112223334445556666")
                    ("refresh_token", "1112223334445556666")
    );

    std::cout << " main : " << "     " << std::this_thread::get_id() << std::endl;

    rxcpp::observable<>::create<int>([](rxcpp::subscriber<int> subscriber)
                                     {
                                         for (int i = 0; i < 3; i++)
                                         {
                                             std::cout << " sub : " << std::this_thread::get_id() << std::endl;
                                             subscriber.on_next(i);
                                             QThread::sleep(1);
                                         }
                                     })
            .subscribe_on(rxcpp::observe_on_event_loop())
            .observe_on(ThreadTool::getInstance()->main_thread)
            .subscribe(
                    [callBack,res](int i)
                    {
                        std::cout << " obs : " << i << "     " << std::this_thread::get_id() << std::endl;
                        if (i == 2)
                        {
                            if (callBack != nullptr)
                            {
                                callBack->onSuccess(res);
                            }
                        }
                    });
}