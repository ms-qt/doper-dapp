import QtQuick 2.0
import QtGraphicalEffects 1.0


import MessageListModel 1.0
import RoomListModel 1.0


Rectangle {
    property color background: "#EBEDEE"
    property color highlightHover: "#DDE0DF"
    property color highlightSelection: "#8D8E8E"

    color: background
    clip: true


    MessageListModel{
        id:messageListModelNotificationMessageList
    }

    RoomListModel{
        id:roomlistModelNotificationMessageList
    }


    ListView {
        id: listViewNotificationMessageList
        anchors.fill: parent
        anchors.topMargin: 5

        opacity: 1
        boundsBehavior: Flickable.DragAndOvershootBounds
        maximumFlickVelocity: 2500
        snapMode: ListView.SnapToItem

        model:  messageListModelNotificationMessageList
        delegate: NotificationMessageListItem {

            roomName: roomlistModelNotificationMessageList.getRoomName(_room_id)
            //roomAvatar: roomlistModelNotificationMessageList.getRoomAvatar(_room_id)
            //lasterMessage: messageListModelNotificationMessageList.getLasterMessageText(_room_id).textContent
            //online: _room_type=='_p2p' ? true : false
            //time : Qt.formatDateTime(new Date(messageListModelNotificationMessageList.getLasterMessageText(_room_id).time), "hh:mm")
            //roomType:_room_type
            width: listViewNotificationMessageList.width
            height: 85
            color: listViewNotificationMessageList.currentIndex === index ? "transparent" : (mouseAreaNotificationMessageList.containsMouse ? highlightHover : background)
            backgroundColor: listViewNotificationMessageList.currentIndex === index ? "transparent" : (mouseAreaNotificationMessageList.containsMouse ? highlightHover : background)
            separatorColor: listViewNotificationMessageList.currentIndex === index ? "transparent" : highlightHover
            smooth: mouseAreaNotificationMessageList.containsMouse

            MouseArea {
                id: mouseAreaNotificationMessageList
                anchors.left: parent.left
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    listViewNotificationMessageList.currentIndex = index
                }
                onDoubleClicked: {

                }
            }
        }

        highlight:
            Rectangle {
            color: highlightSelection
            radius: 3
            anchors.fill: listViewNotificationMessageList.currentItem
        }
        highlightFollowsCurrentItem: true
        highlightRangeMode: ListView.NoHighlightRange
    }
}
