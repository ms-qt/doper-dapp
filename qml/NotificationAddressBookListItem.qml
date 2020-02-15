import QtQuick 2.0
import QtQuick.Layouts 1.12

Rectangle {

    property string name
    property int age
    property bool sex
    property string signature
    property string avatar
    property string qq
    property string email
    property string jobtitle
    property string department
    property string phonenumber

    property color backgroundColor: "#EBEDEE"
    property color separatorColor: "#DDE0DF"
    property color offlineColor: "#FF645F"
    property color onlineColor: "#5ABE50"
    property color presenceTextColor: "#5B5B5B"

    width: parent.width
    height: parent.height

    Image{
        id:imageNotificationAddressBookListItemAvatar
        width: parent.height
        height: parent.height
        source: "image://imageAsync/"+avatar
        anchors.verticalCenter: parent.verticalCenter
    }

    Text {
        anchors.left: imageNotificationAddressBookListItemAvatar.right
        anchors.leftMargin: 15
        text: qsTr(name)
        font.pixelSize: 20
    }

    // 分割线
    Rectangle {
        id: separatorLine
        width: parent.width
        height: 1
        color: separatorColor
        anchors.bottom: parent.bottom
    }

}
