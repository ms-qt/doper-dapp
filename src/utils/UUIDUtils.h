//
// Created by 毛华伟 on 2020/1/13.
//

#ifndef DOPER_DAPP_UUIDUTILS_H
#define DOPER_DAPP_UUIDUTILS_H

#include <QUuid>


class UUIDUtils
{

public:
    static QString uuid()
    {
        return QUuid::createUuid().toString();
    }
};


#endif //DOPER_DAPP_UUIDUTILS_H
