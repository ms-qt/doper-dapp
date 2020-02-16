//
// Created by maohuawei on 2020/2/15.
//

#include "PluginModel.h"

PluginModel::PluginModel()
{
    for (int i = 0; i < 10; i++)
    {
        Plugin *pluginIM = new Plugin();
        pluginIM->setIconLocal("qrc:/images/image_message.png");
        pluginIM->setName("消息");
        plugins.append(pluginIM);
    }
}

PluginModel::~PluginModel()
{

}

QList<QObject *> PluginModel::getPlugins()
{
    return plugins;
}
