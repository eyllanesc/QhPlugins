#ifndef QHSIDEBARTASKMENU_H
#define QHSIDEBARTASKMENU_H

#include <QDesignerTaskMenuExtension>
#include <QExtensionFactory>

#include <qhsidebar.h>

class QhSidebarTaskmenu: public QObject, public QDesignerTaskMenuExtension
{
    Q_OBJECT
    Q_INTERFACES(QDesignerTaskMenuExtension)
public:
    QhSidebarTaskmenu(QhSidebar *sidebar,  QObject *parent);
    QAction *preferredEditAction() const Q_DECL_OVERRIDE;
    QList<QAction *> taskActions() const Q_DECL_OVERRIDE;
private slots:
    void editItems();

private:
    QAction *editItemsAction;
    QhSidebar *m_sidebar;
};


class QhSidebarMenuFactory: public QExtensionFactory
{
    Q_OBJECT
public:
    QhSidebarMenuFactory(QExtensionManager *parent = 0);

protected:
    QObject *createExtension(QObject *object, const QString &iid, QObject *parent) const Q_DECL_OVERRIDE;

};

#endif // QHSIDEBARTASKMENU_H
