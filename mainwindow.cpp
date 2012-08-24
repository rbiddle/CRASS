#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QMessageBox"
#include "QSignalMapper"

#include "iostream"
#include "sstream"
#include "vector"
#include "objects/cocinvestigator.h"
#include "objects/coc6e1920investigator.h"
#include "objects/cocgaslightinvestigator.h"

extern CoC6e1920Investigator objCoC6e1920Inv;
extern CoCGaslightInvestigator objCoCGaslightInv;
extern Investigator * investigatorPtr;
extern CoCInvestigator * cocInvestigatorPtr;
extern QString saveFileName;
extern std::string charType;
std::vector<skillStruct> cocSkillList;
QPushButton *cocSkillButtons[200];
QPushButton *currentCoCSkillButton;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->cocBasicTab));
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->cocSkillTab));
    ui->actionSave->setEnabled(false);
    ui->actionSave_As->setEnabled(false);
    ui->actionExport->setEnabled(false);
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
        ui->cocMaxSanLineEdit->setText( intToString(99 - cocInvestigatorPtr->getSkillPts("cthulhumythos")).c_str() );
        ui->cocCharDescTextEdit->setPlainText( cocInvestigatorPtr->getCharDesc().c_str() );
        ui->cocMaxHPLabel->setText( intToString(cocInvestigatorPtr->getHP()).c_str() );
        ui->cocMaxSanityLabel->setText( intToString(cocInvestigatorPtr->getSAN()).c_str() );
        ui->cocMaxMPLabel->setText( intToString(cocInvestigatorPtr->getMP()).c_str() );
        ui->cocCurrHPLineEdit->setText( intToString(cocInvestigatorPtr->getHP()).c_str() );
        ui->cocCurrMPLineEdit->setText( intToString(cocInvestigatorPtr->getMP()).c_str() );
        ui->cocCurrSanityLineEdit->setText( intToString(cocInvestigatorPtr->getCurrSan()).c_str() );
    }
}

void MainWindow::refreshCoCSkillsTab() {
    ui->cocTotalOcpnPtsLabel->setText( intToString(cocInvestigatorPtr->getTotalOcpnPts()).c_str() );
    ui->cocTotalPrsnPtsLabel->setText( intToString(cocInvestigatorPtr->getTotalPrsnPts()).c_str() );
    ui->cocRemainingOcpnPtsLabel->setText( intToString(cocInvestigatorPtr->getRemainingOcpnPts()).c_str() );
    ui->cocRemainingPrsnPtsLabel->setText( intToString(cocInvestigatorPtr->getRemainingPrsnPts()).c_str() );

    if ( ui->cocCurrentSkillLineEdit->text() == "" ) {
        ui->cocCurrentSkillOcpnPtsSpinner->setValue(0);
        ui->cocCurrentSkillPrsnPtsSpinner->setValue(0);
        ui->cocCurrentSkillOcpnPtsSlider->setValue(0);
        ui->cocCurrentSkillPrsnPtsSlider->setValue(0);
        ui->cocCurrentSkillOcpnCheckBox->setChecked(false);
        ui->cocCurrentSkillTotal->setText("0");
        ui->cocCurrentSkillBaseLabel->setText("0");
    } else {
        std::string currentSkillName = ui->cocCurrentSkillLineEdit->text().toStdString();
        ui->cocCurrentSkillOcpnPtsSpinner->setValue( cocInvestigatorPtr->getSkillOcpnPts(currentSkillName) );
        ui->cocCurrentSkillPrsnPtsSpinner->setValue( cocInvestigatorPtr->getSkillPrsnPts(currentSkillName) );
        ui->cocCurrentSkillOcpnPtsSlider->setValue( cocInvestigatorPtr->getSkillOcpnPts(currentSkillName) );
        ui->cocCurrentSkillPrsnPtsSlider->setValue( cocInvestigatorPtr->getSkillPrsnPts(currentSkillName) );
        if (cocInvestigatorPtr->isOccupationalSkill(currentSkillName))
            ui->cocCurrentSkillOcpnCheckBox->setChecked(true);
        else
            ui->cocCurrentSkillOcpnCheckBox->setChecked(false);
        ui->cocCurrentSkillTotal->setText( intToString(cocInvestigatorPtr->getSkillPts(currentSkillName)).c_str() );
        ui->cocCurrentSkillBaseLabel->setText( intToString(cocInvestigatorPtr->getSkillBasePts(currentSkillName)).c_str() );

        // TODO: disable up spinner/slider is maxed skill or out of points?
    }
}

