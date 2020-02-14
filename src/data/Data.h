//
// Created by 毛华伟 on 2020/1/12.
//

#ifndef DOPER_DAPP_DATA_H
#define DOPER_DAPP_DATA_H

#include <iostream>

class Data
{
public:

    static Data &getInstance()
    {
        static Data instance;
        return instance;
    }



    QString ip = "";
    QString mac = "";
    QString width = "";
    QString height = "";
    QString screenNumber = "";
    QString screenRect = "";
    QString uuid="";
    QString loginQrCodeEnCode;

    QString access_token = "";
    QString userid = "";


private:
    Data()
    {};

    ~Data()
    {};

    Data(const Data &);

    Data &operator=(const Data &);
};


#endif //DOPER_DAPP_DATA_H
