import QtQuick 2.0

import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

// 用户名密码输入框
Rectangle {
    id:rectangleLoginHomeField
    radius: 4
    width: parent.width
    height: parent.height
    border.color: "#bdbdbd"
    border.width: 1

    property alias password: password


    property alias passwordtext: password.text

    ColumnLayout{
        spacing: 0

        TextField{
            id:password
            font.pixelSize: 22
            font.bold: true
            font.family: "微软雅黑"
            signal passwordChange(string passwordstr)
            placeholderText: qsTr("密码")

            echoMode: TextInput.Password

            background: Rectangle{
                implicitWidth: rectangleLoginHomeField.width
                implicitHeight: rectangleLoginHomeField.height/2
                opacity: 0
            }
            validator: RegExpValidator {
                regExp: /^([a-zA-Z0-9]+[_|\_|\.]?)*[a-zA-Z0-9]+@([a-zA-Z0-9]+[_|\_|\.]?)*[a-zA-Z0-9]+\.[a-zA-Z]{2,3}$/
            }
            onTextChanged: password.passwordChange(password.text)
        }
    }
}
