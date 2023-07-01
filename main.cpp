#include "mainwindow.h"
#include <QApplication>
#include <ioccontainer.h>
#include <datareader.h>
#include <win.h>
int IOCContainer::s_nextTypeId = 115094801;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // MainWindow w;

    Win win;
       win.show();
    //IOCContainer injector;

    //injector.RegisterInstance<DataReader, SQLDataReader>();
    //auto dataReader = injector.GetObject<DataReader>();
    //dataReader->GetData("C:\\TRPOLabs\\Laboratornaya3\\TEMPERATURE_NOVOSIB.sqlite");
    //processor->Set(3.1,ProcessorType::x64,"78");
    //Computer computer(processor.get());
    //cout<<computer.GetProcessorInfo()<<endl;
    //DataReader dr;
    //dr.SQLReader("C:\\TRPOLabs\\Laboratornaya3\\TEMPERATURE_NOVOSIB.sqlite");
    //dr.JSONReader("C://DataJSON.json");
   // w.show();

    return a.exec();
}
