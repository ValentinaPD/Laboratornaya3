#include "mainwindow.h"
#include <QApplication>
#include "datareader.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    DataReader dr;
    //dr.SQLReader("C:\\TRPOLabs\\Laboratornaya3\\TEMPERATURE_NOVOSIB.sqlite");
    QFile file("C:\\DataJSON.json");

        //QMap<QString,double> data;
        QList<QPair<QString, float_t>> data;
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QJsonDocument document = QJsonDocument::fromJson(file.readAll());
            file.close();

            QJsonObject object = document.object();
            QListIterator<QString> iterator(object.keys());
            while (iterator.hasNext()) {
                QString key=iterator.next();
                double value =object.value(key).toDouble();
               // data.insert(key, value);
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
    w.show();

    return a.exec();
}
