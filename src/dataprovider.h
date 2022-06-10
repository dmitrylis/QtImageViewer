#ifndef DATAPROVIDER_H
#define DATAPROVIDER_H

#include <QObject>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace Qiv {

class DataProvider : public QObject
{
    Q_OBJECT

public:
    explicit DataProvider(QObject* parent = nullptr);
    virtual ~DataProvider();

    // requests
    virtual void requestUsers() = 0;

    virtual void requestAlbums() = 0;
    virtual void requestUserAlbums(int userId) = 0;

    virtual void requestPhotos() = 0;
    virtual void requestAlbumPhotos(int albumId) = 0;

    virtual void requestComments() = 0;
    virtual void requestPosts() = 0;

signals:
    // responses
    void usersResponse(const QJsonArray& users) const;

    void albumsResponse(const QJsonArray& albums) const;
    void userAlbumsResponse(const QJsonArray& albums) const;

    void photosResponse(const QJsonArray& photos) const;
    void albumPhotosResponse(const QJsonArray& photos) const;

    void commentsResponse(const QJsonArray& users) const;
    void postsResponse(const QJsonArray& users) const;
};

}

#endif // DATAPROVIDER_H
