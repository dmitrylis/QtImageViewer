#ifndef USERSCONTROLLER_H
#define USERSCONTROLLER_H

#include "basecontroller.h"

#include <QJsonObject>
#include <QJsonArray>

namespace Qiv {

class UsersController final : public BaseController
{
    Q_OBJECT
    Q_PROPERTY(QJsonArray usersModel MEMBER m_usersModel NOTIFY usersModelChanged)
    Q_PROPERTY(int selectedUserId MEMBER m_selectedUserId NOTIFY selectedUserIdChanged)
    Q_PROPERTY(QJsonObject selectedUserData READ selectedUserData NOTIFY selectedUserIdChanged)

public:
    explicit UsersController(DataProvider *dataProvider, QObject *parent = nullptr);

    // requests
    Q_INVOKABLE void requestUsers() const;

    // handlers
    void handleUsersResponse(const QJsonArray& usersModel);

    // business logic
    Q_INVOKABLE void selectUser(int userId);
    Q_INVOKABLE void forgetUser();

signals:
    void usersModelChanged();
    void selectedUserIdChanged();

protected:
    QJsonObject selectedUserData() const;

private:
    QJsonArray m_usersModel;
    int m_selectedUserId {INVALID_ID};
};

}

#endif // USERSCONTROLLER_H
