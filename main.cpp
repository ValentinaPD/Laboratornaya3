#include "mainwindow.h"
#include <QApplication>
#include <ioccontainer.h>
#include <datareader.h>
#include <datahandler.h>
int IOCContainer::s_nextTypeId = 115094801;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
