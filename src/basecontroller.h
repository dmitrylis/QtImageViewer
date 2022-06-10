#ifndef BASECONTROLLER_H
#define BASECONTROLLER_H

#include <QObject>

#include "dataprovider.h"

namespace Qiv {

constexpr int INVALID_ID {0};

class BaseController : public QObject
{
    Q_OBJECT

public:
    explicit BaseController(DataProvider *dataProvider, QObject* parent = nullptr);
    virtual ~BaseController();

protected:
    DataProvider *dataProvider() const;

private:
    // communication with data
    DataProvider *m_dataProvider {nullptr};
};

}

#endif // BASECONTROLLER_H
