QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase c++17
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    mockdataprovider.cpp \
    testcontrollers.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../src/release/ -lviewer
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../src/debug/ -lviewer
else:unix: LIBS += -L$$OUT_PWD/../src/ -lviewer

INCLUDEPATH += $$PWD/../src
DEPENDPATH += $$PWD/../src

HEADERS += \
    mockdataprovider.h
