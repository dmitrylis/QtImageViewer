import QtQuick 2.15
import QtGraphicalEffects 1.12

import "../singletons"
import "../controls"
import "../effects"

import "../QivHelper.js" as QivHelper

QivBaseButton {
    id: root

    property alias title: title.text

    QtObject {
        id: internal

        function color(seed) {
            const colors = QivStyle.colorSet
            const colorName = colors[QivHelper.randomCeiling(seed, colors.length)]
            const hackedColor = Qt.darker(colorName, 0.0)
            return QivHelper.opacify(hackedColor, 0.5)
        }
    }

    implicitWidth: QivStyle.sizeTile.width
    implicitHeight: QivStyle.sizeTile.height

    background: Item {
        Image {
            id: srcImage

            anchors.fill: parent
            source: "qrc:/res/assets/album_cover.png"
        }

        ColorOverlay {
            anchors.fill: parent
            source: srcImage
            color: internal.color(root.title)
        }

        layer {
            enabled: true
            effect: QivShadowEffect { alpha: 0.3 }
        }
    }

    contentItem: Item {
        Rectangle {
            anchors {
                left: parent.left
                right: parent.right
                bottom: parent.bottom
            }
            height: 46
            color: QivStyle.colorOverlayLight

            QivText {
                id: title

                anchors {
                    fill: parent
                    leftMargin: QivStyle.marginSmall
                    rightMargin: QivStyle.marginSmall
                }
                maximumLineCount: 2
                verticalAlignment: Text.AlignVCenter
            }
        }
    }

    StateGroup {
        states: [
            State {
                name: "normal_hovered"
                when: root.state === "normal_hovered"

                PropertyChanges {
                    target: background
                    scale: 1.07
                }

                PropertyChanges {
                    target: contentItem
                    scale: 1.07
                }
            },
            State {
                name: "normal_down"
                when: root.state === "normal_down"

                PropertyChanges {
                    target: background
                    scale: 0.95
                }

                PropertyChanges {
                    target: contentItem
                    scale: 0.95
                }
            }
        ]

        transitions: Transition {
            PropertyAnimation { property: "scale"; duration: 125 }
        }
    }
}
