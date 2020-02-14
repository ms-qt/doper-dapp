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


// 登录页面 可翻转
Item {
    id:itemLoginHomeRoot
    width: parent.width
    height: parent.height

    // 背景颜色
    Rectangle{
        width: parent.width
        height: parent.height
        color: "#ECF5FF"
    }

    Flipable {
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
        back: LoginHomeBack {
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
    }
}



