import QtQuick 2.0
import QtGraphicalEffects 1.0


Rectangle {
    property color background: "#EBEDEE"
    property color highlightHover: "#DDE0DF"
    property color highlightSelection: "#8D8E8E"

    color: background
    clip: true





    ListView {
        id: listViewMemberList
        anchors.fill: parent
        anchors.topMargin: 5

        opacity: 1
        boundsBehavior: Flickable.DragAndOvershootBounds
        maximumFlickVelocity: 2500
        snapMode: ListView.SnapToItem

        model:  userModel
        delegate: NotificationAddressBookListItem {
            name:_name
            avatar: _avatar
            width: listViewMemberList.width
            height: 85
            color: listViewMemberList.currentIndex === index ? "transparent" : (mouseAreaMemberList.containsMouse ? highlightHover : background)
            backgroundColor: listViewMemberList.currentIndex === index ? "transparent" : (mouseAreaMemberList.containsMouse ? highlightHover : background)
            separatorColor: listViewMemberList.currentIndex === index ? "transparent" : highlightHover
            smooth: mouseAreaMemberList.containsMouse

            MouseArea {
                id: mouseAreaMemberList
                anchors.left: parent.left
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    listViewMemberList.currentIndex = index

                }

                onDoubleClicked: {


                }
            }
        }

        highlight:
            Rectangle {
            color: highlightSelection
            radius: 3
            anchors.fill: listViewMemberList.currentItem
        }
        highlightFollowsCurrentItem: true
        highlightRangeMode: ListView.NoHighlightRange
    }
}
