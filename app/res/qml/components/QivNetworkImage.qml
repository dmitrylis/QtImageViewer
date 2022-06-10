import QtQuick 2.15

Image {
    id: root

    asynchronous: true

    QivBusyIndicator {
        anchors.centerIn: parent
        running: root.status !== Image.Ready
    }
}
