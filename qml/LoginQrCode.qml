import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import Qt.labs.platform 1.1
import QtQuick.Layouts 1.3

Item {
    width:   parent.width
    height:   parent.height
    Text {
        visible: false
        objectName: "textLoginObject"
        id: textLogin
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr("登录")
        font.pixelSize: 24
        MouseArea {
            anchors.fill: parent
            onClicked: {
                itemMainRoot.onLoginSuccess()
            }
        }
    }

    Image {
        objectName: "imageLoginQrCodeObject"
        id: imageQrCode
        width: parent.width/2
        height: parent.width/2
        anchors.top: textLogin.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        cache: false
        source: "image://imageQrCode/login"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.log("Login.qml : 刷新二维码")
                imageQrCode.source = ""
                imageQrCode.source = "image://imageQrCode/login"
            }
        }

        BaseLoading {
            visible: true
            objectName: "loadingQrCodeObject"
            id: loading
            anchors.centerIn: parent
            width: parent.width
            height: parent.height

            function show() {
                console.log("show -")
                loading.visible = true;
            }

            function hide() {
                console.log("hide -")
                loading.visible = false;
            }
        }
    }

    Text {
        id: textHint
        objectName: "textHintObject"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: imageQrCode.bottom
        text: qsTr("请打开APP点击右上角的扫一扫登录")
        font.pixelSize: 12
        anchors.margins: 50

        function setText(text) {
            textHint.text = text;
        }
    }

    Button{
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: textHint.bottom
        objectName: "buttonCancelLogin"
        id:buttonCancelLogin
        anchors.topMargin: 50
        Layout.margins: 10
        text: "返回"
        onClicked: {
            flipableLoginHome.flipped = !flipableLoginHome.flipped
            // 取消登录
        }
    }
}
