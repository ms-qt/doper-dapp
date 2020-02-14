//
// Created by 毛华伟 on 2020/1/8.
//

#ifndef APP_SYSTEMUTILS_H
#define APP_SYSTEMUTILS_H


#include <QHostAddress>
#include <QNetworkInterface>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QSysInfo>
#include "QSettings"
#include "QDebug"
#include <QDesktopWidget>
#include <QFileInfoList>
#include <QDir>
#include <QLibrary>
#include <QTimer>
#include <QHostInfo>


class SystemUtils : public QObject
{

public:

    static QString localmachineName();

    static QString ip();

    static QString publicIp();

    static QString mac();

    static QString cpuType();

    static QString dCard();

    static QString memory();

    static QString osVersion();

    static QString screen();

    static QString disk();

    static bool ipLive();

    static QString getHtml(QString url);

};


#endif //APP_SYSTEMUTILS_H
