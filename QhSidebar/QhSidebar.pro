#-------------------------------------------------
#
# Project created by QtCreator 2016-10-01T09:49:05
#
#-------------------------------------------------

QT       += widgets

TARGET = QhSidebar
TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH += $$PWD/include

SOURCES += $$PWD/src/qhsidebar.cpp

HEADERS += $$PWD/include/qhsidebar.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

DESTDIR = $$PWD/lib

RESOURCES += \
    resource.qrc