void MainWindow::setupCoCSkillButtons(QStringList skills)
{
    QStringList cocBasicSkillList;
    QStringList cocMeleeSkillList;
    QStringList cocFirearmSkillList;
    int buttonsPerColumn = 0;

    skills.sort();
    for (int i = 0; i < skills.size(); ++i) {
        if (skills.at(i).left(2) == "m_") {
            cocMeleeSkillList.push_back(skills[i]);
        } else if (skills.at(i).left(2) == "f_") {
            cocFirearmSkillList.push_back(skills[i]);
        } else {
            cocBasicSkillList.push_back(skills[i]);
        }
    }

    buttonsPerColumn = cocBasicSkillList.size() / 5;
    for (int i = 0; i < cocBasicSkillList.size(); ++i) {
        QStringList cocSkillInfo = cocBasicSkillList.at(i).split("~");
        QString buttonText = cocSkillInfo.at(1) + " (" + cocSkillInfo.at(2) + ")";
        cocSkillButtons[i] = new QPushButton(buttonText);
        cocSkillButtons[i]->setProperty("cocSkillName",cocSkillInfo.at(0));
        connect(cocSkillButtons[i], SIGNAL(clicked()), this, SLOT(cocSkillButtonClicked()));
        if (i < buttonsPerColumn)
            ui->vLayoutSkillsCol1->addWidget(cocSkillButtons[i]);
        else if ( (i >= buttonsPerColumn) && (i < (buttonsPerColumn * 2)) )
            ui->vLayoutSkillsCol2->addWidget(cocSkillButtons[i]);
        else if ( (i >= (buttonsPerColumn * 2)) && (i < (buttonsPerColumn * 3)) )
            ui->vLayoutSkillsCol3->addWidget(cocSkillButtons[i]);
        else if ( (i >= (buttonsPerColumn * 3)) && (i < (buttonsPerColumn * 4)) )
            ui->vLayoutSkillsCol4->addWidget(cocSkillButtons[i]);
        else
            ui->vLayoutSkillsCol5->addWidget(cocSkillButtons[i]);
    }

    buttonsPerColumn = cocMeleeSkillList.size() / 5;
    for (int i = 0; i < cocMeleeSkillList.size(); ++i) {
        QStringList cocSkillInfo = cocMeleeSkillList.at(i).split("~");
        QString buttonText = cocSkillInfo.at(1) + " (" + cocSkillInfo.at(2) + ")";
        cocSkillButtons[i] = new QPushButton(buttonText);
        cocSkillButtons[i]->setProperty("cocSkillName",cocSkillInfo.at(0));
        connect(cocSkillButtons[i], SIGNAL(clicked()), this, SLOT(cocSkillButtonClicked()));
        if (i < buttonsPerColumn)
            ui->vLayoutMeleeSkillsCol1->addWidget(cocSkillButtons[i]);
        else if ( (i >= buttonsPerColumn) && (i < (buttonsPerColumn * 2)) )
            ui->vLayoutMeleeSkillsCol2->addWidget(cocSkillButtons[i]);
        else if ( (i >= (buttonsPerColumn * 2)) && (i < (buttonsPerColumn * 3)) )
            ui->vLayoutMeleeSkillsCol3->addWidget(cocSkillButtons[i]);
        else if ( (i >= (buttonsPerColumn * 3)) && (i < (buttonsPerColumn * 4)) )
            ui->vLayoutMeleeSkillsCol4->addWidget(cocSkillButtons[i]);
        else
            ui->vLayoutMeleeSkillsCol5->addWidget(cocSkillButtons[i]);
    }

    buttonsPerColumn = cocFirearmSkillList.size() / 5;
    for (int i = 0; i < cocFirearmSkillList.size(); ++i) {
        QStringList cocSkillInfo = cocFirearmSkillList.at(i).split("~");
        QString buttonText = cocSkillInfo.at(1) + " (" + cocSkillInfo.at(2) + ")";
        cocSkillButtons[i] = new QPushButton(buttonText);
        cocSkillButtons[i]->setProperty("cocSkillName",cocSkillInfo.at(0));
        connect(cocSkillButtons[i], SIGNAL(clicked()), this, SLOT(cocSkillButtonClicked()));
        if (i < buttonsPerColumn)
            ui->vLayoutFirearmSkillsCol1->addWidget(cocSkillButtons[i]);
        else if ( (i >= buttonsPerColumn) && (i < (buttonsPerColumn * 2)) )
            ui->vLayoutFirearmSkillsCol2->addWidget(cocSkillButtons[i]);
        else if ( (i >= (buttonsPerColumn * 2)) && (i < (buttonsPerColumn * 3)) )
            ui->vLayoutFirearmSkillsCol3->addWidget(cocSkillButtons[i]);
        else if ( (i >= (buttonsPerColumn * 3)) && (i < (buttonsPerColumn * 4)) )
            ui->vLayoutFirearmSkillsCol4->addWidget(cocSkillButtons[i]);
        else
            ui->vLayoutFirearmSkillsCol5->addWidget(cocSkillButtons[i]);
    }
}

