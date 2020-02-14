import QtQuick 2.0
import QtQuick.Layouts 1.3

// 登录按钮
Rectangle {
    radius: 4
    width: parent.width
    height: parent.height
    color: "#00A3FF"
    RowLayout{
        anchors.centerIn: parent
        Text {
            id: text
            text: qsTr("登 录")
            color: "#ffffff"
            font.pixelSize: 20

        }
    }
}
