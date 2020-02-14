
import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtGraphicalEffects 1.0


// 签名

Item {
    width: parent.width
    height: parent.height
    visible: true

    property string signatureText


    function subEditingFinished()
    {
        if (textFieldback.visible !== true) return;
        textFieldback.visible = false
        textField.focus = false
        textMetrics.text = textField.text
        textField.text = textMetrics.elidedText
        console.debug("textMetrics.elidedText: ", textMetrics.elidedText);
        console.debug("textMetrics.text: ", textMetrics.text);
        console.debug("textField.text: ", textField.text);
        userModel.setSignature(certificateBean.user_id,textField.text);
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            subEditingFinished();

        }
    }

    TextMetrics {
        id: textMetrics
        elide: Text.ElideRight
        elideWidth: textField.width - 12
        text: qsTr(signatureText)
    }

    TextField{
        id: textField
        text: textMetrics.elidedText
        height: parent.height
        width: parent.width
        anchors.centerIn: parent
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment:Text.AlignLeft
        selectByMouse: true

        background: Rectangle {
            id: textFieldback
            implicitWidth: 120
            implicitHeight: 32
            border.color:  "#CCCCCC"
            visible: false
        }

        onPressed:{
            textFieldback.visible = true
            textField.text = textMetrics.text
            console.debug("textMetrics.text: ", textMetrics.text);
        }

        onEditingFinished :{
            subEditingFinished();
        }
    }
}
