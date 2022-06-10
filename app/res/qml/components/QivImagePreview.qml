import QtQuick 2.15

import "../singletons"
import "../effects"

Item {
    id: root

    property alias source: image.source
    property Item blurSource: null

    signal clicked()

    visible: image.source != ""

    // blurred bg
    Rectangle {
        anchors.fill: parent
        color: QivStyle.colorMainBg

        QivBlurEffect {
            anchors.fill: parent
            source: root.blurSource
        }

        Rectangle {
            anchors.fill: parent
            color: QivStyle.colorOverlayDark
        }
    }

    QivNetworkImage {
        id: image

        function handleSize(parentSize, imageSize) {
            return (status === Image.Ready) ? Math.min(parentSize - QivStyle.marginLarge, imageSize)
                                            : parentSize - QivStyle.marginLarge
        }

        anchors.centerIn: parent
        width: handleSize(parent.width, sourceSize.width)
        height: handleSize(parent.height, sourceSize.height)
        layer {
            enabled: true
            effect: QivShadowEffect { radius: 30; alpha: 0.7 }
        }
        fillMode: Image.PreserveAspectCrop
    }

    Column {
        anchors {
            horizontalCenter: parent.horizontalCenter
            bottom: parent.bottom
            bottomMargin: QivStyle.marginLarge
        }
        layer {
            enabled: true
            effect: QivShadowEffect {
                verticalOffset: 0
                shadowColor: QivStyle.colorShadowLight
                alpha: 1.0
            }
        }

        QivText {
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Click anywhere to close")
        }

        QivText {
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Zoom in/out using mouse wheel")
        }
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true

        onWheel: {
            if (wheel.angleDelta.y > 0)
            {
                image.scale = Math.min(7.0, image.scale + 0.2)
            }
            else
            {
                image.scale = Math.max(0.3, image.scale - 0.2)
            }
            wheel.accepted = true
        }

        onClicked: {
            image.scale = 1.0
            root.clicked()
        }
    }
}
