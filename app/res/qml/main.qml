import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import "singletons"

Window {
    width: QivStyle.sizeScreen.width
    height: QivStyle.sizeScreen.height
    visible: true
    title: qsTr("Qt Image Viewer")

    StackView {
        id: stackView

        anchors.fill: parent
        initialItem: rootPage
    }

    Component {
        id: rootPage

        QivUsersPage {
            view: stackView

            onUserSelected: {
                stackView.push(mainPage)
            }
        }
    }

    Component {
        id: mainPage

        QivAlbumsPage {
            view: stackView

            onAlbumSelected: {
                stackView.push(photosPage)
            }
        }
    }

    Component {
        id: photosPage

        QivPhotosPage {
            view: stackView
        }
    }
}
