#ifndef RESTDATAPROVIDER_H
#define RESTDATAPROVIDER_H

#include "dataprovider.h"

class QNetworkAccessManager;

namespace Qiv {

using ReplyHandler = std::function<void(const QJsonArray& dataArray)>;

class RestDataProvider final : public DataProvider
{
    Q_OBJECT

public:
    explicit RestDataProvider(QObject* parent = nullptr);

    void requestUsers() override;

    void requestAlbums() override;
    void requestUserAlbums(int userId) override;

    void requestPhotos() override;
    void requestAlbumPhotos(int albumId) override;

    void requestComments() override;
    void requestPosts() override;

private:
    void sendGetRequest(const QUrl& endpoint, ReplyHandler replyHandler);

private:
    QNetworkAccessManager *m_networkManager {nullptr};
};

}

#endif // RESTDATAPROVIDER_H
