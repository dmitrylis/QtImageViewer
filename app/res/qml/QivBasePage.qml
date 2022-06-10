import QtQuick 2.15
import QtQuick.Controls 2.15

import "singletons"
import "components"
import "effects"

Rectangle {
    id: root

    required property StackView view
    default property alias content: content.data
    property bool loading: false
    property bool forceBackVisible: true
    property alias title: title.text

    signal pageOpened()
    signal pageClosed()

    color: QivStyle.colorMainBg
    clip: true

    Component.onCompleted: {
        root.pageOpened()
    }

    Component.onDestruction: {
        root.pageClosed()
    }

    Item {
        id: content

        anchors {
            fill: parent
            topMargin: titleArea.height
        }
        visible: !root.loading
    }

    Rectangle {
        id: titleArea

        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
        }
        height: 50
        layer {
            enabled: true
            effect: QivShadowEffect {}
        }

        QivButton {
            anchors {
                left: parent.left
                verticalCenter: parent.verticalCenter
                margins: QivStyle.marginTiny
            }
            height: 35
            text: qsTr("back")
            visible: root.forceBackVisible && root.view.depth > 1

            onClicked: {
                root.view.pop()
            }
        }

        QivText {
            id: title

            anchors.centerIn: parent
            type: QivText.TextType.Heading3
        }
    }

    QivBusyIndicator {
        anchors.centerIn: parent
        running: root.loading
    }
}
