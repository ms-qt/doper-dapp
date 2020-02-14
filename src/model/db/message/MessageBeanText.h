//
// Created by maohuawei on 2020/2/6.
//

#ifndef DOPER_DAPP_MESSAGEBEANTEXT_H
#define DOPER_DAPP_MESSAGEBEANTEXT_H

#include <QObject>

class MessageBeanText : public QObject
{
Q_OBJECT
    Q_PROPERTY(QString textContent
                       READ
                               getTextContent
                       CONSTANT
                       )


    Q_PROPERTY(qint64 time
                       READ
                               getTime
                       CONSTANT
                       )

public:
    MessageBeanText();

public slots:


public:
    QString messageId;
    QString senderId;
    QString textContent;
    QString eventId;
    qint64 time;
    qint64 senderTime;
    qint64 receiveTime;
    bool isMe;
    bool isRead;

public slots:

    const QString &getMessageId() const;

    void setMessageId(const QString &messageId);

    const QString &getSenderId() const;

    void setSenderId(const QString &senderId);

    const QString &getTextContent() const;

    void setTextContent(const QString &textContent);

    const QString &getEventId() const;

    void setEventId(const QString &eventId);

    qint64 getTime() const;

    void setTime(qint64 time);

    qint64 getSenderTime() const;

    void setSenderTime(qint64 senderTime);

    qint64 getReceiveTime() const;

    void setReceiveTime(qint64 receiveTime);

    bool isMe1() const;

    void setIsMe(bool isMe);

    bool isRead1() const;

    void setIsRead(bool isRead);

};


#endif //DOPER_DAPP_MESSAGEBEANTEXT_H
