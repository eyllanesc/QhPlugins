#include "qhsidebartaskmenu.h"

#include <qhsidebar.h>

#include <QtDesigner/QDesignerFormEditorInterface>
#include <QAction>

#include <qhsidebardialog.h>

QhSidebarTaskmenu::QhSidebarTaskmenu(QhSidebar *sidebar, QObject *parent):
    QObject(parent),
    editItemsAction(new QAction(tr("Edit Actions..."), this)),
    m_sidebar(sidebar)
{
    connect(editItemsAction, &QAction::triggered, this, &QhSidebarTaskmenu::editItems);
}

QAction *QhSidebarTaskmenu::preferredEditAction() const
{
    return editItemsAction;
}

QList<QAction *> QhSidebarTaskmenu::taskActions() const
{
    QList<QAction *> list;
    list.append(editItemsAction);
    return list;
}

void QhSidebarTaskmenu::editItems()
{
    QhSidebarDialog dialog(m_sidebar);
    dialog.exec();

}


QhSidebarMenuFactory::QhSidebarMenuFactory(QExtensionManager *parent):
    QExtensionFactory(parent)
{

}

QObject *QhSidebarMenuFactory::createExtension(QObject *object, const QString &iid, QObject *parent) const
{
    if (iid != Q_TYPEID(QDesignerTaskMenuExtension))
            return 0;

        if (QhSidebar *sidebar = qobject_cast<QhSidebar*>(object))
            return new QhSidebarTaskmenu(sidebar, parent);

        return 0;
}
