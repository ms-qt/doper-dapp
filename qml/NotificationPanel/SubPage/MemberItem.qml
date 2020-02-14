import QtQuick 2.0

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


    Image{
        width: 30
        height: 30
        //source: "image://imageProvider/"+avatar
        source: "image://async/"+avatar
    }

    Text {
        text: qsTr(name)
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
