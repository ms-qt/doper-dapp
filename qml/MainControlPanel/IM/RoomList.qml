import QtQuick 2.0

import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

import "qrc:/qml/Base"
import "qrc:/qml/Base/Button"
import "qrc:/qml/Base/PopupFrame"
import "qrc:/qml/Emoji"


// 房间列表

Rectangle {

    property color background: "#EBEDEE"
    property color highlightHover: "#DDE0DF"
    property color highlightSelection: "#8D8E8E"


    width: parent.width
    height: parent.height

    // 背景
    Image {
        width: parent.width
        height: parent.height
        source: "qrc:/images/img_back1.jpg"
    }
    ListView{
        width: parent.width
        height: parent.height
        id:listViewRoomList
        anchors.fill: parent
        anchors.topMargin: 5
        opacity: 1
        boundsBehavior: Flickable.DragAndOvershootBounds
        maximumFlickVelocity: 2500
        snapMode: ListView.SnapToItem
        model: messageListModel
        delegate:RoomListItem{
            width: parent.width
            height: 85
            roomName: roomListModel.getRoomName(_room_id)
            roomType: _room_type
            roomAvatar:roomListModel.getRoomAvatar(_room_id)

            MouseArea {
                id: mouseAreaMemberList
                anchors.left: parent.left
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    listViewRoomList.currentIndex = index

                }
                onDoubleClicked: {

                }
            }
        }

        highlight:
            Rectangle {
            color: highlightSelection
            radius: 3
            anchors.fill: listViewRoomList.currentItem
        }
        highlightFollowsCurrentItem: true
        highlightRangeMode: ListView.NoHighlightRange
    }
}
