//
// Created by 毛华伟 on 2020/1/12.
//

#ifndef DOPER_DAPP_MD5_H
#define DOPER_DAPP_MD5_H

#include <QString>
#include <QCryptographicHash>


class MD5Utils
{
public:

    static QString md5(QString str)
    {
        QString md5;
        QByteArray ba, bb;
        QCryptographicHash md(QCryptographicHash::Md5);
        ba.append(str);
        md.addData(ba);
        bb = md.result();
        md5.append(bb.toHex());
        return md5;

    }


};


#endif //DOPER_DAPP_MD5_H
