import QtQuick 2.0
import QtGraphicalEffects 1.0

import Toou2D 1.0

Rectangle {
    property color background: "#EBEDEE"
    property color highlightHover: "#DDE0DF"
    property color highlightSelection: "#8D8E8E"

    color: background
    clip: true

    ListView {
        id: listViewMainHomeLeftMenu
        anchors.fill: parent
        anchors.topMargin: 5
        opacity: 1
        boundsBehavior: Flickable.DragAndOvershootBounds
        maximumFlickVelocity: 2500
        snapMode: ListView.SnapToItem

        model: pluginModel

        delegate: Item {
            width: listViewMainHomeLeftMenu.width
            height: listViewMainHomeLeftMenu.width

            TImage{
                anchors.top: parent.top
                id:imageIcon
                width: parent.width/2
                height: parent.width/2
                source: model.iconLocal
                anchors.centerIn: parent
                anchors.topMargin: -20
            }

            TLabel{
                anchors.topMargin: 10
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: imageIcon.bottom
                id:labelName
                text:model.name
                font.pixelSize: 10
            }


            //            color: listViewMainHomeLeftMenu.currentIndex === index ? "transparent" : (mouseAreaMainHomeLeftMenu.containsMouse ? highlightHover : background)
            //            backgroundColor: listViewMainHomeLeftMenu.currentIndex === index ? "transparent" : (mouseAreaMainHomeLeftMenu.containsMouse ? highlightHover : background)
            //            separatorColor: listViewMainHomeLeftMenu.currentIndex === index ? "transparent" : highlightHover
            smooth: mouseAreaMainHomeLeftMenu.containsMouse

            MouseArea {
                id: mouseAreaMainHomeLeftMenu
                anchors.left: parent.left
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    listViewMainHomeLeftMenu.currentIndex = index
                }

                onDoubleClicked: {

                }
            }
        }

        highlight:
            Rectangle {
            color: highlightSelection
            radius: 3
            anchors.fill: listViewMainHomeLeftMenu.currentItem
        }
        highlightFollowsCurrentItem: true
        highlightRangeMode: ListView.NoHighlightRange
    }
}
