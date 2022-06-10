#ifndef ALBUMSCONTROLLER_H
#define ALBUMSCONTROLLER_H

#include "basecontroller.h"

#include <QJsonArray>

namespace Qiv {

class AlbumsController final : public BaseController
{
    Q_OBJECT
    Q_PROPERTY(QJsonArray albumsModel MEMBER m_albumsModel NOTIFY albumsModelChanged)
    Q_PROPERTY(QJsonArray userAlbumsModel MEMBER m_userAlbumsModel NOTIFY userAlbumsModelChanged)
    Q_PROPERTY(int selectedAlbumId MEMBER m_selectedAlbumId NOTIFY selectedAlbumIdChanged)

public:
    explicit AlbumsController(DataProvider *dataProvider, QObject *parent = nullptr);

    // requests
    Q_INVOKABLE void requestAlbums() const;
    Q_INVOKABLE void requestUserAlbums(int userId) const;

    // handlers
    void handleAlbumsResponse(const QJsonArray& albumsModel);
    void handleUserAlbumsResponse(const QJsonArray& userAlbumsModel);

    // business logic
    Q_INVOKABLE void resetAlbums();
    Q_INVOKABLE void resetUserAlbums();

    Q_INVOKABLE void selectAlbum(int albumId);
    Q_INVOKABLE void forgetAlbum();

signals:
    void albumsModelChanged();
    void userAlbumsModelChanged();
    void selectedAlbumIdChanged();

private:
    QJsonArray m_albumsModel;
    QJsonArray m_userAlbumsModel;
    int m_selectedAlbumId {INVALID_ID};
};

}

#endif // ALBUMSCONTROLLER_H
