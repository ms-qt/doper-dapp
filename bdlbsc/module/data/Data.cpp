﻿//
// Created by dev on 2020/3/12.
//

#include <bdlbsc/module/data/Data.h>

namespace bdlbsc
{
    bdlbsc::Data::Data() {}

    bdlbsc::Data::~Data() {}
    void bdlbsc::Data::set_app_id(QString values)
    {

        this->_app_id = values;
    }
    QString bdlbsc::Data::get_app_id()
    {
        return _app_id;
    }
    void bdlbsc::Data::set_app_secret(QString values)
    {

        this->_app_secret = values;
    }
    QString bdlbsc::Data::get_app_secret()
    {
        return _app_secret;
    }
    void bdlbsc::Data::set_app_access_token(QString values)
    {
        this->_app_access_token = values;
    }
    QString bdlbsc::Data::get_app_access_token()
    {

        return _app_access_token;
    }
    void bdlbsc::Data::set_user_access_token(QString values)
    {

        this->_user_access_token = values;
    }
    QString bdlbsc::Data::get_user_access_token()
    {
        return _user_access_token;
    }
    void bdlbsc::Data::set_user_id(QString values)
    {

        this->_user_id = values;
    }
    QString bdlbsc::Data::get_user_id()
    {
        return _user_id;
    }

    QString bdlbsc::Data::get_base_url()
    {

        return _base_url;
    }

    void bdlbsc::Data::set_base_url(QString values)
    {

        this->_base_url = values;
    }

} // namespace bdlbsc
