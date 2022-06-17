#ifndef MOCKDATAPROVIDER_H
#define MOCKDATAPROVIDER_H

#include <dataprovider.h>

namespace Qiv {

class MockDataProvider : public DataProvider
{
    Q_OBJECT

public:
    explicit MockDataProvider(QObject *parent = nullptr);

    void requestUsers() override;

    void requestAlbums() override;
    void requestUserAlbums(int userId) override;

    void requestPhotos() override;
    void requestAlbumPhotos(int albumId) override;

    void requestComments() override;
    void requestPosts() override;
};

}

#endif // MOCKDATAPROVIDER_H
