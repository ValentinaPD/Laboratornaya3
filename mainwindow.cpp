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
    printButton = std::make_unique<QPushButton>("Печать графика",this);
    label1 = std::make_unique<QLabel>("Выберите тип диаграммы",this);
    label2 = std::make_unique<QLabel>("Черно-белый");
    diagTypeComboBox = std::make_unique<QComboBox>();
    diagColorCheckBox = std::make_unique<QCheckBox>();

    QtCharts::QChart *chart = new QtCharts::QChart();

    QtCharts::QLineSeries *series = new QtCharts::QLineSeries();
    chart->addSeries(series);
    chart->setTitle("QT Charts example");

    chartView = std::make_unique<QChartView>(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    tableView = std::make_unique<QTableView>();

    std::unique_ptr<QVBoxLayout> mainLayout = std::make_unique<QVBoxLayout>(this);
    std::unique_ptr<QHBoxLayout> topLayout = std::make_unique<QHBoxLayout>();



    topLayout ->addWidget(label1.get());
    topLayout ->addWidget(diagTypeComboBox.get());
    topLayout ->addWidget(diagColorCheckBox.get());
    topLayout ->addWidget(label2.get());
    topLayout ->addWidget(printButton.get());
    topLayout ->addStretch(1);



    splitter = std::make_unique<QSplitter>(Qt::Horizontal, this);
    splitter->setChildrenCollapsible(false);
    splitter->addWidget(tableView.get());
    splitter->addWidget(chartView.get());
    splitter->setHandleWidth(1);
    mainLayout->addLayout(topLayout.release());
    mainLayout->addWidget(splitter.release());
    std::unique_ptr<QWidget> mainWidget = std::make_unique<QWidget>();
    mainWidget ->setLayout(mainLayout.release());

    setCentralWidget(mainWidget.release());
}

MainWindow::~MainWindow()
{
    delete ui;
}
