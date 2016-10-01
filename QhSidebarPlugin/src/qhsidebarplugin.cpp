#include <qhsidebar.h>
#include "qhsidebarplugin.h"

#include <QtDesigner/QDesignerFormEditorInterface>
#include <QtDesigner/QExtensionManager>
#include <QtPlugin>

#include <qhsidebartaskmenu.h>

QhSidebarPlugin::QhSidebarPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void QhSidebarPlugin::initialize(QDesignerFormEditorInterface *formEditor)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    QExtensionManager *manager = formEditor->extensionManager();
    Q_ASSERT(manager != 0);

    manager->registerExtensions(new QhSidebarMenuFactory(manager),
                                Q_TYPEID(QDesignerTaskMenuExtension));

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
    return QLatin1String("Qhipa Widgets");
}

QIcon QhSidebarPlugin::icon() const
{
    return QIcon(QLatin1String(":/sidebar.png"));
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
