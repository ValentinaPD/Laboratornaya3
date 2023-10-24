#ifndef CHARTCREATOR_H
#define CHARTCREATOR_H
#include "QString"
#include <QPair>
#include <QChartView>
#include <QtCharts/QtCharts>
#include <memory>
#include <QLineSeries>
#include <QBarSeries>
#include <QLineSeries>
#include <QPieSeries>
#include <QScatterSeries>
class ChartCreator
{
public:
    void DrawChart(QList<QPair<QString, float_t>> data, std::unique_ptr<QChartView>& chartView);
    virtual ~ChartCreator() {}

protected:
    virtual void CreateSeries(QList<QPair<QString, float_t>> data, std::unique_ptr<QChartView>& chartView) = 0;
    virtual void CreateTitle(std::unique_ptr<QChartView>& chartView) = 0;
    virtual void SetAnimation(std::unique_ptr<QChartView>& chartView) = 0;

};

class BarChartCreator:public ChartCreator
{
protected:
    void CreateSeries(QList<QPair<QString, float_t>> data, std::unique_ptr<QChartView>& chartView) override;
    void CreateTitle(std::unique_ptr<QChartView>& chartView) override;
    void SetAnimation(std::unique_ptr<QChartView>& chartView) override;
};

class LineChartCreator:public ChartCreator
{
protected:
    void CreateSeries(QList<QPair<QString, float_t>> data, std::unique_ptr<QChartView>& chartView) override;
    void CreateTitle(std::unique_ptr<QChartView>& chartView) override;
    void SetAnimation(std::unique_ptr<QChartView>& chartView) override;

};
class ScatterChartCreator:public ChartCreator
{
protected:
    void CreateSeries(QList<QPair<QString, float_t>> data, std::unique_ptr<QChartView>& chartView) override;
    void CreateTitle(std::unique_ptr<QChartView>& chartView) override;
    void SetAnimation(std::unique_ptr<QChartView>& chartView) override;

};




#endif // CHARTCREATOR_H
