import QtQuick 2.15
import QtQuick.Controls 2.15

BusyIndicator {
    id: root

    visible: running

    contentItem: Image {
        source: "qrc:/res/assets/spinner.png"

        RotationAnimation on rotation {
            loops: Animation.Infinite
            duration: 1250
            from: 0.0
            to: 360.0
            running: root.running
        }
    }
}
