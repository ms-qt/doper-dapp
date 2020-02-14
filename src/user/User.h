//
// Created by 毛华伟 on 2020/1/7.
//

#ifndef APP_USER_H
#define APP_USER_H


#include <QString>

class User
{
private:
    // 名称
    QString name;
    // ID
    QString userid;
    // 性别
    QString sex;
    // 年龄
    int age;
    // 部门
    QString department;
    // 职称
    QString jobTitle;
    // 头像
    QString avatar;
    // 签名
    QString signature;
    // 手机号
    QString phoneNumber;
    // 邮箱
    QString email;
    // qq
    QString qq;
    // 简介
    QString introduction;

public:
    User();
};


#endif //APP_USER_H
