#ifndef DATAREADER_H
#define DATAREADER_H
#include "QString"
#include <QtSql>
#include <QException>

class IDataReader{
public:
    virtual QList<QPair<QString, float_t>> GetData(const QString& path) = 0;
    virtual ~IDataReader() = default;
public:
    virtual bool IsExist(const QString& path) = 0;


};
class SQLDataReader : public IDataReader{
public:
    bool IsExist(const QString& path);
public:
    SQLDataReader();
    QList<QPair<QString, float_t>> GetData(const QString& path);
    virtual ~SQLDataReader() = default;
};
class JSONDataReader : public IDataReader{
public:
    bool IsExist(const QString& path);
public:
    JSONDataReader();
    QList<QPair<QString, float_t>> GetData(const QString& path);
    virtual ~JSONDataReader() = default;
};
/*
class DataReaderImp
{
private:
   IDataReader datareader;
public:
   DataReaderImp(const IDataReader& dataReader);
   QList<Qpair<Qstring, float_t>> GetData(QSting path);
};
*/
#endif // DATAREADER_H
