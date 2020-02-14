
import QtQuick 2.9
import QtGraphicalEffects 1.0

// 加载中 转圈

Rectangle
{
    id:rectangleLoadingRoot
    width: parent.width
    height: parent.height
    //    radius: width / 8
    color:"#99515151"


    Image
    {
        id:imageLoading
        anchors.centerIn: parent
        width: parent.width/8
        height:parent.width/8
        source: "qrc:/images/img_loading.png"
        RotationAnimation on rotation {
            from: 0
            to: 30
            duration: 150
            loops: Animation.Infinite
        }
    }

    Text{
        anchors.horizontalCenter: parent.horizontalCenter
        color: "#ffffff"
        text: "加载中..."
        anchors.top: imageLoading.bottom
        anchors.topMargin: 10
        font.bold: true
    }
}

