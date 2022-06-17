#include "mockdataprovider.h"

using namespace Qiv;

namespace
{

QJsonArray generate(int count)
{
    QJsonArray array;
    for (int i = 0; i < count; ++i)
    {
        array << QJsonObject{{"id", i + 1}};
    }
    return array;
}

}

MockDataProvider::MockDataProvider(QObject *parent) : DataProvider(parent)
{
}

void MockDataProvider::requestUsers()
{
    emit usersResponse(generate(10));
}

void MockDataProvider::requestAlbums()
{
    emit albumsResponse(generate(100));
}

void MockDataProvider::requestUserAlbums(int)
{
    emit userAlbumsResponse(generate(10));
}

void MockDataProvider::requestPhotos()
{
    emit photosResponse(generate(5000));
}

void MockDataProvider::requestAlbumPhotos(int)
{
    emit albumPhotosResponse(generate(50));
}

void MockDataProvider::requestComments()
{
    emit commentsResponse(generate(500));
}

void MockDataProvider::requestPosts()
{
    emit postsResponse(generate(100));
}
