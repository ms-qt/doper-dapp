//
// Created by maohuawei on 2020/2/17.
//

#include "UserBean.h"


UserBean::UserBean()
{
}
int UserBean::id()
{
    return _id;
}
QString UserBean::user_id()
{ return _user_id; }

QString UserBean::name()
{ return _name; }

int UserBean::age()
{ return _age; }

bool UserBean::sex()
{ return _sex; }

QString UserBean::department()
{ return _department; }

QString UserBean::job_title()
{ return _job_title; }

QString UserBean::avatar()
{ return _avatar; }

QString UserBean::signature()
{ return _signature; }

QString UserBean::phonenumber()
{ return _phonenumber; }

QString UserBean::email()
{ return _email; }

QString UserBean::qq()
{ return _qq; }

QString UserBean::introduction()
{ return _introduction; }

QString UserBean::company()
{ return _company; }