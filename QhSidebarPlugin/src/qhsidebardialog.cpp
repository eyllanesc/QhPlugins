#include "qhsidebardialog.h"

#include <QVBoxLayout>
#include <QVariant>

QhSidebarDialog::QhSidebarDialog(QhSidebar *plugin, QWidget *parent):
    QDialog(parent),
    editor(new QhSidebar),
    sidebar(plugin),
    buttonBox(new QDialogButtonBox(QDialogButtonBox::Ok
                                   | QDialogButtonBox::Cancel
                                   | QDialogButtonBox::Reset))
{

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(editor);
    mainLayout->addWidget(buttonBox);

    setLayout(mainLayout);
    setWindowTitle(tr("Edit Actions"));
}

QSize QhSidebarDialog::sizeHint() const
{
    return QSize(250, 250);
}
