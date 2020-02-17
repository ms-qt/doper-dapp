//
// Created by maohuawei on 2020/2/6.
//

#include "MessageBeanText.h"

MessageBeanText::MessageBeanText()
{
}

int MessageBeanText::id()
{
    return _id;
}

QString MessageBeanText::room_id()
{
    return _room_id;
}

QString MessageBeanText::message_id()
{
    return _message_id;
}

QString MessageBeanText::event_id()
{
    return _event_id;
}

QString MessageBeanText::sender_id()
{
    return _sender_id;
}

qint64 MessageBeanText::time()
{
    return _time;
}

QString MessageBeanText::text_content()
{
    return _text_content;
}

qint64 MessageBeanText::message_sender_time()
{
    return _message_sender_time;
}

qint64 MessageBeanText::message_receive_time()
{
    return _message_receive_time;
}

bool MessageBeanText::is_me()
{
    return _is_me;
}

bool MessageBeanText::is_read()
{
    return _is_read;
}