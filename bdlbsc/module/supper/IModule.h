//
// Created by dev on 2020/3/12.
//

#ifndef MODULES_IMODULE_H
#define MODULES_IMODULE_H

#include <QObject>

namespace bdlbsc
{
    class IModule : public QObject
    {
        Q_OBJECT
    public:
        virtual ~IModule() {};
       // virtual QString module_name() = 0;
    };
} // namespace bdlbsc

#endif //MODULES_IMODULE_H
