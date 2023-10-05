#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileSystemModel>
#include <QListView>
#include <QStatusBar>
#include <memory>
#include <cassert>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QtCharts/QtCharts>
#include <QTableView>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QPushButton *printButton;
    QLabel *label1;
    QLabel *label2;
    QComboBox *diagTypeComboBox;
    QCheckBox *diagColorCheckBox;
    QChartView *chartView;
    QTableView *tableView;

private:
    Ui::MainWindow *ui;
protected:

};

#endif // MAINWINDOW_H
