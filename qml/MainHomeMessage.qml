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
    // 聊天信息列表
    MainHomeMessageChatList{
        id:mainHomeMessageChatList
        width: parent.width-mainHomeMessageList
        height: parent.height
    }

    Connections{
        target: mainHomeMessageList
        onCurrentRoomId:{
            console.log("房间ID:"+roomid+"  房间类型:"+roomtype)
        }

    }
}
