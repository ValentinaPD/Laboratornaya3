#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>

//int IOCContainer::s_nextTypeId = 115094801;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Построитель диаграмм");
    this->setGeometry(100, 100, 1500, 700);
    this->setMinimumSize(900, 500);
    this->setWindowTitle("Построитель диаграмм");
    this->setStatusBar(new QStatusBar(this));
    this->statusBar()->showMessage("Выбранный путь : ");

    printButton = std::make_unique<QPushButton>("Печать графика",this);
    openFolderButton = std::make_unique<QPushButton>("Выбрать папку",this);
    label1 = std::make_unique<QLabel>("Выберите тип диаграммы",this);
    label2 = std::make_unique<QLabel>("Черно-белый");
    diagTypeComboBox = std::make_unique<QComboBox>();
    diagTypeComboBox->addItem("Круговая диаграмма");
    diagTypeComboBox->addItem("Столбчатая диаграмма");
    diagColorCheckBox = std::make_unique<QCheckBox>();

    QtCharts::QChart *chart = new QtCharts::QChart();

    QtCharts::QLineSeries *series = new QtCharts::QLineSeries();
    chart->addSeries(series);
    chart->setTitle("QT Charts example");

    chartView = std::make_unique<QChartView>();
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(500,500);
    chartView->setGeometry(100,100,700,700);

    tableView = std::make_unique<QTableView>();
    tableView->setMinimumSize(300,500);

    QString homePath = QDir::homePath();
    // Определим  файловой системы:
    leftPartModel = std::make_unique<QFileSystemModel>(this);
    leftPartModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    leftPartModel->setRootPath(homePath);
    tableView->setModel(leftPartModel.get());

    QItemSelectionModel *selectionModel = tableView->selectionModel();

    std::unique_ptr<QVBoxLayout> mainLayout = std::make_unique<QVBoxLayout>(this);
    std::unique_ptr<QHBoxLayout> topLayout = std::make_unique<QHBoxLayout>();
    std::unique_ptr<QHBoxLayout> tLeftLayout = std::make_unique<QHBoxLayout>();


    tLeftLayout->addWidget(openFolderButton.get());
    topLayout ->addLayout(tLeftLayout.release());

    topLayout ->addWidget(label1.get());
    topLayout ->addWidget(diagTypeComboBox.get());
    topLayout ->addWidget(diagColorCheckBox.get());
    topLayout ->addWidget(label2.get());
    topLayout ->addWidget(printButton.get());
    topLayout ->setAlignment(Qt::AlignRight);
    topLayout ->setMargin(3);

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

    QItemSelection toggleSelection;
    QModelIndex topLeft;
    topLeft = leftPartModel->index(homePath);
    toggleSelection.select(topLeft, topLeft);
    selectionModel->select(toggleSelection, QItemSelectionModel::Toggle);

    connect(selectionModel, &QItemSelectionModel::selectionChanged, this, &MainWindow::SelectFile);
    connect(openFolderButton.get(), &QPushButton::clicked, this, &MainWindow::OpenFolder);


}

void MainWindow::OpenFolder(){
    QFileDialog fileDialog(nullptr, "Выберите папку");
    QStringList filter;
    filter << "*.sqlite" << "*.json" << "*.csv";
    fileDialog.setOptions(QFileDialog::DontUseNativeDialog | QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    fileDialog.setFileMode(QFileDialog::Directory);
    fileDialog.setNameFilter("*.sqlite *.json *.svg");
    QString folderPath;
    if(fileDialog.exec())
        folderPath =fileDialog.selectedFiles().first();
    leftPartModel->setRootPath(folderPath);
    leftPartModel->setFilter(QDir::Files);
    leftPartModel->setNameFilters(filter);
    tableView->setRootIndex(leftPartModel->index(folderPath));
}

void MainWindow::SelectFile(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected);
    QModelIndex index = tableView->selectionModel()->currentIndex();
    QModelIndexList indexs =  selected.indexes();
    QString filePath = "";

    if (indexs.count() >= 1) {
        QModelIndex ix =  indexs.constFirst();
        filePath = leftPartModel->filePath(ix);
        this->statusBar()->showMessage("Выбранный путь : " + leftPartModel->filePath(indexs.constFirst()));
    }
    OpenFile(filePath);
}
void MainWindow::OpenFile(QString fileName){
    QFileInfo fileInfo(fileName);
    QString fileExtension = fileInfo.suffix();
    if (fileExtension == "sqlite")
        dataReader = std::make_unique<SQLDataReader>();
    else if (fileExtension == "json")
        dataReader = std::make_unique<JSONDataReader>();
    _data = dataReader->GetData(fileName);
    qDebug() << _data.first().first;
    ChangeChartType("Столбчатая диаграмма");
}

void MainWindow::ChangeChartType(const QString typeName){
    if(typeName=="Столбчатая диаграмма"){
        injector.RegisterFactory<ChartCreator,PieChartCreator>();
        chartCreator = injector.GetObject<ChartCreator>();
    }
    if (chartCreator)
        chartCreator->DrawChart(_data, chartView);

}
MainWindow::~MainWindow()
{
    delete ui;
}
