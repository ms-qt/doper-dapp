import QtQuick 2.0
import QtGraphicalEffects 1.0


Rectangle {
    id: rectangleTaskListRoot

    property color background: "#EBEDEE"
    property color highlightHover: "#DDE0DF"
    property color highlightSelection: "#8D8E8E"

    color: background
    clip: true

    ListView {
        id: listViewNotificationTaskList
        anchors.fill: parent
        anchors.topMargin: 5
        opacity: 1
        boundsBehavior: Flickable.DragAndOvershootBounds
        maximumFlickVelocity: 2500
        snapMode: ListView.SnapToItem
        model:taskListModel
        delegate: NotificationTaskListItem {
            taskName: taskModel.getTaskName(_task_id)
            width: listViewNotificationTaskList.width
            height: 85
            color: listViewNotificationTaskList.currentIndex === index ? "transparent" : (mouseAreaNotificationTaskList.containsMouse ? highlightHover : background)
            backgroundColor: listViewNotificationTaskList.currentIndex === index ? "transparent" : (mouseAreaNotificationTaskList.containsMouse ? highlightHover : background)
            separatorColor: listViewNotificationTaskList.currentIndex === index ? "transparent" : highlightHover
            smooth: mouseAreaNotificationTaskList.containsMouse
            MouseArea {
                id: mouseAreaNotificationTaskList
                anchors.left: parent.left
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    listViewNotificationTaskList.currentIndex = index
                }
                onDoubleClicked: {
                }
            }
        }
        highlight:
            Rectangle {
            color: highlightSelection
            radius: 3
            anchors.fill: listViewNotificationTaskList.currentItem
        }
        highlightFollowsCurrentItem: true
        highlightRangeMode: ListView.NoHighlightRange
    }
}
