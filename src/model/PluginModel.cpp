//
// Created by maohuawei on 2020/2/15.
//

#include "PluginModel.h"

PluginModel::PluginModel()
{
    for (int i = 0; i < 10; i++)
    {
        Plugin *pluginIm = new Plugin();
        pluginIm->setIconLocal("qrc:/images/image_message.png");
        pluginIm->setName("消息");
        plugins.append(pluginIm);
    }
}

PluginModel::~PluginModel()
{
}

QList<QObject *> PluginModel::getPlugins()
{
    return plugins;
}