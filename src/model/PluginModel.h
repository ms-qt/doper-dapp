//
// Created by maohuawei on 2020/2/15.
//

#ifndef APP_PLUGINMODEL_H
#define APP_PLUGINMODEL_H


#include <QtCore/QObject>
#include "src/plugin/Plugin.h"
#include <QList>

class PluginModel : public QObject
{

Q_OBJECT

public:
    PluginModel();
    ~PluginModel();
public slots:
    QList<QObject *> getPlugins();
private:
    QList<QObject *> plugins;
};
#endif //APP_PLUGINMODEL_H
