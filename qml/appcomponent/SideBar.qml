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
import "../BasicComponent"
Item {
    property int currentIndex : 1

    Rectangle {
        id: rectangle
        color: "#463e37"
        anchors.fill: parent

        TImageBtn{
            imageUrl: "qrc:/images/msg.png"
            id: chat
            x: 288
            y: -164
            width: 50
            height: 50
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.top: header.bottom
            anchors.topMargin: 30
            onClicked: currentIndex = 1
        }

//        Button {
//            id: plugins
//            x: 288
//            y: -94
//            width: 50
//            height: 50
//            text: qsTr("插件")
//            anchors.top: chat.bottom
//            anchors.topMargin: 20
//            anchors.left: parent.left
//            anchors.leftMargin: 5
//            onClicked: currentIndex = 2
//        }

        TImageBtn{
            imageUrl: "qrc:/images/plugin.png"
            id: plugins
            x: 288
            y: -94
            width: 50
            height: 50
            anchors.top: chat.bottom
            anchors.topMargin: 20
            anchors.left: parent.left
            anchors.leftMargin: 5
            onClicked: currentIndex = 2
        }

//        Button {
//            id: chat
//            x: 288
//            y: -164
//            width: 50
//            height: 50
//            text: qsTr("聊天")
//            anchors.left: parent.left
//            anchors.leftMargin: 5
//            anchors.top: header.bottom
//            anchors.topMargin: 30
//            onClicked: currentIndex = 1
//        }

        Image {
            id: header
            x: 288
            y: -244
            width: 50
            height: 50
            anchors.top: parent.top
            anchors.topMargin: 20
            anchors.left: parent.left
            anchors.leftMargin: 5
            source: "qrc:/images/header.jpg"
            fillMode: Image.PreserveAspectFit

        }

//        Button {
//            id: pwa
//            width: 50
//            height: 50
//            text: qsTr("pwa")
//            anchors.left: parent.left
//            anchors.leftMargin: 5
//            anchors.top: plugins.bottom
//            anchors.topMargin: 20
//            onClicked: currentIndex = 3
//        }

        TImageBtn{
            imageUrl: "qrc:/images/pwa.png"
            id: pwa
            width: 50
            height: 50
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.top: plugins.bottom
            anchors.topMargin: 20
            onClicked: currentIndex = 3
        }

        TImageBtn{
            imageUrl: "qrc:/images/setting.png"
            id: setting
            width: 50
            height: 50
            anchors.bottom:  parent.bottom
            anchors.bottomMargin:  40
            anchors.left: parent.left
            anchors.leftMargin: 5
            onClicked: currentIndex = currentIndex
        }
    }

}



/*##^## Designer {
    D{i:2;anchors_x:"-14";anchors_y:241}D{i:3;anchors_x:8;anchors_y:126}D{i:4;anchors_x:0;anchors_y:17}
D{i:5;anchors_x:-150;anchors_y:267}D{i:1;anchors_height:200;anchors_width:200;anchors_x:"-283";anchors_y:264}
}
 ##^##*/
