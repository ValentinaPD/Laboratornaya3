#ifndef OBSERVER_H
#define OBSERVER_H
#include <memory>
#include <QList>
#include <QtSql>
#include <QDebug>
class IObserver
{
public:
    virtual ~IObserver() {}
    virtual void Update(QList<QPair<QString, float_t>>& data) = 0;
};

class Subject {
    std::vector<std::shared_ptr<IObserver>> observers;
public:
    void count1(){
        qDebug()<<observers.size();
    }
    void attach(std::shared_ptr<IObserver> observer) {
        observers.push_back(observer);
        qDebug()<<observers.size();
    }
    void detach(std::shared_ptr<IObserver> observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
        qDebug()<<"erace";
    }
    void notify(QList<QPair<QString, float_t>>& data) {

        for (std::shared_ptr<IObserver> observer : observers) {

            observer->Update(data);
        }
    }
};
#endif // OBSERVER_H
