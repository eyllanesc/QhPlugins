#ifndef QHSIDEBAR_H
#define QHSIDEBAR_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QIcon>
#include <QAction>

#include <QtUiPlugin/QDesignerExportWidget>

class QDESIGNER_WIDGET_EXPORT QhSidebar : public QWidget
{
    Q_OBJECT

public:
    QhSidebar(QWidget *parent = 0);
    ~QhSidebar();

    void addAction(QAction *action);
    QAction *addAction(const QString &text, const QIcon &icon = QIcon());
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    QSize minimumSizeHint() const;

    QAction* actionAt(const QPoint &at);
private:
    QList<QAction*> _actions;
    QAction *_pressedAction;
    QAction *_checkedAction;

    int action_height = 90;
};

#endif
