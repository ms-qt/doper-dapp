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

// 登录正面



Item {
    width: parent.width
    height: parent.height
    id:itemLoginHomePositiveFrom


    //Logo
    Image {
        id: imageLoginHomeLogo
        source: "qrc:/images/org_ms_image_dev.png"
        width: 80
        height: 80
        anchors.top: parent.top
        anchors.topMargin: 50
        anchors.horizontalCenter: parent.horizontalCenter
    }

    FieldUsername{
        anchors.top: imageLoginHomeLogo.bottom
        anchors.topMargin: 30
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width/5*4
        height: 60
        id:fieldUsername
    }



    FieldPassword{
        anchors.topMargin: 20
        anchors.top: fieldUsername.bottom
        id:fieldPassword
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width/5*4
        height: 60
    }


    RowLayout {
        id:rowLayoutCheckBoxFrom
        anchors.top: fieldPassword.bottom
        anchors.topMargin: 15
        width: parent.width/5*4
        anchors.horizontalCenter: parent.horizontalCenter
        objectName: "CheckBoxSavePasswordAutoLogin"
        CheckBox {
            id: checkBoxSavePassword
            scale: 1
            text: "记住密码"
            onCheckStateChanged: {
                if(!checkBoxSavePassword.checked){
                    checkBoxAutoLogin.checked=false
                }
            }
        }
        CheckBox {
            id: checkBoxAutoLogin
            scale: 1
            text: "自动登录"
            onCheckStateChanged: {
                if(checkBoxAutoLogin.checked)
                {
                    checkBoxSavePassword.checked=true
                }
            }
        }
    }

    LoginButton {
        anchors.top:rowLayoutCheckBoxFrom.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 15
        id: loginButton
        width:  parent.width/5*4
        height:  60

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onClicked: {

                if (fieldUsername.usernametext.trim().length == 0) {

                    TToast.showError("请输入账号");
                    return
                }
                if (fieldUsername.usernametext.trim().length < 6) {

                    TToast.showError("请输合法的账号");
                    return
                }

                if (fieldPassword.passwordtext.trim().length == 0) {

                    TToast.showError("请输入密码");
                    return
                }

                if (fieldPassword.passwordtext.trim().length < 6) {

                    TToast.showError("请输入合法的密码");
                    return
                }

                baseLoading.show()

            }
            onEntered: {
                loginButton.color = "#3CC3F5"
            }
            onExited: {
                loginButton.color = "#00A3FF"
            }
        }
    }



    Item {
        id:itemLoginHomePositiveRegisterAccount
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 50
        anchors.leftMargin: 50
        Text {
            id: textRegisterAccount
            text: qsTr("注册账号")
            color: "#00A3FF"
            font.pixelSize: 18
            MouseArea {
                hoverEnabled: true
                anchors.fill: parent
                onClicked: Qt.openUrlExternally(
                               "https://www.baidu.com/")
                onEntered: {
                    textRegisterAccount.color = "#3CC3F5"
                }
                onExited: {
                    textRegisterAccount.color = "#00A3FF"
                }
            }
        }
    }
    Item {
        anchors.left: itemLoginHomePositiveRegisterAccount.right
        anchors.leftMargin: textRegisterAccount.width+30
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 50
        Text {
            id: textFindPassword
            text: qsTr("找回密码")
            color: "#00A3FF"
            font.pixelSize: 18
            MouseArea {
                hoverEnabled: true
                anchors.fill: parent
                onClicked: Qt.openUrlExternally(
                               "https://www.baidu.com/")
                onEntered: {
                    textFindPassword.color = "#3CC3F5"
                }
                onExited: {
                    textFindPassword.color = "#00A3FF"
                }
            }
        }
    }


    Rectangle{
        width: 50
        height: 50
        id:rectangleLoginHomePositiveQrCode
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.rightMargin: 30
        anchors.bottomMargin: 30
        color: "#ffffff"

        Image {
            width: 40
            height:  40
            anchors.centerIn: parent
            source: "qrc:/images/img_qrcode.png"
        }


        MouseArea{

            anchors.fill: parent
            hoverEnabled: true

            onClicked: {
                flipableLoginHome.flipped=!flipableLoginHome.flipped
            }

            onEntered: {
                rectangleLoginHomePositiveQrCode.color = "#FFDAB9"
            }
            onExited: {
                rectangleLoginHomePositiveQrCode.color = "#ffffff"
            }
        }
    }
}

