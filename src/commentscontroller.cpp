#include "commentscontroller.h"

using namespace Qiv;

CommentsController::CommentsController(DataProvider *dataProvider, QObject *parent)
    : BaseController(dataProvider, parent)
{
    assert(this->dataProvider());

    connect(this->dataProvider(), &DataProvider::commentsResponse,
            this, &CommentsController::handleCommentsResponse);
}

void CommentsController::requestComments() const
{
    assert(dataProvider());

    dataProvider()->requestComments();
}

void CommentsController::handleCommentsResponse(const QJsonArray &commentsModel)
{
    if (m_commentsCount == commentsModel.count())
    {
        return;
    }

    m_commentsCount = commentsModel.count();
    emit commentsCountChanged();
}

void CommentsController::resetComments()
{
    handleCommentsResponse(QJsonArray());
}
