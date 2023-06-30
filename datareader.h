#ifndef DATAREADER_H
#define DATAREADER_H
#include "QString"
#include <QtSql>

class DataReader{
public:
    DataReader();
    virtual QString GetData(QString path);
protected:
    virtual bool IsOpen(QString path) = 0;
    virtual bool IsEmpty(QString path) = 0;
    virtual QString ReadData(QString path) = 0;

};
class SQLDataReader : DataReader{
private:
    bool IsOpen(QString path);
    bool IsEmpty(QString path);
    QString ReadData(QString path);
public:
    SQLDataReader(){};
    QList<QPair<QString, float_t>> GetData(QString path);
};
class JSONDataReader : DataReader{
private:
    bool IsOpen(QString path);
    bool IsEmpty(QString path);
    QString ReadData(QString path);
public:
    JSONDataReader(){};
    QList<QPair<QString, float_t>> GetData(QString path);
};


#endif // DATAREADER_H
