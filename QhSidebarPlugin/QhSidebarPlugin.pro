QT += widgets uiplugin designer
QTDIR_build {
# This is only for the Qt build. Do not use externally. We mean it.
PLUGIN_TYPE = designer
PLUGIN_CLASS_NAME = qhsidebarplugin
load(qt_plugin)
CONFIG += install_ok
} else {
# Public example:

CONFIG      += plugin
TEMPLATE    = lib

TARGET = $$qtLibraryTarget($$TARGET)

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS += target
}

INCLUDEPATH += $$PWD/include

HEADERS     = $$PWD/include/qhsidebarplugin.h \
              $$PWD/include/qhsidebartaskmenu.h \
              $$PWD/include/qhsidebardialog.h

SOURCES     = $$PWD/src/qhsidebarplugin.cpp \
              $$PWD/src/qhsidebartaskmenu.cpp \
              $$PWD/src/qhsidebardialog.cpp

RESOURCES += \
    icons.qrc

DESTDIR = $$PWD/lib

LIBS += -L$$PWD/../QhSidebar/lib/ -lQhSidebar

INCLUDEPATH += $$PWD/../QhSidebar/include
