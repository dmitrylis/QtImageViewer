#include "albumscontroller.h"

using namespace Qiv;

AlbumsController::AlbumsController(DataProvider *dataProvider, QObject *parent)
    : BaseController(dataProvider, parent)
{
    assert(this->dataProvider());

    connect(this->dataProvider(), &DataProvider::albumsResponse,
            this, &AlbumsController::handleAlbumsResponse);
    connect(this->dataProvider(), &DataProvider::userAlbumsResponse,
            this, &AlbumsController::handleUserAlbumsResponse);
}

void AlbumsController::requestAlbums() const
{
    assert(dataProvider());

    dataProvider()->requestAlbums();
}

void AlbumsController::requestUserAlbums(int userId) const
{
    assert(dataProvider());

    dataProvider()->requestUserAlbums(userId);
}

void AlbumsController::handleAlbumsResponse(const QJsonArray &albumsModel)
{
    if (m_albumsModel == albumsModel)
    {
        return;
    }

    m_albumsModel = albumsModel;
    emit albumsModelChanged();
}

void AlbumsController::handleUserAlbumsResponse(const QJsonArray &userAlbumsModel)
{
    if (m_userAlbumsModel == userAlbumsModel)
    {
        return;
    }

    m_userAlbumsModel = userAlbumsModel;
    emit userAlbumsModelChanged();
}

void AlbumsController::resetAlbums()
{
    handleAlbumsResponse(QJsonArray());
}

void AlbumsController::resetUserAlbums()
{
    handleUserAlbumsResponse(QJsonArray());
}

void AlbumsController::selectAlbum(int albumId)
{
    if (m_selectedAlbumId == albumId)
    {
        return;
    }

    m_selectedAlbumId = albumId;
    emit selectedAlbumIdChanged();
}

void AlbumsController::forgetAlbum()
{
    selectAlbum(INVALID_ID);
}
