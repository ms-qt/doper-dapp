import QtQuick 2.0

// 标题栏

Item {
    width: parent.width
    height: parent.height

    Rectangle{
        id:rectangleLoginTitleClose
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
                loginWindow.close()
            }
            hoverEnabled: true
            onEntered: {
                rectangleLoginTitleClose.color="#ff0000"

            }
            onExited: {
                rectangleLoginTitleClose.color="#ECF5FF"
            }
        }
    }
}
