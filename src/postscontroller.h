#ifndef POSTSCONTROLLER_H
#define POSTSCONTROLLER_H

#include "basecontroller.h"

#include <QJsonArray>

namespace Qiv {

class PostsController final : public BaseController
{
    Q_OBJECT
    Q_PROPERTY(int postsCount MEMBER m_postsCount NOTIFY postsCountChanged)

public:
    explicit PostsController(DataProvider *dataProvider, QObject *parent = nullptr);

    // requests
    Q_INVOKABLE void requestPosts() const;

    // handlers
    void handlePostsResponse(const QJsonArray& postsModel);

    // business logic
    Q_INVOKABLE void resetPosts();

signals:
    void postsCountChanged();

private:
    int m_postsCount {0};
};

}

#endif // POSTSCONTROLLER_H
