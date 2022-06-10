import QtQuick 2.15

import "../singletons"
import "../effects"

Rectangle {
    id: root

    property alias title: title.text
    property int value: 0
    property bool loading: false

    color: QivStyle.colorInfoBg
    radius: QivStyle.marginSmall
    layer {
        enabled: true
        effect: QivShadowEffect {}
    }

    Column {
        anchors {
            verticalCenter: parent.verticalCenter
            left: parent.left
            right: parent.right
        }
        spacing: QivStyle.marginSmall

        QivText {
            id: title

            width: parent.width
            horizontalAlignment: Text.AlignHCenter
        }

        QivText {
            id: value

            width: parent.width
            horizontalAlignment: Text.AlignHCenter
            text: root.loading ? "..." : root.value
            type: QivText.TextType.Heading3
        }
    }
}
