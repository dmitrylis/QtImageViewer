import QtQuick 2.15

import "../controls"
import "../singletons"
import "../effects"

QivBaseButton {
    id: root

    implicitWidth: contentItem.implicitWidth + QivStyle.marginHuge
    implicitHeight: 50

    background: Rectangle {
        radius: root.height * 0.5
        layer {
            enabled: true
            effect: QivShadowEffect { alpha: 0.3 }
        }

        gradient: Gradient {
            orientation: Gradient.Horizontal

            GradientStop {
                position: 0.0
                color: QivStyle.colorButtonsSet[0]
            }

            GradientStop {
                position: 0.5
                color: QivStyle.colorButtonsSet[1]
            }

            GradientStop {
                position: 1.0
                color: QivStyle.colorButtonsSet[2]
            }
        }
    }

    contentItem: QivText {
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text: root.text
        type: QivText.TextType.PrimaryText
        color: QivStyle.colorTextLight
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
            },
            State {
                name: "normal_disabled"
                when: root.state === "normal_disabled"

                PropertyChanges {
                    target: background
                    opacity: 0.4
                }

                PropertyChanges {
                    target: contentItem
                    opacity: 0.4
                }
            }
        ]

        transitions: Transition {
            PropertyAnimation { property: "scale"; duration: 125 }
        }
    }
}
