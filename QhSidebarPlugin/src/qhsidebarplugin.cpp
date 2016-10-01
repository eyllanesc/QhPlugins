#include "qhsidebar.h"
#include "qhsidebarplugin.h"

#include <QtPlugin>

QhSidebarPlugin::QhSidebarPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void QhSidebarPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool QhSidebarPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *QhSidebarPlugin::createWidget(QWidget *parent)
{
    return new QhSidebar(parent);
}

QString QhSidebarPlugin::name() const
{
    return QLatin1String("QhSidebar");
}

QString QhSidebarPlugin::group() const
{
    return QLatin1String("Sidebar");
}

QIcon QhSidebarPlugin::icon() const
{
    return QIcon(QLatin1String(":/quipa.png"));
}

QString QhSidebarPlugin::toolTip() const
{
    return QLatin1String("Sidebar");
}

QString QhSidebarPlugin::whatsThis() const
{
    return QLatin1String("Sidebar");
}

bool QhSidebarPlugin::isContainer() const
{
    return false;
}

QString QhSidebarPlugin::domXml() const
{
    return QLatin1String("<widget class=\"QhSidebar\" name=\"qhSidebar\">\n</widget>\n");
}

QString QhSidebarPlugin::includeFile() const
{
    return QLatin1String("qhsidebar.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(qhsidebarplugin, QhSidebarPlugin)
#endif // QT_VERSION < 0x050000
