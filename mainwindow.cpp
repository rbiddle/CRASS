#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QMessageBox"

#include "iostream"
#include "objects/coc6e1920investigator.h"
#include "objects/cocgaslightinvestigator.h"

extern CoC6e1920Investigator objCoC6e1920Inv;
extern CoCGaslightInvestigator objCoCGaslightInv;
extern Investigator * investigatorPtr;
extern QString saveFileName;

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
        ui->actionOutput_Investigator->setVisible(true);
    } else {
        ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->debugDataTab));
        ui->debugTextArea->setText("");
        ui->actionOutput_Investigator->setVisible(false);
    }
}

void MainWindow::on_action6th_Edition_1920s_Investigator_triggered()
{
    objCoC6e1920Inv = CoC6e1920Investigator();
    objCoC6e1920Inv.createInvestigator("Chester the Character", "Rob the Player", "A shifty man...");
    objCoC6e1920Inv.incrSkillOcpn("headbutt", 10);
    objCoC6e1920Inv.incrSkillPrsn("Head Butt", 15);
    investigatorPtr = &objCoC6e1920Inv;

    // TODO: Clear Form fields and erase existing 1920s Investigator

    // TODO: Enable Save/Save As...
}

void MainWindow::on_actionOpen_triggered()
{
    saveFileName = QFileDialog::getOpenFileName(this->parentWidget()
                                           ,"Open File"
                                           ,""
                                           ,"CRASS Files (*.crass);;Byakhee Files (*.coc)");
    ui->debugTextArea->setText(saveFileName);
    investigatorPtr->loadInvestigator(saveFileName.toStdString());
    // TODO: Open File

    // TODO: Enable Save/Save As... if a file was opened and loaded
}

void MainWindow::on_actionSave_triggered()
{
    if (saveFileName == "") {
        this->on_actionSave_As_triggered();
    } else {
        investigatorPtr->saveInvestigator(saveFileName.toStdString());
        ui->debugTextArea->setText(saveFileName);
    }
}

void MainWindow::on_actionOutput_Investigator_triggered()
{
    ui->debugTextArea->setText(objCoC6e1920Inv.debugOutputInvestigator().c_str());
}

void MainWindow::on_actionSave_As_triggered()
{
    saveFileName = QFileDialog::getSaveFileName(this->parentWidget()
                                           ,"Open File"
                                           ,""
                                           ,"CRASS Files (*.crass)");
    ui->debugTextArea->setText(saveFileName);
    investigatorPtr->saveInvestigator(saveFileName.toStdString());
    // TODO: Save File
}

void MainWindow::on_actionExport_triggered()
{
    // TODO: Add export to Byakhee format (PDF?, Other?)
    QMessageBox msgBox;
    msgBox.setText("This Feature is not yet implemented");
    msgBox.exec();
}

void MainWindow::on_actionGaslight_Investigator_triggered()
{
    // TODO: Create Gaslight Character
    QMessageBox msgBox;
    msgBox.setText("This Feature is not yet implemented");
    msgBox.exec();
}

void MainWindow::on_actionHelp_triggered()
{
    // TODO: Pop up dialogue for about/help (link to Wiki)
    QMessageBox msgBox;
    msgBox.setText("This Feature is not yet implemented");
    msgBox.exec();
}