void MainWindow::cocSkillButtonClicked()
{
    currentCoCSkillButton = (QPushButton *)sender();
    std::string cocSkillName = currentCoCSkillButton->text().toStdString();

    ui->cocCurrentSkillLineEdit->setText( cocSkillName.substr(0,cocSkillName.find_last_of("(")-1).c_str() );

    this->refreshCoCSkillsTab();
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
    this->refreshCoCBasicDataTab();
    this->refreshCoCSkillsTab();
    ui->tabWidget->setCurrentWidget(ui->cocBasicTab);
    ui->actionSave->setEnabled(true);
    ui->actionSave_As->setEnabled(true);
    ui->actionExport->setEnabled(true);

    // TODO: Clear Form fields and erase existing 1920s Investigator
    // TODO: set occupations list
    ui->cocOccupationComboBox->addItem("Occuaption_1");
    ui->cocOccupationComboBox->addItem("Occuaption_2");
    ui->cocOccupationComboBox->addItem("Occuaption_3");
    cocInvestigatorPtr->addOccupationalSkill("Dodge");

    // TODO: setup Skills tab buttons (Occupation and customized)
    QStringList cocSkills;
    cocSkillList = cocInvestigatorPtr->getSkillList();
    for ( unsigned int i=0; i < cocSkillList.size(); i++ ) {
        int val = cocSkillList[i].baseVal + cocSkillList[i].incrOcpn + cocSkillList[i].incrPrsn;
        std::string buttonText = cocSkillList[i].name + "~" + cocSkillList[i].desc + "~" + intToString(val);
        cocSkills.push_back(buttonText.c_str());
    }
    this->setupCoCSkillButtons(cocSkills);
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

void MainWindow::on_cocCurrentSkillOcpnPtsSpinner_valueChanged(int arg1)
{
    std::string currentSkillName = ui->cocCurrentSkillLineEdit->text().toStdString();
    ui->cocCurrentSkillOcpnPtsSlider->setValue(arg1);
    cocInvestigatorPtr->incrSkillOcpn(currentSkillName, arg1);
    this->refreshCoCSkillsTab();
    ui->cocCurrentSkillTotal->setText( intToString(cocInvestigatorPtr->getSkillPts(currentSkillName)).c_str() );

    // TODO: Update Skill Button
    // TODO: Update Spinner/Slider Maxes
}

void MainWindow::on_cocCurrentSkillPrsnPtsSpinner_valueChanged(int arg1)
{
    std::string currentSkillName = ui->cocCurrentSkillLineEdit->text().toStdString();
    ui->cocCurrentSkillPrsnPtsSlider->setValue(arg1);
    cocInvestigatorPtr->incrSkillPrsn(currentSkillName, arg1);
    this->refreshCoCSkillsTab();
    ui->cocCurrentSkillTotal->setText( intToString(cocInvestigatorPtr->getSkillPts(currentSkillName)).c_str() );

    // TODO: Update Skill Button
}

void MainWindow::on_cocCurrentSkillOcpnPtsSlider_valueChanged(int value)
{
    std::string currentSkillName = ui->cocCurrentSkillLineEdit->text().toStdString();
    ui->cocCurrentSkillOcpnPtsSpinner->setValue(value);
    cocInvestigatorPtr->incrSkillOcpn(currentSkillName, value);
    this->refreshCoCSkillsTab();
    ui->cocCurrentSkillTotal->setText( intToString(cocInvestigatorPtr->getSkillPts(currentSkillName)).c_str() );

    // TODO: Update Skill Button
}

void MainWindow::on_cocCurrentSkillPrsnPtsSlider_valueChanged(int value)
{
    std::string currentSkillName = ui->cocCurrentSkillLineEdit->text().toStdString();
    ui->cocCurrentSkillPrsnPtsSpinner->setValue(value);
    cocInvestigatorPtr->incrSkillPrsn(currentSkillName, value);
    this->refreshCoCSkillsTab();
    ui->cocCurrentSkillTotal->setText( intToString(cocInvestigatorPtr->getSkillPts(currentSkillName)).c_str() );

    // TODO: Update Skill Button
}

void MainWindow::on_cocCurrentSkillOcpnCheckBox_clicked()
{
    // TODO: make Current Skill an Occupational Skill
}

void MainWindow::on_tabWidget_selected(const QString &arg1)
{
    if( (arg1 == "Skills") && cocInvestigatorPtr ) {
        this->refreshCoCSkillsTab();
    } else {

    }
}

void MainWindow::on_cocCurrentSkillLineEdit_editingFinished()
{
    this->refreshCoCSkillsTab();
}

void MainWindow::on_create6e1920InvestigatorPushButton_clicked()
{
    ui->action6th_Edition_1920s_Investigator->trigger();
}
