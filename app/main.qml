import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 480
    height: 480
    visible: true
    title: qsTr("Qt Image Viewer")

    Item { // user selection view
        anchors.fill: parent
    }

    Item { // main view
        anchors.fill: parent
    }
}
