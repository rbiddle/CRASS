#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_actionDebug_Mode_triggered();

    void on_action6th_Edition_1920s_Investigator_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionOutput_Investigator_triggered();

    void on_actionSave_As_triggered();

    void on_actionExport_triggered();

    void on_actionGaslight_Investigator_triggered();

    void on_actionHelp_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
