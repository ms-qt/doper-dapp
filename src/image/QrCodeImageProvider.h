//
// Created by 毛华伟 on 2020/1/12.
//

#ifndef DOPER_DAPP_QRCODEIMAGEPROVIDER_H
#define DOPER_DAPP_QRCODEIMAGEPROVIDER_H


#include<QQuickImageProvider>
#include <QUuid>
#include <QDateTime>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include"src/qrcode/QRCodeGenerator.h"
#include "src/utils/SystemUtils.h"
#include "src/utils/MD5.h"
#include "src/data/Data.h"

class QrCodeImageProvider : public QQuickImageProvider
{
public:
    QrCodeImageProvider() : QQuickImageProvider(QQuickImageProvider::Pixmap)
    {
    }

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) override
    {
        return refresh();
    }

    QPixmap refresh()
    {
        int levelIndex = 1;
        int versionIndex = 0;
        bool bExtent = true;
        int maskIndex = -1;

        QString uuid = QUuid::createUuid().toString();
        QDateTime time = QDateTime::currentDateTime();   //获取当前时间
        int timeT = time.toTime_t();

        QJsonObject object;
        object.insert("uuid", uuid);
        object.insert("time", timeT);
        object.insert("mac", SystemUtils::mac());
        object.insert("ip", SystemUtils::ip());
        object.insert("origin", MD5::md5("bdlbs"));

        QJsonDocument document = QJsonDocument(object);
        QString encodeString = QString(document.toJson());

        encodeString = MD5::md5(encodeString);
        encodeString = "000000" + encodeString + "000000";
        Data::getInstance().loginQrCodeEnCode = encodeString;

        qDebug() << "QrCodeImageProvider" << encodeString;
        
        qrEncode.EncodeData(levelIndex, versionIndex, bExtent, maskIndex, encodeString.toUtf8().data());

        int qrImageSize = qrEncode.m_nSymbleSize;
        int encodeImageSize = qrImageSize + (QR_MARGIN * 2);
        QImage encodeImage(encodeImageSize, encodeImageSize, QImage::Format_Mono);
        encodeImage.fill(1);
        for (int i = 0; i < qrImageSize; i++)
        {
            for (int j = 0; j < qrImageSize; j++)
            {
                if (qrEncode.m_byModuleData[i][j])
                {
                    encodeImage.setPixel(i + QR_MARGIN, j + QR_MARGIN, 0);
                }
            }
        }
        QPixmap mp = QPixmap::fromImage(encodeImage);
        int scale_size = encodeImageSize * 8;
        const QPixmap &scale_image = mp.scaled(scale_size, scale_size);
        return scale_image;
    }

private:
    CQR_Encode qrEncode;
};


#endif //DOPER_DAPP_QRCODEIMAGEPROVIDER_H
