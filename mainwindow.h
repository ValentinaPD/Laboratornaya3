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
#include <QSplitter>
#include <memory>
#include <QFileDialog>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    std::unique_ptr <QPushButton> printButton;
    std::unique_ptr <QPushButton> openFolderButton;
    std::unique_ptr <QLabel> label1;
    std::unique_ptr <QLabel> label2;
    std::unique_ptr <QComboBox> diagTypeComboBox;
    std::unique_ptr <QCheckBox> diagColorCheckBox;
    std::unique_ptr <QChartView> chartView;
    std::unique_ptr <QTableView> tableView;
    std::unique_ptr <QSplitter> splitter;
    std::unique_ptr <QFileSystemModel> leftPartModel;

public slots:
    void OpenFolder();
private:
    Ui::MainWindow *ui;
protected:

};

#endif // MAINWINDOW_H
