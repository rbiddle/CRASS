#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QMessageBox"

#include "iostream"
#include "sstream"
#include "objects/cocinvestigator.h"
#include "objects/coc6e1920investigator.h"
#include "objects/cocgaslightinvestigator.h"

extern CoC6e1920Investigator objCoC6e1920Inv;
extern CoCGaslightInvestigator objCoCGaslightInv;
extern Investigator * investigatorPtr;
extern CoCInvestigator * cocInvestigatorPtr;
extern QString saveFileName;
extern std::string charType;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->cocBasicTab));
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->cocSkillTab));
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::string MainWindow::intToString(int inInt)
{
    std::string output;
    std::stringstream stream;

    stream << inInt;
    output = stream.str();

    return output;
}

void MainWindow::refreshCoCBasicDataTab()
{
    if (cocInvestigatorPtr) {
        ui->cocInvestigatorNameLineEdit->setText( cocInvestigatorPtr->getCharName().c_str() );
        ui->cocPlayerNameLineEdit->setText( cocInvestigatorPtr->getPlayerName().c_str() );
        ui->cocEducationLineEdit->setText( cocInvestigatorPtr->getEducation().c_str() );
        ui->cocBirthplaceLineEdit->setText( cocInvestigatorPtr->getBirthplace().c_str() );
        ui->cocDisordersLineEdit->setText( cocInvestigatorPtr->getDisorders().c_str() );
        ui->cocSexLineEdit->setText( cocInvestigatorPtr->getSex().c_str() );
        ui->cocAgeSpinner->setValue( cocInvestigatorPtr->getAge() );
        ui->cocSTRSpinner->setValue( cocInvestigatorPtr->getSTR() );
        ui->cocDEXSpinner->setValue( cocInvestigatorPtr->getDEX() );
        ui->cocINTSpinner->setValue( cocInvestigatorPtr->getINT() );
        ui->cocCONSpinner->setValue( cocInvestigatorPtr->getCON() );
        ui->cocAPPSpinner->setValue( cocInvestigatorPtr->getAPP() );
        ui->cocPOWSpinner->setValue( cocInvestigatorPtr->getPOW() );
        ui->cocSIZSpinner->setValue( cocInvestigatorPtr->getSIZ() );
        ui->cocSANSpinner->setValue( cocInvestigatorPtr->getSAN() );
        ui->cocEDUSpinner->setValue( cocInvestigatorPtr->getEDU() );
        ui->cocIdeaLineEdit->setText( intToString(cocInvestigatorPtr->getIDEA()).c_str() );
        ui->cocLuckLineEdit->setText( intToString(cocInvestigatorPtr->getLUCK()).c_str() );
        ui->cocKnowLineEdit->setText( intToString(cocInvestigatorPtr->getKNOW()).c_str() );
        ui->cocDamageBonusLineEdit->setText( cocInvestigatorPtr->getDmgBonus().c_str() );
        ui->cocMaxSanLineEdit->setText( intToString(99 - cocInvestigatorPtr->getSkill("cthulhumythos")).c_str() );
        ui->cocCharDescTextEdit->setPlainText( cocInvestigatorPtr->getCharDesc().c_str() );
        ui->cocMaxHPLabel->setText( intToString(cocInvestigatorPtr->getHP()).c_str() );
        ui->cocMaxSanityLabel->setText( intToString(cocInvestigatorPtr->getSAN()).c_str() );
        ui->cocMaxMPLabel->setText( intToString(cocInvestigatorPtr->getMP()).c_str() );
        ui->cocCurrHPLineEdit->setText( intToString(cocInvestigatorPtr->getHP()).c_str() );
        ui->cocCurrMPLineEdit->setText( intToString(cocInvestigatorPtr->getMP()).c_str() );
        ui->cocCurrSanityLineEdit->setText( intToString(cocInvestigatorPtr->getCurrSan()).c_str() );
    }
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
    cocInvestigatorPtr = &objCoC6e1920Inv;
    charType = "CoC_1920";

    ui->tabWidget->insertTab(ui->tabWidget->indexOf(ui->menuTab)+1, ui->cocBasicTab, "Basic Data && Charactaristics");
    ui->tabWidget->insertTab(ui->tabWidget->indexOf(ui->menuTab)+2, ui->cocSkillTab, "Skills");
    ui->tabWidget->setCurrentWidget(ui->cocBasicTab);

    // TODO: Clear Form fields and erase existing 1920s Investigator
    // TODO: Enable Save/Save As...
    // TODO: set occupations list
    ui->cocOccupationComboBox->addItem("Occuaption_1");
    ui->cocOccupationComboBox->addItem("Occuaption_2");
    ui->cocOccupationComboBox->addItem("Occuaption_3");

    this->refreshCoCBasicDataTab();
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

void MainWindow::on_cocInvestigatorNameLineEdit_editingFinished()
{
    cocInvestigatorPtr->setCharName( ui->cocInvestigatorNameLineEdit->text().toStdString() );
}

void MainWindow::on_cocPlayerNameLineEdit_editingFinished()
{
    cocInvestigatorPtr->setPlayerName( ui->cocPlayerNameLineEdit->text().toStdString() );
}

void MainWindow::on_cocEducationLineEdit_editingFinished()
{
    cocInvestigatorPtr->setEducation( ui->cocEducationLineEdit->text().toStdString() );
}

void MainWindow::on_cocBirthplaceLineEdit_editingFinished()
{
    cocInvestigatorPtr->setBirthplace( ui->cocBirthplaceLineEdit->text().toStdString() );
}

void MainWindow::on_cocDisordersLineEdit_editingFinished()
{
    cocInvestigatorPtr->setDisorders( ui->cocDisordersLineEdit->text().toStdString() );
}

void MainWindow::on_cocSexLineEdit_editingFinished()
{
    cocInvestigatorPtr->setSex( ui->cocSexLineEdit->text().toStdString() );
}

void MainWindow::on_cocAgeSpinner_editingFinished()
{
    // TODO: check age and see about STR/CON/etc.. adjustments
}

void MainWindow::on_cocOccupationComboBox_editTextChanged(const QString &arg1)
{
    cocInvestigatorPtr->setOccupation( arg1.toStdString() );
}

void MainWindow::on_cocSTRSpinner_valueChanged(int arg1)
{
    cocInvestigatorPtr->setSTR(arg1);
    this->refreshCoCBasicDataTab();
}

void MainWindow::on_pushButton_clicked()
{
    ui->action6th_Edition_1920s_Investigator->trigger();
}

void MainWindow::on_cocCONSpinner_valueChanged(int arg1)
{
    cocInvestigatorPtr->setCON(arg1);
    this->refreshCoCBasicDataTab();
}

void MainWindow::on_cocSIZSpinner_valueChanged(int arg1)
{
    cocInvestigatorPtr->setSIZ(arg1);
    this->refreshCoCBasicDataTab();
}

void MainWindow::on_cocDEXSpinner_valueChanged(int arg1)
{
    cocInvestigatorPtr->setDEX(arg1);
    this->refreshCoCBasicDataTab();
}

void MainWindow::on_cocAPPSpinner_valueChanged(int arg1)
{
    cocInvestigatorPtr->setAPP(arg1);
    this->refreshCoCBasicDataTab();
}

void MainWindow::on_cocSANSpinner_valueChanged(int arg1)
{
    cocInvestigatorPtr->setSAN(arg1);
    this->refreshCoCBasicDataTab();
}

void MainWindow::on_cocINTSpinner_valueChanged(int arg1)
{
    cocInvestigatorPtr->setINT(arg1);
    this->refreshCoCBasicDataTab();
}

void MainWindow::on_cocPOWSpinner_valueChanged(int arg1)
{
    cocInvestigatorPtr->setPOW(arg1);
    this->refreshCoCBasicDataTab();
}

void MainWindow::on_cocEDUSpinner_valueChanged(int arg1)
{
    cocInvestigatorPtr->setEDU(arg1);
    this->refreshCoCBasicDataTab();
}

void MainWindow::on_cocCharDescTextEdit_textChanged()
{
    cocInvestigatorPtr->setCharDesc(ui->cocCharDescTextEdit->toPlainText().toStdString());
}
