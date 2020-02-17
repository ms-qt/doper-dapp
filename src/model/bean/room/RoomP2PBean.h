//
// Created by maohuawei on 2020/2/17.
//

#ifndef APP_ROOMP2PBEAN_H
#define APP_ROOMP2PBEAN_H


#include <QObject>
#include <QString>


class RoomP2PBean : public QObject
{
Q_OBJECT
    Q_PROPERTY(int _id READ id CONSTANT)
    Q_PROPERTY(QString _room_id READ room_id CONSTANT)
    Q_PROPERTY(QString _room_name READ room_name CONSTANT)
    Q_PROPERTY(QString _room_avatar READ room_avatar CONSTANT)
    Q_PROPERTY(int _room_version READ room_version CONSTANT)
public:
    RoomP2PBean();
    int _id;
    QString _room_id;
    QString _room_name;
    QString _room_avatar;
    int _room_version;

    int id();
    QString room_id();
    QString room_name();
    QString room_avatar();
    int room_version();

};


#endif //APP_ROOMP2PBEAN_H
