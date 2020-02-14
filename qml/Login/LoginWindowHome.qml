import QtQuick 2.12
import QtQuick.Window 2.12
import QtQml 2.13

import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4

import QtQuick.Controls.Material 2.12
import Qt.labs.platform 1.1
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import Toou2D 1.0
import "qrc:/qml/Base"

import "qrc:/qml"



// 登录页面 可翻转
Item {
    id:itemLoginHomeRoot

    MouseArea { //为窗口添加鼠标事件
        property int xMouse //存储鼠标x坐标
        property int yMouse //存储鼠标y坐标
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton //只处理鼠标左键
        drag.filterChildren: true
        onPressed: { //接收鼠标按下事件
            xMouse = mouse.x
            yMouse = mouse.y
        }
        onPositionChanged: { //鼠标按下后改变位置
            loginWindow.x = loginWindow.x + (mouse.x - xMouse)
            loginWindow.y = loginWindow.y + (mouse.y - yMouse)
        }
    }


    // 背景颜色
    Rectangle{
        width: parent.width
        height: parent.height
        color: "#ECF5FF"
    }

    LoginTitlePage{
        id:loginTitlePageLoginHome
        width: parent.width
        height: 15
    }

    Flipable {
        anchors.top: loginTitlePageLoginHome.bottom
        property bool flipped: false
        id: flipableLoginHome
        clip: true

        width: parent.width
        height: parent.height

        // 正面
        front: LoginHomePositive{
            width: parent.width
            height: parent.height
            anchors.horizontalCenter: parent.horizontalCenter
        }
        // 背面
        back: LoginQRCode {
            width: parent.width
            height: parent.height
            anchors.horizontalCenter: parent.horizontalCenter
        }

        transform: Rotation {
            id: rotation
            origin.x: flipableLoginHome.width / 2
            origin.y: flipableLoginHome.height / 2
            axis.x: 0
            axis.y: 1
            axis.z: 0
            angle: 0
        }

        states: State {
            name: "back"
            PropertyChanges {
                target: rotation
                angle: 180
            }
            when: flipableLoginHome.flipped
        }

        transitions: Transition {
            NumberAnimation {
                target: rotation
                properties: "angle"
                duration: 500
            }
        }

        // 加载中
        Loading{
            visible: false
            objectName: "loadingLoginHomeObject"
            id:loadingLoginHome
            width: parent.width
            height: parent.height
            anchors.centerIn: parent

            Layout.margins: 10
            implicitWidth: 30
            implicitHeight: 30


            function show()
            {
                console.log("loadingLoginHome show")
                loadingLoginHome.visible=true
            }

            function hide()
            {
                loadingLoginHome.visible=false
            }
        }
    }
}



