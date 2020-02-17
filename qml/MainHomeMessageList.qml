import QtQuick 2.0
import QtGraphicalEffects 1.0
import Toou2D 1.0


Rectangle {
    property color background: "#EBEDEE"
    property color highlightHover: "#DDE0DF"
    property color highlightSelection: "#8D8E8E"

    color: background
    clip: true

    width: parent.width
    height: parent.height


    signal currentRoom(string roomid,string roomtype);


    ListView {
        currentIndex: 0
        id: listViewMainHomeMessageList
        anchors.fill: parent
        anchors.topMargin: 5

        width: parent.width
        height: parent.height

        opacity: 1
        boundsBehavior: Flickable.DragAndOvershootBounds
        maximumFlickVelocity: 2500
        snapMode: ListView.SnapToItem

        model:  messageListModel

        delegate: MainHomeMessageListItem {

            roomName: roomListModel.getRoomName(_room_id)
            roomAvatar: roomListModel.getRoomAvatar(_room_id)
            lasterMessage: messageListModel.getLasterMessageText(_room_id)._text_content
            online: _room_type=='_p2p' ? true : false
            time : Qt.formatDateTime(new Date(messageListModel.getLasterMessageText(_room_id)._time), "hh:mm")
            roomType:_room_type
            width: listViewMainHomeMessageList.width
            height: 85
            color: listViewMainHomeMessageList.currentIndex === index ? "transparent" : (mouseAreaMainHomeMessageList.containsMouse ? highlightHover : background)
            backgroundColor: listViewMainHomeMessageList.currentIndex === index ? "transparent" : (mouseAreaMainHomeMessageList.containsMouse ? highlightHover : background)
            separatorColor: listViewMainHomeMessageList.currentIndex === index ? "transparent" : highlightHover
            smooth: mouseAreaMainHomeMessageList.containsMouse


            Component.onCompleted: {
                console.log("----------"+_room_id+" "+_room_type)
                if(index==0){
                    currentRoom(_room_id,_room_type)
                }
            }

            MouseArea {
                id: mouseAreaMainHomeMessageList
                anchors.left: parent.left
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    listViewMainHomeMessageList.currentIndex = index
                    currentRoom(_room_id,_room_type)
                }
                onDoubleClicked: {

                }
            }
        }

        highlight:
            Rectangle {
            color: highlightSelection
            radius: 3
            anchors.fill: listViewMainHomeMessageList.currentItem
        }
        highlightFollowsCurrentItem: true
        highlightRangeMode: ListView.NoHighlightRange
    }
}
