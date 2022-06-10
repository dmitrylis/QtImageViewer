import QtQuick 2.15
import QtQuick.Controls 2.15

import "components"
import "singletons"

QivBasePage {
    id: root

    loading: !_photosController.albumPhotosModel.length
    forceBackVisible: imagePreview.source == ""
    title: !_usersController.selectedUserId ? qsTr("All photos")
                                            : qsTr("%1's photos").arg(_usersController.selectedUserData.username)

    onPageOpened: {
        _photosController.requestAlbumPhotos(_albumsController.selectedAlbumId)
    }

    onPageClosed: {
        _albumsController.forgetAlbum()
        _photosController.resetAlbumPhotos()
    }

    GridView {
        id: photosView

        anchors.fill: parent
        cellWidth: QivStyle.sizeTile.width
        cellHeight: QivStyle.sizeTile.height
        model: _photosController.albumPhotosModel
        delegate: QivPhotoTile {
            source: modelData.thumbnailUrl

            onClicked: {
                imagePreview.source = modelData.url
            }
        }

        ScrollBar.vertical: ScrollBar {
            policy: ScrollBar.AlwaysOn
        }
    }

    QivImagePreview {
        id: imagePreview

        anchors.fill: parent
        blurSource: photosView

        onClicked: {
            source = ""
        }
    }
}
