import QtQuick 2.0
import QtGraphicalEffects 1.0

Rectangle {

    // 任务名称
    property string taskName
    // 任务优先级
    property string taskPriority


    property color backgroundColor: "#EBEDEE"
    property color separatorColor: "#DDE0DF"

    color: background

    Text {
        id:textTaskName
        text: taskName
        anchors.leftMargin: 15
        anchors.topMargin: 15
        font.bold: true
        font.pixelSize: 25
        anchors.verticalCenter: parent.verticalCenter
    }


    Text{
        id:textTaskStatus
        text: "待处理"
        anchors{
            right:  parent.right

            margins: 15

        }
        font.pixelSize: 15
    }


    Text{
        text: "高"
        anchors{
            right:  parent.right
            top: textTaskStatus.bottom
            margins: 15
        }
        font.pixelSize: 15
    }



    // 分割线
    Rectangle {
        width: parent.width
        height: 1
        color: separatorColor
        anchors.bottom: parent.bottom
    }
}
