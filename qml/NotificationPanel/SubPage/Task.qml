import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import Qt.labs.platform 1.1
import QtQuick.Layouts 1.3

import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.4
// 任务
Item {
    width: parent.width
    height: parent.height
    Rectangle{
        width: parent.width
        height: parent.height
        color: "#ffa001"
    }

    TabView {
        id: tabViewTask
        width: parent.width
        height: 85
        anchors.fill: parent
        currentIndex: 0
        style: TabStyle { tabRadius: 0 }
        Tab {
            width: 60
            title: qsTr("任务")
            TaskList{}
        }
    }
}
