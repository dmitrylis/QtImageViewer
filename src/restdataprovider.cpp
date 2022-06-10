#include "restdataprovider.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

using namespace Qiv;

namespace {
const QString URL {QStringLiteral("https://jsonplaceholder.typicode.com")};

const QString USERS {QStringLiteral("/users")};

const QString ALBUMS {QStringLiteral("/albums")};
const QString USER_ALBUMS {QStringLiteral("/users/%1/albums")};

const QString PHOTOS {QStringLiteral("/photos")};
const QString ALBUM_PHOTOS {QStringLiteral("/albums/%1/photos")};

const QString COMMENTS {QStringLiteral("/comments")};
const QString POSTS {QStringLiteral("/posts")};
}

RestDataProvider::RestDataProvider(QObject* parent)
    : DataProvider(parent)
{
    m_networkManager = new QNetworkAccessManager(this);
}

void RestDataProvider::requestUsers()
{
    sendGetRequest(QUrl(URL + USERS), [this](const QJsonArray& dataArray)
    {
        emit usersResponse(dataArray);
    });
}

void RestDataProvider::requestAlbums()
{
    sendGetRequest(QUrl(URL + ALBUMS), [this](const QJsonArray& dataArray)
    {
        emit albumsResponse(dataArray);
    });
}

void RestDataProvider::requestUserAlbums(int userId)
{
    sendGetRequest(QUrl(URL + USER_ALBUMS.arg(userId)), [this](const QJsonArray& dataArray)
    {
        emit userAlbumsResponse(dataArray);
    });
}

void RestDataProvider::requestPhotos()
{
    sendGetRequest(QUrl(URL + PHOTOS), [this](const QJsonArray& dataArray)
    {
        emit photosResponse(dataArray);
    });
}

void RestDataProvider::requestAlbumPhotos(int albumId)
{
    sendGetRequest(QUrl(URL + ALBUM_PHOTOS.arg(albumId)), [this](const QJsonArray& dataArray)
    {
        emit albumPhotosResponse(dataArray);
    });
}

void RestDataProvider::requestComments()
{
    sendGetRequest(QUrl(URL + COMMENTS), [this](const QJsonArray& dataArray)
    {
        emit commentsResponse(dataArray);
    });
}

void RestDataProvider::requestPosts()
{
    sendGetRequest(QUrl(URL + POSTS), [this](const QJsonArray& dataArray)
    {
        emit postsResponse(dataArray);
    });
}

void RestDataProvider::sendGetRequest(const QUrl& endpoint, ReplyHandler replyHandler)
{
    assert(m_networkManager);

    const QNetworkRequest request{endpoint};
    QNetworkReply *reply = m_networkManager->get(request);
    connect(reply, &QNetworkReply::finished, this, [reply, replyHandler]() {
        if (reply->error() != QNetworkReply::NoError)
        {
            qWarning() << "Error: " << reply->errorString();
        }
        else
        {
            replyHandler(QJsonDocument::fromJson(reply->readAll()).array());
        }
        reply->deleteLater();
    });
}
