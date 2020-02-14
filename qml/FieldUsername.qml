import QtQuick 2.0

import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

// 用户名密码输入框
Rectangle {
    id:rectangleLoginHomeField
    radius: 2
    width: parent.width
    height: parent.height
    border.color: "#bdbdbd"
    border.width: 1

    property alias username: username

    property alias usernametext: username.text

    ColumnLayout{
        width: parent.width
        height: parent.height
        spacing: 0
        TextField{
            width: parent.width
            height: parent.height
            id:username
            font.pixelSize: 22
            font.bold: true
            font.family: "微软雅黑"
            placeholderText: qsTr("账号/手机/邮箱")

            signal usernameChange(string usernamestr)
            background: Rectangle{
                implicitWidth: rectangleLoginHomeField.width
                implicitHeight: rectangleLoginHomeField.height/2 //此时用width 和height 输入有问题？？？
                opacity: 0 //为0 是看不见
            }
            validator: RegExpValidator {
                regExp: /^([a-zA-Z0-9]+[_|\_|\.]?)*[a-zA-Z0-9]+@([a-zA-Z0-9]+[_|\_|\.]?)*[a-zA-Z0-9]+\.[a-zA-Z]{2,3}$/
            }

            onTextChanged: username.usernameChange(username.text)
        }
    }
}
