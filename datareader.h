#ifndef DATAREADER_H
#define DATAREADER_H
#include "QString"
#include <QtSql>

class DataReader
{
public:
    DataReader();
    QList<QPair<QString, float_t>> SQLReader(QString path);
};

#endif // DATAREADER_H