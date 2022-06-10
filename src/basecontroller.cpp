#include "basecontroller.h"

using namespace Qiv;

BaseController::BaseController(DataProvider *dataProvider, QObject *parent)
    : QObject(parent)
    , m_dataProvider(dataProvider)
{
}

BaseController::~BaseController()
{
}

DataProvider *BaseController::dataProvider() const
{
    return m_dataProvider;
}
