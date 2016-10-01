#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->qhSidebar->addAction(tr("Compras"));
    ui->qhSidebar->addAction(tr("ventas"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
