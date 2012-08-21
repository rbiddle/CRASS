#include <QtGui/QApplication>
#include "mainwindow.h"
#include "stdio.h"
#include "iostream"

#include "objects/cocinvestigator.h"
#include "objects/coc6e1920investigator.h"
#include "objects/cocgaslightinvestigator.h"

CoC6e1920Investigator objCoC6e1920Inv;
CoCGaslightInvestigator objCoCGaslightInv;
Investigator * investigatorPtr;
CoCInvestigator * cocInvestigatorPtr;
QString saveFileName = "";
std::string charType = "";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
