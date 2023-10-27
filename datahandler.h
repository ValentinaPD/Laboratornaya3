#ifndef DATAHANDLER_H
#define DATAHANDLER_H
#include <QString>
#include <QPair>
#include "QString"
#include <QList>
#include <QtSql>
#include <QFileInfo>
#include <memory>
#include <datareader.h>
#include <observer.h>
class DataHandler:public Subject
{
public:
    DataHandler();
    QList<QPair<QString, float_t>> GetDataForCount(QString &path,int n);
   // QList<QPair<QString, float_t>> GetGroupedData(QString &path);
private:
    QList<QPair<QString, float_t>> data;
    void GetDataFromReader(QString &path);

};

#endif // DATAHANDLER_H
