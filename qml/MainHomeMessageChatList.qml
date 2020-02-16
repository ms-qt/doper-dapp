import QtQuick 2.0

// 聊天信息的列表
Item {
    width: parent.width
    height: parent.height

    ListView {
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width
        height: parent.height
        id: listViewMainHomeMessageChatList
        spacing: 12
        verticalLayoutDirection: ListView.BottomToTop
        model: messageDbModel
        cacheBuffer: 50
        focus: true
        clip: true



    }
}
