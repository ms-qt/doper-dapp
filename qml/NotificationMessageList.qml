import QtQuick 2.0
import QtGraphicalEffects 1.0


Rectangle {
    property color background: "#EBEDEE"
    property color highlightHover: "#DDE0DF"
    property color highlightSelection: "#8D8E8E"

    color: background
    clip: true

    ListView {
        id: listViewNotificationMessageList
        anchors.fill: parent
        anchors.topMargin: 5

        opacity: 1
        boundsBehavior: Flickable.DragAndOvershootBounds
        maximumFlickVelocity: 2500
        snapMode: ListView.SnapToItem

        model:  messageListModel
        delegate: NotificationMessageListItem {

            roomName: roomListModel.getRoomName(_room_id)
            roomAvatar: roomListModel.getRoomAvatar(_room_id)
            lasterMessage: messageListModel.getLasterMessageText(_room_id).textContent
            online: _room_type=='_p2p' ? true : false
            time : Qt.formatDateTime(new Date(messageListModel.getLasterMessageText(_room_id).time), "hh:mm")
            roomType:_room_type
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
                    messageListModel.enterRoom(_room_id)
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
