#ifndef COMMENTSCONTROLLER_H
#define COMMENTSCONTROLLER_H

#include "basecontroller.h"

#include <QJsonArray>

namespace Qiv {

class CommentsController final : public BaseController
{
    Q_OBJECT
    Q_PROPERTY(int commentsCount MEMBER m_commentsCount NOTIFY commentsCountChanged)

public:
    explicit CommentsController(DataProvider *dataProvider, QObject *parent = nullptr);

    // requests
    Q_INVOKABLE void requestComments() const;

    // handlers
    void handleCommentsResponse(const QJsonArray& commentsModel);

    // business logic
    Q_INVOKABLE void resetComments();

signals:
    void commentsCountChanged();

private:
    int m_commentsCount {0};
};

}

#endif // COMMENTSCONTROLLER_H
