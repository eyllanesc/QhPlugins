#ifndef QHSIDEBARDIALOG_H
#define QHSIDEBARDIALOG_H

#include <qhsidebar.h>
#include <QDialogButtonBox>
#include <QDialog>

class QhSidebarDialog : public QDialog
{
    Q_OBJECT
public:
    QhSidebarDialog(QhSidebar *plugin = 0, QWidget *parent = 0);
    QSize sizeHint() const Q_DECL_OVERRIDE;

private:
    QhSidebar *editor;
    QhSidebar *sidebar;
    QDialogButtonBox *buttonBox;
};

#endif // QHSIDEBARDIALOG_H
