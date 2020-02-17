//
// Created by maohuawei on 2020/2/17.
//

#include "RoomP2PBean.h"

RoomP2PBean::RoomP2PBean()
{
}
int RoomP2PBean::id()
{ return _id; }

QString RoomP2PBean::room_id()
{ return _room_id; }

QString RoomP2PBean::room_name()
{ return _room_name; }

QString RoomP2PBean::room_avatar()
{ return _room_avatar; }

int RoomP2PBean::room_version()
{ return _room_version; }