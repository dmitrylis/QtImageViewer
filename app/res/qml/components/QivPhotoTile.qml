import QtQuick 2.15

import "../controls"
import "../singletons"

QivBaseButton {
    id: root

    property url source

    implicitWidth: QivStyle.sizeTile.width
    implicitHeight: QivStyle.sizeTile.height

    contentItem: QivNetworkImage {
        source: root.source
    }

    StateGroup {
        states: [
            State {
                name: "normal_hovered"
                when: root.state === "normal_hovered"

                PropertyChanges {
                    target: contentItem
                    opacity: 0.7
                }
            },
            State {
                name: "normal_down"
                when: root.state === "normal_down"

                PropertyChanges {
                    target: contentItem
                    opacity: 0.5
                }
            }
        ]

        transitions: Transition {
            PropertyAnimation { property: "opacity"; duration: 125 }
        }
    }
}
