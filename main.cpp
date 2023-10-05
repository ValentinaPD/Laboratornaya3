#include "mainwindow.h"
#include <QApplication>
#include <ioccontainer.h>
#include <datareader.h>
int IOCContainer::s_nextTypeId = 115094801;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

   // Win win(0);
   //    win.show();
    //IOCContainer injector;

    //injector.RegisterInstance<DataReader, SQLDataReader>();
    //auto dataReader = injector.GetObject<DataReader>();
    //dataReader->GetData("C:\\TRPOLabs\\Laboratornaya3\\TEMPERATURE_NOVOSIB.sqlite");
    //DataReader dr;
    //dr.SQLReader("C:\\TRPOLabs\\Laboratornaya3\\TEMPERATURE_NOVOSIB.sqlite");
    //dr.JSONReader("C://DataJSON.json");
    w.show();

    return a.exec();
}
