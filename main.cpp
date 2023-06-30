#include "mainwindow.h"
#include <QApplication>
#include "datareader.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    DataReader dr;
    //dr.SQLReader("C:\\TRPOLabs\\Laboratornaya3\\TEMPERATURE_NOVOSIB.sqlite");
    dr.JSONReader("C://DataJSON.json");
    w.show();

    return a.exec();
}
