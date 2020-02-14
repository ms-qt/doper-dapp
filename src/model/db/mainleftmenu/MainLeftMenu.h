//
// Created by maohuawei on 2020/2/14.
//

#ifndef DOPER_DAPP_MAINLEFTMENU_H
#define DOPER_DAPP_MAINLEFTMENU_H


#include <QObject>

class MainLeftMenu: public QObject
{
Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString iconUrl READ iconUrl WRITE setIconUrl NOTIFY iconUrlChanged)
    //![0]

public:
    MainLeftMenu(QObject *parent=0);

    QString name() const;
    void setName(const QString &name);

    QString iconUrl() const;
    void setIconUrl(const QString &iconUrl);

signals:
    void nameChanged();
    void iconUrlChanged();

private:
    QString m_name;
    QString m_iconUrl;
    //![1]
};


#endif //DOPER_DAPP_MAINLEFTMENU_H
