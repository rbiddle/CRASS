#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "iostream"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionDebug_Mode_triggered()
{
    if( ui->actionDebug_Mode->isChecked() ) {
        ui->tabWidget->insertTab(0,ui->debugDataTab,"Debug Data");
        ui->tabWidget->setCurrentWidget(ui->debugDataTab);
    } else {
        ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->debugDataTab));
    }
}
