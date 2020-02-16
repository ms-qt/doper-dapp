import QtQuick 2.0

Item{
    width: parent.width
    height: parent.height

    // 左侧房间列表
    MainHomeMessageList{
        id:mainHomeMessageList
        width: 260
        height: parent.height
    }

    // 右侧聊天
    MainHomeMessageChat{
        id:mainHomeMessageChat
        width: parent.width-mainHomeMessageList.width
        height: parent.height
        anchors.left: mainHomeMessageList.right
    }

    Connections{
        target: mainHomeMessageList
        onCurrentRoom:{
            console.log("房间ID:"+roomid+"  房间类型:"+roomtype)
            mainHomeMessageChat.setRoomId(roomid)
        }
    }
}
