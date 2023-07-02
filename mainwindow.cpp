#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    codec = QTextCodec::codecForName("utf-8");
    this->setWindowTitle(codec->toUnicode("Построитель диаграмм"));
    //Устанавливаем размер главного окна
    this->setGeometry(100, 100, 1500, 500);
    this->setStatusBar(new QStatusBar(this));
    btn = new QPushButton(codec->toUnicode("Открыть папку"),this );
    listView = new QListView(this);
    listView->setMinimumWidth(100);
    listView->setMinimumHeight(100);

}

MainWindow::~MainWindow()
{
    delete ui;
}
