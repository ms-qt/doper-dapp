//
// Created by maohuawei on 2020/2/17.
//

#ifndef APP_USERBEAN_H
#define APP_USERBEAN_H

#include <QObject>

class UserBean : public QObject
{
Q_OBJECT

    Q_PROPERTY(int _id READ id CONSTANT)
    Q_PROPERTY(QString _user_id READ user_id CONSTANT)
    Q_PROPERTY(QString _name READ name CONSTANT)
    Q_PROPERTY(int _age READ age CONSTANT)
    Q_PROPERTY(bool _sex READ sex CONSTANT)
    Q_PROPERTY(QString _department READ department CONSTANT)
    Q_PROPERTY(QString _job_title READ job_title CONSTANT)
    Q_PROPERTY(QString _avatar READ avatar CONSTANT)
    Q_PROPERTY(QString _signature READ signature CONSTANT)
    Q_PROPERTY(QString _phonenumber READ phonenumber CONSTANT)
    Q_PROPERTY(QString _email READ email CONSTANT)
    Q_PROPERTY(QString _qq READ qq CONSTANT)
    Q_PROPERTY(QString _introduction READ introduction CONSTANT)
    Q_PROPERTY(QString _company READ company CONSTANT)


public:

    UserBean();
    int _id;
    QString _user_id;
    QString _name;
    int _age;
    bool _sex;
    QString _department;
    QString _job_title;
    QString _avatar;
    QString _signature;
    QString _phonenumber;
    QString _email;
    QString _qq;
    QString _introduction;
    QString _company;


    int id();
    QString user_id();
    QString name();
    int age();
    bool sex();
    QString department();
    QString job_title();
    QString avatar();
    QString signature();
    QString phonenumber();
    QString email();
    QString qq();
    QString introduction();
    QString company();


};


#endif //APP_USERBEAN_H
