import QtQuick 2.0

Rectangle {
    property string messageType
    property string messageId
    property string time




    MainHomeMessageChatListItemText{
        visible: messageType=="_text"
        textContent:"哈哈哈哈"
    }
}
