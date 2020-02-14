import QtQuick 2.0


// 房间列表条目

Item {
    width: parent.width
    height: parent.height
    property string  roomAvatar
    property string  roomName
    property string  roomType

    property color backgroundColor: "#EBEDEE"
    property color separatorColor: "#DDE0DF"
    property color offlineColor: "#FF645F"
    property color onlineColor: "#5ABE50"
    property color presenceTextColor: "#5B5B5B"

    anchors.margins: 10

    Image{
        anchors.verticalCenter:parent.verticalCenter
        id:imageRoomListItemRoomAvatar
        width: parent.height
        height: parent.height
        //source: "image://imageProvider/"+avatar
        source: "image://async/"+roomAvatar
    }

    Text {
        anchors.left: imageRoomListItemRoomAvatar.right
        id:textRoomListItemRoomName
        anchors.verticalCenter:parent.verticalCenter
        text: qsTr(roomName)
        font.bold: true
        font.pixelSize: 25
    }

    // 分割线
    Rectangle {
        id: rectangleRoomListItemSeparatorLine
        width: parent.width
        height: 1
        color: separatorColor
        anchors.bottom: parent.bottom
    }
}
