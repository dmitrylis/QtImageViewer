#ifndef PHOTOSCONTROLLER_H
#define PHOTOSCONTROLLER_H

#include "basecontroller.h"

#include <QJsonArray>

namespace Qiv {

class PhotosController final : public BaseController
{
    Q_OBJECT
    Q_PROPERTY(int photosCount MEMBER m_photosCount NOTIFY photosCountChanged)
    Q_PROPERTY(QJsonArray albumPhotosModel MEMBER m_albumPhotosModel NOTIFY albumPhotosModelChanged)

public:
    explicit PhotosController(DataProvider *dataProvider, QObject *parent = nullptr);

    // requests
    Q_INVOKABLE void requestPhotos() const;
    Q_INVOKABLE void requestAlbumPhotos(int albumId) const;

    // handlers
    void handlePhotosResponse(const QJsonArray& photosModel);
    void handleAlbumPhotosResponse(const QJsonArray& albumPhotosModel);

    // business logic
    Q_INVOKABLE void resetPhotos();
    Q_INVOKABLE void resetAlbumPhotos();

signals:
    void photosCountChanged();
    void albumPhotosModelChanged();

private:
    int m_photosCount {0};
    QJsonArray m_albumPhotosModel;
};

}

#endif // PHOTOSCONTROLLER_H
