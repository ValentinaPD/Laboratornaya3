#ifndef DATAREADER_H
#define DATAREADER_H
#include "QString"
#include <QtSql>

class DataReader{
    DataReader();

};
class SQLDataReader{
    SQLDataReader(){};
    QList<QPair<QString, float_t>> GetData(QString path);
};
class JSONDataReader{
    JSONDataReader(){};
    QList<QPair<QString, float_t>> GetData(QString path);
};


#endif // DATAREADER_H
