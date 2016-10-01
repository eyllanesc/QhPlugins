#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(960, 720);
    ui->qhSidebar->addAction(tr("Compras"));
    ui->qhSidebar->addAction(tr("Ventas"));
    ui->qhSidebar->addAction(tr("Contabilidad"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
