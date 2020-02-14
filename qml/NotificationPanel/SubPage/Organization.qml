import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import Qt.labs.platform 1.1
import QtQuick.Layouts 1.3

// 组织
Item {
    width: swipeViewHomeContent.width
    height: swipeViewHomeContent.height
    Rectangle{
        width: parent.width
        height: parent.height
        color: "#ffa001"
    }
    MemberList{
        width: parent.width
        height: parent.height
    }
}



