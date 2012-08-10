#include <QtGui/QApplication>
#include "mainwindow.h"
#include "stdio.h"
#include "iostream"

#include "objects/coc1920investigator.h"

int main(int argc, char *argv[])
{
    CoC1920Investigator test = CoC1920Investigator();
    std::cout << "Test: " << test.rollDice(2,10) << " ( ";
    std::cout << test.getDieRoll() << " )" << std::endl;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
