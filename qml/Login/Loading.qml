
import QtQuick 2.9
import QtGraphicalEffects 1.0

// 加载中 转圈

Rectangle
{
    id:rect
    width: parent.width
    height: parent.height
    radius: width / 8
    color:"#998a8a8a"

    Image
    {
        anchors.centerIn: parent
        width: parent.width/3
        height:parent.height/3
        source: "qrc:/images/img_loading.png"
        RotationAnimation on rotation {
            from: 0
            to: 360
            duration: 1500
            loops: Animation.Infinite
        }
    }
}
