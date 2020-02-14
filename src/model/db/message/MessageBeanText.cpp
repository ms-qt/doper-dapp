//
// Created by maohuawei on 2020/2/6.
//

#include "MessageBeanText.h"

MessageBeanText::MessageBeanText()
{
}

const QString &MessageBeanText::getMessageId() const
{
    return messageId;
}

void MessageBeanText::setMessageId(const QString &messageId)
{
    MessageBeanText::messageId = messageId;
}

const QString &MessageBeanText::getSenderId() const
{
    return senderId;
}

void MessageBeanText::setSenderId(const QString &senderId)
{
    MessageBeanText::senderId = senderId;
}

const QString &MessageBeanText::getTextContent() const
{
    return textContent;
}

void MessageBeanText::setTextContent(const QString &textContent)
{
    MessageBeanText::textContent = textContent;
}

const QString &MessageBeanText::getEventId() const
{
    return eventId;
}

void MessageBeanText::setEventId(const QString &eventId)
{
    MessageBeanText::eventId = eventId;
}

qint64 MessageBeanText::getTime() const
{
    return time;
}

void MessageBeanText::setTime(qint64 time)
{
    MessageBeanText::time = time;
}

qint64 MessageBeanText::getSenderTime() const
{
    return senderTime;
}

void MessageBeanText::setSenderTime(qint64 senderTime)
{
    MessageBeanText::senderTime = senderTime;
}

qint64 MessageBeanText::getReceiveTime() const
{
    return receiveTime;
}

void MessageBeanText::setReceiveTime(qint64 receiveTime)
{
    MessageBeanText::receiveTime = receiveTime;
}

bool MessageBeanText::isMe1() const
{
    return isMe;
}

void MessageBeanText::setIsMe(bool isMe)
{
    MessageBeanText::isMe = isMe;
}

bool MessageBeanText::isRead1() const
{
    return isRead;
}

void MessageBeanText::setIsRead(bool isRead)
{
    MessageBeanText::isRead = isRead;
}
