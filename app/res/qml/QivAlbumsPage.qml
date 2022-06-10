import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

import "singletons"
import "components"

QivBasePage {
    id: root

    signal albumSelected()

    loading: !_usersController.selectedUserId ? !_albumsController.albumsModel.length
                                              : !_albumsController.userAlbumsModel.length
    title: !_usersController.selectedUserId ? qsTr("All albums (%1)").arg(_albumsController.albumsModel.length)
                                            : qsTr("%1's albums (%2)").arg(_usersController.selectedUserData.username).arg(_albumsController.userAlbumsModel.length)

    onPageOpened: {
        if (!!_usersController.selectedUserId) {
            _albumsController.requestUserAlbums(_usersController.selectedUserId)
        }
        else {
            _albumsController.requestAlbums()
        }

        _photosController.requestPhotos()
        _commentsController.requestComments()
        _postsController.requestPosts()
    }

    onPageClosed: {
        if (!!_usersController.selectedUserId) {
            _usersController.forgetUser()
            _albumsController.resetUserAlbums()
        }
        else {
            _albumsController.resetAlbums()
        }

        _photosController.resetPhotos()
        _commentsController.resetComments()
        _postsController.resetPosts()
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        ListView {
            id: albumsView

            Layout.alignment: Qt.AlignCenter
            Layout.fillWidth: true
            Layout.leftMargin: QivStyle.marginSmall
            Layout.rightMargin: QivStyle.marginSmall

            model: !_usersController.selectedUserId ? _albumsController.albumsModel
                                                    : _albumsController.userAlbumsModel
            height: QivStyle.sizeTile.height
            spacing: QivStyle.marginSmall
            orientation: ListView.Horizontal
            delegate: QivAlbumTile {
                title: modelData.title

                onClicked: {
                    _albumsController.selectAlbum(modelData.id)
                    root.albumSelected()
                }
            }

            ScrollBar.horizontal: ScrollBar {
                anchors {
                    left: albumsView.left
                    right: albumsView.right
                    top: albumsView.bottom
                    topMargin: QivStyle.marginSmall
                }
                policy: albumsView.width < albumsView.contentWidth ? ScrollBar.AlwaysOn
                                                                   : ScrollBar.AlwaysOff
            }
        }

        RowLayout {
            Layout.fillWidth: true
            Layout.leftMargin: QivStyle.marginLarge
            Layout.rightMargin: QivStyle.marginLarge

            spacing: QivStyle.marginMedium

            QivInfoPanel {
                Layout.preferredHeight: 100
                Layout.fillWidth: true

                title: qsTr("Users")
                value: _usersController.usersModel.length
                loading: !_usersController.usersModel.length
            }

            QivInfoPanel {
                Layout.preferredHeight: 100
                Layout.fillWidth: true

                title: qsTr("Photos")
                value: _photosController.photosCount
                loading: !_photosController.photosCount
            }

            QivInfoPanel {
                Layout.preferredHeight: 100
                Layout.fillWidth: true

                title: qsTr("Comments")
                value: _commentsController.commentsCount
                loading: !_commentsController.commentsCount
            }

            QivInfoPanel {
                Layout.preferredHeight: 100
                Layout.fillWidth: true

                title: qsTr("Posts")
                value: _postsController.postsCount
                loading: !_postsController.postsCount
            }
        }
    }
}
