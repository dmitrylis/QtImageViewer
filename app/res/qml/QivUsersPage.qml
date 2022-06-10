import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

import "components"
import "singletons"

QivBasePage {
    id: root

    signal userSelected()

    loading: !_usersController.usersModel.length
    title: qsTr("Welcome")

    onPageOpened: {
        _usersController.requestUsers()
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        QivText {
            Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
            Layout.topMargin: QivStyle.marginHuge

            text: qsTr("Please select the user")
            type: QivText.TextType.Heading1
        }

        ListView {
            id: usersView

            Layout.alignment: Qt.AlignCenter
            Layout.fillWidth: true
            Layout.leftMargin: QivStyle.marginSmall
            Layout.rightMargin: QivStyle.marginSmall

            model: _usersController.usersModel
            height: QivStyle.sizeTile.height
            spacing: QivStyle.marginTiny
            orientation: ListView.Horizontal
            delegate: QivUserTile {
                primaryText: modelData.name
                secondaryText: modelData.username

                onClicked: {
                    _usersController.selectUser(modelData.id)
                    root.userSelected()
                }
            }

            ScrollBar.horizontal: ScrollBar {
                anchors {
                    left: usersView.left
                    right: usersView.right
                    top: usersView.bottom
                    topMargin: QivStyle.marginSmall
                }
                policy: usersView.width < usersView.contentWidth ? ScrollBar.AlwaysOn
                                                                 : ScrollBar.AlwaysOff
            }
        }

        QivText {
            Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter

            text: qsTr("or")
            type: QivText.TextType.Heading2
        }

        QivButton {
            Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
            Layout.bottomMargin: QivStyle.marginLarge

            text: qsTr("explore all albums")

            onClicked: {
                root.userSelected()
            }
        }
    }
}
