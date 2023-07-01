#include "datareader.h"

QList<QPair<QString, float_t>> SQLDataReader::GetData(QString path){
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
QList<QPair<QString, float_t>> JSONDataReader::GetData(QString path){
    QFile file(path);
    QList<QPair<QString, float_t>> data;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
       QJsonDocument document = QJsonDocument::fromJson(file.readAll());
       file.close();

       QJsonObject object = document.object();
       QListIterator<QString> iterator(object.keys());
       while (iterator.hasNext()) {
           QString key=iterator.next();
           double value =object.value(key).toDouble();
           data.append(qMakePair(key,value));
           qDebug() << object.value(key).toDouble();
       }
       if (data.isEmpty()) {
           qDebug()<<"Ошибка. Файл пуст";
       }
    }
    else {
       qDebug()<<"Ошибка. Файл не читается";
    }
    return data;

}

bool SQLDataReader::IsOpen(QString path){
    return false;
}
bool SQLDataReader::IsEmpty(QString path){
    return false;
}

bool JSONDataReader::IsOpen(QString path){
    return false;
}
bool JSONDataReader::IsEmpty(QString path){
    return false;
}

