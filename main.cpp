#include <QtGui/QApplication>
#include "mainwindow.h"
#include "stdio.h"
#include "iostream"

#include "objects/coc1920investigator.h"

int main(int argc, char *argv[])
{
    CoC1920Investigator test = CoC1920Investigator();
    test.create1920Investigator();
    test.setCharDesc("A shifty man...");

    test.incrSkillOcpn("headbutt", 10);
    test.incrSkillPrsn("Head Butt", 15);

    test.OutputInvestigator();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
