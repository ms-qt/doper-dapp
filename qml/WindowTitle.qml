import QtQuick 2.0
import Toou2D 1.0



Item {
    width: parent.width
    height: parent.height
    Rectangle{
        width: parent.width
        height: parent.height
        color: "#ECF5FF"
    }

    // 关闭
    Rectangle{
        id:rectangleWindowTitleClose
        width: 50
        height: 50
        anchors.right: parent.right
        color: "#ECF5FF"

        Image {
            anchors.topMargin: 10
            anchors.rightMargin: 10
            scale: 0.8
            width: 40
            height: 40
            source: "qrc:/images/image_close.png"
            anchors.centerIn: parent
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
               rootWindow.close()
            }

            hoverEnabled: true
            onEntered: {
                rectangleWindowTitleClose.color="#ff0000"

            }
            onExited: {
                rectangleWindowTitleClose.color="#ECF5FF"
            }
        }
    }

    // 最大化
    property bool max: false

    Rectangle{
        id:rectangleWindowTitleMaximize
        width: 50
        height: 50
        anchors.right: rectangleWindowTitleClose.left
        color: "#ECF5FF"

        Image {
            anchors.topMargin: 10
            anchors.rightMargin: 10
            scale: 0.8
            width: 40
            height: 40
            source: max ?"qrc:/images/image_maximize_1.png"  :  "qrc:/images/image_maximize_0.png"
            anchors.centerIn: parent
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                if(max)
                {
                    rootWindow.showNormal()
                    max=false
                }
                else
                {
                    rootWindow.showMaximized()
                    max=true
                }
            }
            hoverEnabled: true
            onEntered: {
                rectangleWindowTitleMaximize.color="#ff0000"

            }
            onExited: {
                rectangleWindowTitleMaximize.color="#ECF5FF"
            }
        }
    }



    // 最小化

    Rectangle{
        id:rectangleWindowTitleMinimize
        width: 50
        height: 50
        anchors.right: rectangleWindowTitleMaximize.left
        color: "#ECF5FF"

        Image {
            anchors.topMargin: 10
            anchors.rightMargin: 10
            scale: 0.8
            width: 40
            height: 40
            source: "qrc:/images/image_minimize.png"
            anchors.centerIn: parent
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                rootWindow.    showMinimized()
            }

            hoverEnabled: true
            onEntered: {
                rectangleWindowTitleMinimize.color="#ff0000"

            }
            onExited: {
                rectangleWindowTitleMinimize.color="#ECF5FF"
            }
        }
    }

    // 关于
    Rectangle{
        id:rectangleWindowTitleAbout
        width: 50
        height: 50
        anchors.right: rectangleWindowTitleMinimize.left
        color: "#ECF5FF"

        Image {
            anchors.topMargin: 10
            anchors.rightMargin: 10
            scale: 0.8
            width: 40
            height: 40
            source: "qrc:/images/image_about.png"
            anchors.centerIn: parent
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                about.open()

            }
            hoverEnabled: true
            onEntered: {
                rectangleWindowTitleAbout.color="#ff0000"

            }
            onExited: {
                rectangleWindowTitleAbout.color="#ECF5FF"
            }
        }
    }
}
