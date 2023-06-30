#include "datareader.h"

DataReader::DataReader()
{

}
QList<QPair<QString, float_t>> DataReader::SQLReader(QString path){
       QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
       dbase.setDatabaseName(path);
       if (!dbase.open()) {
           qDebug() << "Что-то не так с соединением!";
       }
       QList<QPair<QString, float_t>> data;

       QStringList tables = dbase.tables();
       QString table = tables.first();
       auto query = QSqlQuery("SELECT * FROM " + table + " ");
       while(query.next())
       {
          data.append(qMakePair(query.value(0).toString(), query.value(1).toFloat()));
          qDebug() << query.value(0).toString();
       }
       return data;

}
