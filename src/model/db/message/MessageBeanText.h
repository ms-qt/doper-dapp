//
// Created by maohuawei on 2020/2/6.
//
#pragma execution_character_set("utf-8")
#ifndef DOPER_DAPP_MESSAGEBEANTEXT_H
#define DOPER_DAPP_MESSAGEBEANTEXT_H

#include <QObject>

class MessageBeanText : public QObject
{
Q_OBJECT
    Q_PROPERTY(QString _id READ id CONSTANT)
    Q_PROPERTY(qint64 _room_id READ room_id CONSTANT)
    Q_PROPERTY(qint64 _message_id READ message_id CONSTANT)
    Q_PROPERTY(qint64 _event_id READ event_id CONSTANT)
    Q_PROPERTY(qint64 _sender_id READ sender_id CONSTANT)
    Q_PROPERTY(qint64 _time READ _time CONSTANT)
    Q_PROPERTY(qint64 _text_content READ _text_content CONSTANT)
    Q_PROPERTY(qint64 _message_sender_time READ _message_sender_time CONSTANT)
    Q_PROPERTY(qint64 _message_receive_time READ _message_receive_time CONSTANT)
    Q_PROPERTY(qint64 _is_me READ _is_me CONSTANT)
    Q_PROPERTY(qint64 _is_read READ _is_read CONSTANT)
public:
    MessageBeanText();
public:
    int _id;
    QString _room_id;
    QString _message_id;
    QString _event_id;
    QString _sender_id;
    qint64 _time;
    QString _text_content;
    qint64 _message_sender_time;
    qint64 _message_receive_time;
    bool _is_me;
    bool _is_read;

    int id();
    QString room_id();
    QString message_id();
    QString event_id();
    QString sender_id();
    qint64 time();
    QString text_content();
    qint64 message_sender_time();
    qint64 message_receive_time();
    bool is_me();
    bool is_read();
};


#endif //DOPER_DAPP_MESSAGEBEANTEXT_H
