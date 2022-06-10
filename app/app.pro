QT += quick
CONFIG += c++17

TEMPLATE = app

include(../defaults.pri)

SOURCES += main.cpp

RESOURCES += qml.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../src/release/ -lviewer
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../src/debug/ -lviewer
else:unix: LIBS += -L$$OUT_PWD/../src/ -lviewer

INCLUDEPATH += $$PWD/../src
DEPENDPATH += $$PWD/../src
