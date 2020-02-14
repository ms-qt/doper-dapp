import QtQuick 2.0

Item {

    Rectangle{
        width: parent.width
        height: parent.height
        color: "#ECF5FF"
    }


    // 关闭
    Rectangle{
        id:rectangleMainPanelTitleClose
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
                mainWindow.close();
            }
            hoverEnabled: true
            onEntered: {
                rectangleMainPanelTitleClose.color="#ff0000"

            }
            onExited: {
                rectangleMainPanelTitleClose.color="#ECF5FF"
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
        id:rectangleMainPanelTitleMinimize
        width: 50
        height: 50
        anchors.right: rectangleMainPanelTitleMaximize.left
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
                mainWindow.showMinimized()
            }
            hoverEnabled: true
            onEntered: {
                rectangleMainPanelTitleMinimize.color="#ff0000"
            }
            onExited: {
                rectangleMainPanelTitleMinimize.color="#ECF5FF"
            }
        }
    }
}
