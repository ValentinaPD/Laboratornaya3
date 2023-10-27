#include "datareader.h"

SQLDataReader::SQLDataReader() {}

QList<QPair<QString, float_t>> SQLDataReader::GetData(const QString& path){
    try {
        if(!IsExist(path)){
            throw QString("База данных с именем \"" + path + "\" не существет!");
        }
        QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
        dbase.setDatabaseName(path);

        if (!dbase.open()) {
            throw QString("Что-то не так с соединением!");
        }
        QList<QPair<QString, float_t>> data;

        QStringList tables = dbase.tables();
        QString table = tables.first();
        auto query = QSqlQuery("SELECT * FROM " + table + " ");
        while(query.next())
        {
           data.append(qMakePair(query.value(0).toString(), query.value(1).toFloat()));

        }

        return data;
    }
    catch(const QString& ex) {
        qDebug() << ex;
    }
}

JSONDataReader::JSONDataReader() {}

QList<QPair<QString, float_t>> JSONDataReader::GetData(const QString& path){
    try {
        if(!IsExist(path)){
            throw QString("Невозможно открыть файл \"" + path + "\"");
        }
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

           }
           if (data.isEmpty()) {
               throw QString("Файл \"" + path + "\" пуст");
           }
        }
        else {
          throw QString("Невозможно прочитать файл \"" + path + "\"");
        }
        return data;
    }
    catch (const QString& ex){
        qDebug() << ex;
    }
}

bool SQLDataReader::IsExist(const QString& path){
    return QFileInfo::exists(path);
}

bool JSONDataReader::IsExist(const QString& path){
    return QFileInfo::exists(path);
}

