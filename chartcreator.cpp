#include "chartcreator.h"


void ChartCreator::DrawChart(QList<QPair<QString, float_t>> data, std::unique_ptr<QChartView>& chartView){
    chartView->chart()->removeAllSeries();
    CreateSeries(data, chartView);
    CreateTitle(chartView);
    SetAnimation(chartView);
    chartView->update();
}
void BarChartCreator::CreateSeries(QList<QPair<QString, float_t>> data, std::unique_ptr<QChartView>& chartView){
    std::unique_ptr<QBarSeries> series = std::make_unique<QBarSeries>();
    for(auto item : data){
        std::unique_ptr<QBarSet> barSet(new QBarSet(item.first));
        *barSet << item.second;
        series->append(barSet.release());
    }
    chartView->chart()->addSeries(series.release());
}
void BarChartCreator::CreateTitle(std::unique_ptr<QChartView>& chartView){
    chartView->chart()->setTitle("Гистограмма");
}
void BarChartCreator::SetAnimation(std::unique_ptr<QChartView>& chartView){
    chartView->chart()->setAnimationOptions(QChart::SeriesAnimations);
}

void LineChartCreator::CreateSeries(QList<QPair<QString, float_t>> data, std::unique_ptr<QChartView>& chartView){
    std::unique_ptr<QLineSeries> series = std::make_unique<QLineSeries>();
    int i = 0;

    for(auto item : data){
        series->append(i,item.second);
        i++;
    }
    chartView->chart()->addSeries(series.release());
    chartView->chart()->createDefaultAxes();
}
void LineChartCreator::CreateTitle(std::unique_ptr<QChartView>& chartView){
    chartView->chart()->setTitle("Линейная");
}
void LineChartCreator::SetAnimation(std::unique_ptr<QChartView>& chartView){
    chartView->chart()->setAnimationOptions(QChart::SeriesAnimations);
}
void ScatterChartCreator::CreateSeries(QList<QPair<QString, float_t>> data, std::unique_ptr<QChartView>& chartView){
    std::unique_ptr<QScatterSeries> series = std::make_unique<QScatterSeries>();
    int i = 0;

    for(auto item : data){
        series->append(i,item.second);
        i++;
    }
    chartView->chart()->addSeries(series.release());
    chartView->chart()->createDefaultAxes();
}
void ScatterChartCreator::CreateTitle(std::unique_ptr<QChartView>& chartView){
    chartView->chart()->setTitle("Scatter");
}
void ScatterChartCreator::SetAnimation(std::unique_ptr<QChartView>& chartView){
    chartView->chart()->setAnimationOptions(QChart::SeriesAnimations);
}
void PieChartCreator::CreateSeries(QList<QPair<QString, float_t>> data, std::unique_ptr<QChartView>& chartView){
    std::unique_ptr<QPieSeries> series = std::make_unique<QPieSeries>();
    for(auto item : data){
        series->append(item.first,item.second);
    }
    chartView->chart()->addSeries(series.release());
}
void PieChartCreator::CreateTitle(std::unique_ptr<QChartView>& chartView){
    chartView->chart()->setTitle("Pie");
}
void PieChartCreator::SetAnimation(std::unique_ptr<QChartView>& chartView){
    chartView->chart()->setAnimationOptions(QChart::SeriesAnimations);
}

