QT += core network
QT -= gui

CONFIG += qt c++17
CONFIG -= app_bundle

TEMPLATE = lib

TARGET = viewer

include(../defaults.pri)

HEADERS += albumscontroller.h \
           basecontroller.h \
           commentscontroller.h \
           dataprovider.h \
           photoscontroller.h \
           postscontroller.h \
           restdataprovider.h \
           userscontroller.h

SOURCES += albumscontroller.cpp \
           basecontroller.cpp \
           commentscontroller.cpp \
           dataprovider.cpp \
           photoscontroller.cpp \
           postscontroller.cpp \
           restdataprovider.cpp \
           userscontroller.cpp
