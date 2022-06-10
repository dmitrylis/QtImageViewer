import QtQuick 2.15

import "../singletons"
import "../controls"

QivBaseButton {
    id: root

    property string primaryText
    property string secondaryText

    implicitWidth: QivStyle.sizeTile.width
    implicitHeight: QivStyle.sizeTile.height

    contentItem: Item {
        Column {
            anchors {
                verticalCenter: parent.verticalCenter
                left: parent.left
                right: parent.right
            }
            spacing: QivStyle.marginTiny

            QivAvatar {
                anchors.horizontalCenter: parent.horizontalCenter
                name: root.primaryText
            }

            QivText {
                width: parent.width
                horizontalAlignment: Text.AlignHCenter
                text: root.primaryText
                type: QivText.TextType.PrimaryText
            }

            QivText {
                width: parent.width
                horizontalAlignment: Text.AlignHCenter
                text: '"' + root.secondaryText + '"'
            }
        }
    }

    StateGroup {
        states: [
            State {
                name: "normal_hovered"
                when: root.state === "normal_hovered"

                PropertyChanges {
                    target: contentItem
                    scale: 1.07
                }
            },
            State {
                name: "normal_down"
                when: root.state === "normal_down"

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
