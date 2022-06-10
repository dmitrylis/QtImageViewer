#include "postscontroller.h"

using namespace Qiv;

PostsController::PostsController(DataProvider *dataProvider, QObject *parent)
    : BaseController(dataProvider, parent)
{
    assert(this->dataProvider());

    connect(this->dataProvider(), &DataProvider::postsResponse,
            this, &PostsController::handlePostsResponse);
}

void PostsController::requestPosts() const
{
    assert(dataProvider());

    dataProvider()->requestPosts();
}

void PostsController::handlePostsResponse(const QJsonArray &postsModel)
{
    if (m_postsCount == postsModel.count())
    {
        return;
    }

    m_postsCount = postsModel.count();
    emit postsCountChanged();
}

void PostsController::resetPosts()
{
    handlePostsResponse(QJsonArray());
}
