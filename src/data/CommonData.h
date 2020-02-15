//
// Created by 毛华伟 on 2020/1/12.
//

#ifndef DOPER_DAPP_DATA_H
#define DOPER_DAPP_DATA_H

#include <iostream>

class CommonData
{
public:

    static CommonData &getInstance()
    {
        static CommonData instance;
        return instance;
    }


    QString ip = "";
    QString mac = "";
    QString width = "";
    QString height = "";
    QString screenNumber = "";
    QString screenRect = "";
    QString uuid="";
    QString login_qrcode_encoding;
    QString access_token = "";
    QString userid = "";


private:
    CommonData()
    {};

    ~CommonData()
    {};

    CommonData(const CommonData &);

    CommonData &operator=(const CommonData &);
};


#endif //DOPER_DAPP_DATA_H
