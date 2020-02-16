//
// Created by 毛华伟 on 2020/1/19.
//

#include "IMModel.h"


IMModel::IMModel()
{
    imProxy = new IMProxy();
}

void IMModel::login(QString username, QString password, bool savePassword, bool autoLogin)
{
    qDebug() << "username : " << username;
    qDebug() << "password : " << password;
    qDebug() << "savePassword : " << savePassword;
    qDebug() << "autoLogin : " << autoLogin;

    //正则表达式检验表单信息

    // 网络请求
    // 登录回调
    LoginCallBack *loginCallBack = new LoginCallBack();
    // 发起登录
    imProxy->login(username, password, savePassword, autoLogin, loginCallBack);

    
}
