#-------------------------------------------------
#
# Project created by QtCreator 2016-10-01T10:37:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Testing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

LIBS += -L$$PWD/../QhSidebar/lib/ -lQhSidebar

INCLUDEPATH += $$PWD/../QhSidebar/include

