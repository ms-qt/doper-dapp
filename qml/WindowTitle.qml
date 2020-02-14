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
        id:rectangleNotificationPanelHomeTitleClose
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
                notificationWindow.close()
            }

            hoverEnabled: true
            onEntered: {
                rectangleNotificationPanelHomeTitleClose.color="#ff0000"

            }
            onExited: {
                rectangleNotificationPanelHomeTitleClose.color="#ECF5FF"
            }
        }
    }



    // 最大化

    property bool max: false
    property int  tw
    property int  th

    Rectangle{
        id:rectangleMainPanelTitleMaximize
        width: 50
        height: 50
        anchors.right: rectangleMainPanelTitleClose.left
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

                tw=mainWindow.width;
                th=mainWindow.height;

                if(max)
                {
                    mainWindow.showNormal()
                    max=false
                }
                else
                {
                    mainWindow.showMaximized()
                    max=true
                }
            }
            hoverEnabled: true
            onEntered: {
                rectangleMainPanelTitleMaximize.color="#ff0000"

            }
            onExited: {
                rectangleMainPanelTitleMaximize.color="#ECF5FF"
            }
        }
    }



    // 最小化

    Rectangle{
        id:rectangleNotificationPanelHomeTitleMinimize
        width: 50
        height: 50
        anchors.right: rectangleNotificationPanelHomeTitleClose.left
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
                notificationWindow.    showMinimized()
            }

            hoverEnabled: true
            onEntered: {
                rectangleNotificationPanelHomeTitleMinimize.color="#ff0000"

            }
            onExited: {
                rectangleNotificationPanelHomeTitleMinimize.color="#ECF5FF"
            }
        }
    }

    // 关闭

    Rectangle{
        id:rectangleNotificationPanelHomeTitleAbout
        width: 50
        height: 50
        anchors.right: rectangleNotificationPanelHomeTitleMinimize.left
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
                aboutNotificationHome.open()

            }
            hoverEnabled: true
            onEntered: {
                rectangleNotificationPanelHomeTitleAbout.color="#ff0000"

            }
            onExited: {
                rectangleNotificationPanelHomeTitleAbout.color="#ECF5FF"
            }
        }
    }
}
