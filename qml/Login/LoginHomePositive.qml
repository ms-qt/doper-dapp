
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
    id:itemLoginHomeFront
    width:   parent.width
    height:   parent.height
    //Logo
    Image {
        id: imageLoginHomeLogo
        source: "qrc:/images/org_ms_image_dev.png"
        width: parent.width/4
        height: parent.width/4
        anchors {
            top: parent.top
            horizontalCenter: parent.horizontalCenter
            topMargin: parent.height/25
        }
    }

    // 错误提示
    Text {
        objectName: "textHintObj"
        id: textHint
        text: ""
        anchors {
            top: imageLoginHomeLogo.bottom
            horizontalCenter: parent.horizontalCenter
            topMargin: parent.height/25
        }
        function changeHintText(msg) {
            textHint.text = msg
        }
    }

    ColumnLayout {
        width: parent.width/5*4
        objectName: "columnLayoutLoginHomeFromInfo"
        anchors {
            top: textHint.bottom
            topMargin: parent.height/25
            horizontalCenter: parent.horizontalCenter
        }
        function setUsername(username)
        {
            loginHomeField.usernametext=username
        }
        function setPassword(password)
        {
            loginHomeField.passwordtext=password
        }
        function savePassword(save)
        {
            console.log("savePassword : "+save);
            checkBoxSavePassword.checked=save
        }
        function autoLogin(auto)
        {
            console.log("autoLogin : "+auto);
            checkBoxAutoLogin.checked=auto
        }

        LoginHomeField {
            objectName: "LoginHomeField"
            id: loginHomeField
            implicitWidth: parent.width
            implicitHeight:  120
        }

        RowLayout {
            width: parent.width
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

        LoginHomeButton {
            id: loginButton
            implicitWidth: parent.width
            implicitHeight: 50

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {

                    if (loginHomeField.usernametext.trim().length == 0) {
                        textHint.text = "请输入账号"
                        TToast.showError("请输入账号");
                        return
                    }
                    if (loginHomeField.usernametext.trim().length < 6) {
                        textHint.text = "请输合法的账号"
                        TToast.showError("请输合法的账号");
                        return
                    }

                    if (loginHomeField.passwordtext.trim().length == 0) {
                        textHint.text = "请输入密码"
                        TToast.showError("请输入密码");
                        return
                    }

                    if (loginHomeField.passwordtext.trim().length < 6) {
                        textHint.text = "请输入合法的密码"
                        TToast.showError("请输入合法的密码");
                        return
                    }
                    imModel.login(loginHomeField.usernametext.trim(),
                                  loginHomeField.passwordtext.trim(),
                                  checkBoxSavePassword.checkState,
                                  checkBoxAutoLogin.checkState
                                  )
                }
                onEntered: {
                    loginButton.color = "#3CC3F5"
                }
                onExited: {
                    loginButton.color = "#00A3FF"
                }
            }
        }
    }

    RowLayout {
        anchors {
            left: itemLoginHomeFront.left
            bottom: itemLoginHomeFront.bottom
            leftMargin: parent.height/25
            bottomMargin: parent.height/25
        }
        Item {
            width: 100
            height: 20
            Text {
                id: textRegisterAccount
                text: qsTr("注册账号")
                color: "#00A3FF"
                font.pixelSize: 15
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
            width: 100
            height: 20
            Text {
                id: textFindPassword
                text: qsTr("找回密码")
                color: "#00A3FF"
                font.pixelSize: 15
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
    }

    ImageBackColor {
        id: imageQr
        source: "qrc:/images/img_qrcode.png"
        width:30
        height:30
        anchors {

            rightMargin: parent.height/25
            bottomMargin: parent.height/25
            right: parent.right
            bottom: parent.bottom

        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                imageQr.visibleRec = true
            }
            onExited: {
                imageQr.visibleRec = false
            }
            onClicked: {
                console.log("qrcode image")
                flipableLoginHome.flipped = !flipableLoginHome.flipped
            }
        }
    }


    // 用户名输入处理
    Connections {
        target: loginHomeField.username
        onUsernameChange: {
            console.log(loginHomeField.usernametext)
        }
    }
    // 密码输入处理
    Connections {
        target: loginHomeField.password
        onPasswordChange: {
            console.log(loginHomeField.passwordtext)
        }
    }
}
