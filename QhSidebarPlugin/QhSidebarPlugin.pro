QT          += widgets uiplugin

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
sources.files = $$SOURCES $$HEADERS *.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/designer/qhsidebarplugin
INSTALLS += target sources

}

INCLUDEPATH += $$PWD/include

HEADERS     = $$PWD/include/qhsidebar.h \
              $$PWD/include/qhsidebarplugin.h

SOURCES     = $$PWD/src/qhsidebar.cpp \
              $$PWD/src/qhsidebarplugin.cpp

RESOURCES += \
    icons.qrc

DESTDIR = $$PWD/lib
