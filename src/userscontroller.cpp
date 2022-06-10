#include "userscontroller.h"

using namespace Qiv;

UsersController::UsersController(DataProvider *dataProvider, QObject *parent)
    : BaseController(dataProvider, parent)
{
    assert(this->dataProvider());

    connect(this->dataProvider(), &DataProvider::usersResponse,
            this, &UsersController::handleUsersResponse);
}

void UsersController::requestUsers() const
{
    assert(dataProvider());

    dataProvider()->requestUsers();
}

void UsersController::handleUsersResponse(const QJsonArray &usersModel)
{
    if (m_usersModel == usersModel)
    {
        return;
    }

    m_usersModel = usersModel;
    emit usersModelChanged();
}

void UsersController::selectUser(int userId)
{
    if (m_selectedUserId == userId)
    {
        return;
    }

    m_selectedUserId = userId;
    emit selectedUserIdChanged();
}

void UsersController::forgetUser()
{
    selectUser(INVALID_ID);
}

QJsonObject UsersController::selectedUserData() const
{
    if (m_selectedUserId > INVALID_ID)
    {
        for (const auto& user : m_usersModel)
        {
            if (user.toObject().value("id") == m_selectedUserId)
            {
                return user.toObject();
            }
        }
    }
    return QJsonObject();
}
