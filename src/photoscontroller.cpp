#include "photoscontroller.h"

using namespace Qiv;

PhotosController::PhotosController(DataProvider *dataProvider, QObject *parent)
    : BaseController(dataProvider, parent)
{
    assert(this->dataProvider());

    connect(this->dataProvider(), &DataProvider::photosResponse,
            this, &PhotosController::handlePhotosResponse);
    connect(this->dataProvider(), &DataProvider::albumPhotosResponse,
            this, &PhotosController::handleAlbumPhotosResponse);
}

void PhotosController::requestPhotos() const
{
    assert(dataProvider());

    dataProvider()->requestPhotos();
}

void PhotosController::requestAlbumPhotos(int albumId) const
{
    assert(dataProvider());

    dataProvider()->requestAlbumPhotos(albumId);
}

void PhotosController::handlePhotosResponse(const QJsonArray &photosModel)
{
    if (m_photosCount == photosModel.count())
    {
        return;
    }

    m_photosCount = photosModel.count();
    emit photosCountChanged();
}

void PhotosController::handleAlbumPhotosResponse(const QJsonArray &albumPhotosModel)
{
    if (m_albumPhotosModel == albumPhotosModel)
    {
        return;
    }

    m_albumPhotosModel = albumPhotosModel;
    emit albumPhotosModelChanged();
}

void PhotosController::resetPhotos()
{
    handlePhotosResponse(QJsonArray());
}

void PhotosController::resetAlbumPhotos()
{
    handleAlbumPhotosResponse(QJsonArray());
}
