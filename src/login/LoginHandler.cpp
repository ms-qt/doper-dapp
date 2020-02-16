//
// Created by 毛华伟 on 2020/2/15.
//

#include "LoginHandler.h"


LoginHandler::LoginHandler()
{

}

LoginHandler::~LoginHandler()
{

}

void LoginHandler::login(QString username, QString password, bool savePassword, bool autoLogin)
{

    qDebug() << "username : " << username;
    qDebug() << "password : " << password;
    qDebug() << "savePassword : " << savePassword;
    qDebug() << "autoLogin : " << autoLogin;


    // 模拟登录
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
                    [this, username, password, savePassword, autoLogin](int i)
                    {
                        std::cout << " obs : " << i << "     " << std::this_thread::get_id() << std::endl;
                        if (i == 2)
                        {

                            CertificateBean *certificateBean = new CertificateBean();
                            CertificateDB *certificateDb = new CertificateDB();
                            certificateBean->_username = username;
                            certificateBean->_password = password;
                            certificateBean->_save_password = savePassword;
                            certificateBean->_auto_login = autoLogin;
                            certificateBean->_access_token = "test_access_token";
                            certificateBean->_refresh_token = "test_refresg_token";
                            certificateBean->_user_id = "maohuawei";
                            certificateBean->_login_type = "login-username";
                            certificateDb->insert(certificateBean);

                            emit loginSuccess("maohuawei");
                        }
                    });

}
