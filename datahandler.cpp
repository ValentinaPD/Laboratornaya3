#include "datahandler.h"

DataHandler::DataHandler()
{

}
QList<QPair<QString, float_t>> DataHandler::GetDataForCount(QString &path, int n){
    GetDataFromReader(path);
    QList<QPair<QString, float_t>> _data;
    for(int i = 0; i < n; i++){
        _data.append(data[i]);
    }
    notify(_data);
    return _data;
}
/*
QList<QPair<QString, float_t>> DataHandler::GetGroupedData(QString &path){
    GetDataFromReader(path);
    QList<QPair<QString, float_t>> groupedData;
    // Вычисляем среднее значение для каждой даты
    auto count = 0;
    float_t sum = 0;

    std::sort(data.begin(), data.end(), [](const QPair<QString, float_t>& pair1, const QPair<QString, float_t>& pair2) {
        QDate date1 = QDate::fromString(pair1.first, "dd.MM.yyyy");
        QDate date2 = QDate::fromString(pair2.first, "dd.MM.yyyy");
        return date1 < date2;
    });

    for(auto it = data.begin()+1; it < data.end(); ++it) {
        if(QDate::fromString(it->first.split(' ').first(), "dd.MM.yyyy") == QDate::fromString((it-1)->first.split(' ').first(), "dd.MM.yyyy")) {
            count++;
            sum += (it-1)->second;
        }
        else{
            groupedData.append(qMakePair((it-1)->first.split(' ').first(), sum));
            sum = (it-1)->second;
            count = 0;
        }
    }
    return groupedData;
}*/
void DataHandler::GetDataFromReader(QString &path){
    QFileInfo fileInfo(path);
    QString fileExtension = fileInfo.suffix();
    std::unique_ptr<IDataReader> dataReader;
    if (fileExtension == "sqlite")
        dataReader = std::make_unique<SQLDataReader>();
    else if (fileExtension == "json")
        dataReader = std::make_unique<JSONDataReader>();
    data = dataReader->GetData(path);

}

