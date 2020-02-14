import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Item {
    anchors.fill: parent
    property bool loginStatus: false
    Image {
        id: image
        anchors.fill: parent
        source: "qrc:/backdrop.jpg"
        fillMode: Image.PreserveAspectFit

        Rectangle {
            id: rectangle
            x: 177
            y: 87
            width: 220
            height: 150
            color: "#f0d8d8"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            Row {
                id: row
                anchors.fill: parent
                z: 1
            }

            Label {
                id: label
                x: 82
                y: 8
                width: 57
                height: 29
                text: qsTr("登录")
                font.pointSize: 18
            }

            TextInput {
                id: username
                y: 43
                height: 20
                text: qsTr("账号")
                anchors.right: parent.right
                anchors.rightMargin: 40
                anchors.left: parent.left
                anchors.leftMargin: 40
                horizontalAlignment: Text.AlignLeft
                font.pixelSize: 12
            }

            TextInput {
                id: password
                y: 75
                height: 20
                text: qsTr("密码")
                anchors.right: parent.right
                anchors.rightMargin: 40
                anchors.left: parent.left
                anchors.leftMargin: 40
                font.pixelSize: 12
            }

            Button {
                id: button
                x: 70
                y: 116
                width: 60
                height: 20
                text: qsTr("登录")
                onClicked: {
                    client.login(username.text,password.text)
                    loginStatus = true
                }
            }
        }
    }

}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:3;anchors_height:150;anchors_width:220;anchors_x:0;anchors_y:11}
D{i:4;anchors_height:40;anchors_width:60;anchors_x:68;anchors_y:21}D{i:5;anchors_height:20;anchors_width:80;anchors_x:70;anchors_y:43}
D{i:6;anchors_width:80;anchors_x:70}D{i:1;anchors_x:176;anchors_y:126}
}
 ##^##*/
