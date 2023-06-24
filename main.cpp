#include "mainwindow.h"
#include <QApplication>
#include <QtSql>
#include <QTableView>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
       dbase.setDatabaseName("C:\\TRPOLabs\\Laboratornaya3\\TEMPERATURE_NOVOSIB.sqlite");
       if (!dbase.open()) {
           qDebug() << "Что-то не так с соединением!";
           return -1;
       }

       QTableView view;
       QSqlTableModel model;

       QList<QPair<QString, float_t>> data;

       QStringList tables = dbase.tables();
       QString table = tables.first();
       auto query = QSqlQuery("SELECT * FROM " + table + " ");
       while(query.next())
       {
          data.append(qMakePair(query.value(0).toString(), query.value(1).toFloat()));
       }
       model.setTable("my_table");
       model.select();
       model.setEditStrategy(QSqlTableModel::OnFieldChange);

       view.setModel(&model);
       view.show();

    //w.show();

    return a.exec();
}
