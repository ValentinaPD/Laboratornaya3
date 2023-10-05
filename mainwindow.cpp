#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Построитель диаграмм");
    //Устанавливаем размер главного окна
    this->setGeometry(100, 100, 1500, 500);

    this->setWindowTitle("Построитель диаграмм");
    printButton = new QPushButton("Печать графика",this);
    label1 = new QLabel("Выберите тип диаграммы",this);
    label2 = new QLabel("Черно-белый");
    diagTypeComboBox = new QComboBox();
    diagColorCheckBox = new QCheckBox();

    QtCharts::QChart *chart = new QtCharts::QChart();

    QtCharts::QLineSeries *series = new QtCharts::QLineSeries();
    chart->addSeries(series);
    chart->setTitle("QT Charts example");

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    tableView = new QTableView();

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *topLayout = new QHBoxLayout();
    QHBoxLayout *centralLayout = new QHBoxLayout();


    topLayout ->addWidget(printButton);
    topLayout ->addWidget(label1);
    topLayout ->addWidget(diagTypeComboBox);
    topLayout ->addWidget(diagColorCheckBox);
    topLayout ->addWidget(label2);
    topLayout ->addWidget(printButton);
    topLayout ->addStretch();
    centralLayout ->addWidget(tableView);
    centralLayout ->addWidget(chartView);
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(centralLayout);
    QWidget *mainWidget = new QWidget();
    mainWidget ->setLayout(mainLayout);          //ранее наполненный layout

    setCentralWidget(mainWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
