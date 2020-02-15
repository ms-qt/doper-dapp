import QtQuick 2.0
import QtGraphicalEffects 1.0

Rectangle {

    // 房间名称
    property string roomName
    // 头像
    property string roomAvatar
    // 最后一条消息
    property string lasterMessage
    // 时间
    property string time
    // 是否在线
    property bool online
    // 房间类型
    property string roomType


    property color backgroundColor: "#EBEDEE"
    property color separatorColor: "#DDE0DF"
    property color offlineColor: "#FF645F"
    property color onlineColor: "#5ABE50"
    property color presenceTextColor: "#5B5B5B"


    color: background


    Item {
        id: avatarItem
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: 12
        height: parent.height - 14
        width: height

        Image {
            id: avatarImage
            width: parent.width;  height: parent.height
            sourceSize: Qt.size(parent.width, parent.height)
            smooth: true
            visible: false
            asynchronous: true
            //source: roomAvatar
            source: "image://async/"+roomAvatar
        }

        Rectangle {
            id: mask

            width: parent.width;  height: parent.height
            radius: parent.height/2
            smooth: true
            visible: false
        }

        OpacityMask {
            anchors.fill: avatarImage
            source: avatarImage
            maskSource: mask
        }
    }

    Item {
        visible: roomType=='_p2p' ? true : false
        width: 12;  height: width
        anchors.right: avatarItem.right
        anchors.bottom: avatarItem.bottom
        Rectangle {
            width: parent.width;  height: width
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            radius: width/2
            color: backgroundColor
        }
        Rectangle {
            width: parent.width-4;  height: width
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            radius: width/2
            color: online ? onlineColor : offlineColor
        }
    }

    Item {
        id: contactText
        height: parent.height
        anchors.left: avatarItem.right
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: 12

        // 房间名称
        Text {
            id: contactNameText
            width: parent.width
            height: parent.height/2 - 4
            anchors.top: parent.top
            anchors.topMargin: 2
            verticalAlignment: Text.AlignVCenter
            text: roomName
        }
        // 消息
        Text {
            id: contactPresenceText
            width: parent.width;  height: parent.height/2 - 8
            anchors.top: contactNameText.bottom
            verticalAlignment: Text.AlignVCenter
            font.pointSize: contactNameText.font.pointSize-1
            color: presenceTextColor
            text: lasterMessage
        }

        Text {
            anchors.bottom:  parent.bottom
            anchors.right:   parent.right
            anchors.rightMargin: 10
            anchors.bottomMargin: 5
            text: time
        }

        // 分割线
        Rectangle {
            id: separatorLine
            width: parent.width
            height: 1
            color: separatorColor
            anchors.bottom: parent.bottom
        }
    }
}
