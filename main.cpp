#include <QtGui/QApplication>
#include "mainwindow.h"
#include "stdio.h"
#include "iostream"

#include "objects/coc1920investigator.h"

int main(int argc, char *argv[])
{
    CoC1920Investigator test = CoC1920Investigator();
    test.setCharName("James McGregor");
    test.setPlayerName("Rob B.");
    test.setCharDesc("A shifty man...");
    test.setStats();
    test.setIncome();
    test.OutputInvestigator();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
