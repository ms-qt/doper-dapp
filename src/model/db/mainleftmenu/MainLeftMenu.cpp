//
// Created by maohuawei on 2020/2/14.
//

#include "MainLeftMenu.h"


MainLeftMenu::MainLeftMenu(QObject *parent)
{

}

QString MainLeftMenu::name() const
{
    return m_name;
}

void MainLeftMenu::setName(const QString &name)
{
    if(name!=m_name){
        m_name = name;
        emit nameChanged();
    }

}

QString MainLeftMenu::iconUrl() const
{
    return m_iconUrl;
}

void MainLeftMenu::setIconUrl(const QString &iconUrl)
{
    if(iconUrl!=m_iconUrl){
        m_iconUrl = iconUrl;
        emit iconUrlChanged();
    }

}
