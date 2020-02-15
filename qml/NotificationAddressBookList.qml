import QtQuick 2.0
import QtGraphicalEffects 1.0

import UserModel 1.0

Rectangle {
    property color background: "#EBEDEE"
    property color highlightHover: "#DDE0DF"
    property color highlightSelection: "#8D8E8E"

    color: background
    clip: true





    UserModel{
        id:userModelNotificationAddressBookList
    }




    ListView {

        id: listViewNotificationAddressBookList
        anchors.fill: parent
        anchors.topMargin: 5

        opacity: 1
        boundsBehavior: Flickable.DragAndOvershootBounds
        maximumFlickVelocity: 2500
        snapMode: ListView.SnapToItem

        model:  userModelNotificationAddressBookList
        delegate: NotificationAddressBookListItem {
            name:_name
            avatar: _avatar
            width: listViewNotificationAddressBookList.width
            height: 85
            color: listViewNotificationAddressBookList.currentIndex === index ? "transparent" : (mouseAreaNotificationAddressBookList.containsMouse ? highlightHover : background)
            backgroundColor: listViewNotificationAddressBookList.currentIndex === index ? "transparent" : (mouseAreaNotificationAddressBookList.containsMouse ? highlightHover : background)
            separatorColor: listViewNotificationAddressBookList.currentIndex === index ? "transparent" : highlightHover
            smooth: mouseAreaNotificationAddressBookList.containsMouse

            MouseArea {
                id: mouseAreaNotificationAddressBookList
                anchors.left: parent.left
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    listViewNotificationAddressBookList.currentIndex = index

                }

                onDoubleClicked: {


                }
            }
        }

        highlight:
            Rectangle {
            color: highlightSelection
            radius: 3
            anchors.fill: listViewNotificationAddressBookList.currentItem
        }
        highlightFollowsCurrentItem: true
        highlightRangeMode: ListView.NoHighlightRange
    }
}
