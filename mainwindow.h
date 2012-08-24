#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QPushButton"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void refreshCoCBasicDataTab();
    void refreshCoCSkillsTab();
    void setupCoCSkillButtons(QStringList skills);

private slots:
    void cocSkillButtonClicked();

    void on_actionDebug_Mode_triggered();

    void on_action6th_Edition_1920s_Investigator_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionOutput_Investigator_triggered();

    void on_actionSave_As_triggered();

    void on_actionExport_triggered();

    void on_actionGaslight_Investigator_triggered();

    void on_actionHelp_triggered();

    void on_cocInvestigatorNameLineEdit_editingFinished();

    void on_cocPlayerNameLineEdit_editingFinished();

    void on_cocEducationLineEdit_editingFinished();

    void on_cocBirthplaceLineEdit_editingFinished();

    void on_cocDisordersLineEdit_editingFinished();

    void on_cocSexLineEdit_editingFinished();

    void on_cocAgeSpinner_editingFinished();

    void on_cocOccupationComboBox_editTextChanged(const QString &arg1);

    void on_cocSTRSpinner_valueChanged(int arg1);

    void on_cocCONSpinner_valueChanged(int arg1);

    void on_cocSIZSpinner_valueChanged(int arg1);

    void on_cocDEXSpinner_valueChanged(int arg1);

    void on_cocAPPSpinner_valueChanged(int arg1);

    void on_cocSANSpinner_valueChanged(int arg1);

    void on_cocINTSpinner_valueChanged(int arg1);

    void on_cocPOWSpinner_valueChanged(int arg1);

    void on_cocEDUSpinner_valueChanged(int arg1);

    void on_cocCharDescTextEdit_textChanged();

    void on_cocCurrentSkillOcpnPtsSpinner_valueChanged(int arg1);

    void on_cocCurrentSkillPrsnPtsSpinner_valueChanged(int arg1);

    void on_cocCurrentSkillOcpnPtsSlider_valueChanged(int value);

    void on_cocCurrentSkillPrsnPtsSlider_valueChanged(int value);

    void on_cocCurrentSkillOcpnCheckBox_clicked();

    void on_tabWidget_selected(const QString &arg1);

    void on_cocCurrentSkillLineEdit_editingFinished();

    void on_create6e1920InvestigatorPushButton_clicked();

private:
    Ui::MainWindow *ui;
    std::string intToString(int inInt);
};

#endif // MAINWINDOW_H
