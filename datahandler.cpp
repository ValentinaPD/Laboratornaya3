#include "datahandler.h"

DataHandler::DataHandler()
{

}
QList<QPair<QString, float_t>> DataHandler::GetDataForCount(QString &path){
    GetData(path);
    return data;
}
QList<QPair<QString, float_t>> DataHandler::GetGroupedData(QString &path){
    GetData(path);
    return data;
}
void DataHandler::GetData(QString &path){
    QFileInfo fileInfo(path);
    QString fileExtension = fileInfo.suffix();
    std::unique_ptr<IDataReader> dataReader;
    if (fileExtension == "sqlite")
        dataReader = std::make_unique<SQLDataReader>();
    else if (fileExtension == "json")
        dataReader = std::make_unique<JSONDataReader>();
    data = dataReader->GetData(path);
}

