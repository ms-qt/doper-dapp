/*!
 *@file BaseTabBar.qml
 *@brief 自定义TabBar
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/


import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import "qrc:/qml/BasicComponent"
// 主面板左侧菜单

Item {
    id:itemLeftMenuSideBarRoot
    property int currentIndex : 1

    width: parent.width
    height: parent.height

    property int imageItemWidth : 60
    property int imageItemHeigth : 60

    property int iconwidth: 35
    property int iconheight: 35
    property int fontSize: 18


    property color background: "#EBEDEE"
    property color highlightHover: "#DDE0DF"
    property color highlightSelection: "#8D8E8E"



    Rectangle {
        id: rectangle
        width: parent.width
        height: parent.height
        color: "#463e37"
        anchors.fill: parent
        anchors.horizontalCenter: parent.horizontalCenter

        ListView {
            id: listViewLeftMenuSideBar
            anchors.top: imageLeftMenuSideBarAvatar.bottom
            anchors.bottom: columnLeftMenuSideBarPluginManager.top
            width: parent.width
            height: parent.height
            anchors.bottomMargin: 15
            anchors.topMargin: 15
            opacity: 1
            boundsBehavior: Flickable.DragAndOvershootBounds
            maximumFlickVelocity: 2500
            snapMode: ListView.SnapToItem

            model: homeLeftMenuModel

            delegate:Item {

                anchors.horizontalCenter: parent.horizontalCenter
                width: 100
                height: 100
                Column{
                    Layout.margins: 30
                    anchors.centerIn: parent
                    Image {
                        width: iconwidth
                        height: iconheight
                        anchors.margins: 10
                        anchors.horizontalCenter: parent.horizontalCenter
                        source: model.iconUrl
                    }
                    Text{
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: qsTr(model.name)
                        font: font.pixelSize=fontSize
                    }

                    MouseArea {
                        id: mouseAreaMessageList
                        anchors.fill: parent
                        hoverEnabled: true
                        onClicked: {

                            console.log(index)

                            listViewLeftMenuSideBar.currentIndex = index
                            currentIndex = index
                        }

                        onDoubleClicked: {

                        }
                    }
                }
            }

            highlight:
                Rectangle {
                color: highlightSelection
                radius: 3
                anchors.fill: listViewLeftMenuSideBar.currentItem
            }
            highlightFollowsCurrentItem: true
            highlightRangeMode: ListView.NoHighlightRange
        }


        // 头像
        Image {
            id: imageLeftMenuSideBarAvatar
            width:  imageItemWidth
            height: imageItemHeigth
            anchors.top: parent.top
            anchors.topMargin: 20
            anchors.left: parent.left
            anchors.leftMargin: 5
            source: "qrc:/images/header.jpg"
            fillMode: Image.PreserveAspectFit
            anchors.horizontalCenter: parent.horizontalCenter


            MouseArea{
                anchors.fill: parent
                onClicked: currentIndex = -1
            }
        }


        // 插件管理
        Column{
            width: parent.width
            height: iconheight
            id:columnLeftMenuSideBarPluginManager
            anchors.bottom:  parent.bottom
            anchors.bottomMargin:  40
            anchors.left: parent.left
            anchors.leftMargin: 5
            Layout.margins: 30

            Image {

                width: iconwidth
                height: iconheight
                anchors.margins: 10
                anchors.horizontalCenter: parent.horizontalCenter
                source: "qrc:/images/img_plugin_manager.png"
            }
            Text{
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr(model.name)
                font: font.pixelSize=fontSize
            }

            MouseArea{
                anchors.fill: parent
                onClicked: currentIndex = -2
            }
        }
    }
}
