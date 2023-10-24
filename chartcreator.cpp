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
    int i = 0;
    for(auto item : data){
        std::unique_ptr<QBarSet> barSet(new QBarSet(item.first));
        *barSet << item.second;
        series->append(barSet.release());
        i++;
        if(i==5)
            break;
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
        if(i==5)
            break;
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


