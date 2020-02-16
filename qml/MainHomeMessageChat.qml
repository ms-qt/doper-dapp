import QtQuick 2.0

Item {
    width: parent.width
    height: parent.height

    function setRoomId(roomid)
    {
        mainHomeMessageChatList.setRoomId(roomid)
    }

    property int rightComponentWidth : 200

    Rectangle{
        id:rectangleMainHomeMessageChatTopMenu
        width: parent.width-rightComponentWidth
        height: 60
        color: "#ff0011"
    }

    // 聊天信息列表
    MainHomeMessageChatList{
        id:mainHomeMessageChatList
        anchors.top:rectangleMainHomeMessageChatTopMenu.bottom
        width: parent.width-rightComponentWidth
        height: parent.height-160
    }

    // 输入框
    Rectangle{
        id:rectangleMainHomeMessageChatBottom
        anchors.top:mainHomeMessageChatList.bottom
        width: parent.width-rightComponentWidth
        height: 100
        color: "#f055aa"
    }
}
