#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "datareader.h"
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
#include "chartcreator.h"
#include <ioccontainer.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void OpenFolder();
    void SelectFile(const QItemSelection &selected, const QItemSelection &deselected);
    void ChangeChartType(const QString typeName);
    void PrintChart();
private:
    Ui::MainWindow *ui;
    void OpenFile(QString fileName);
    IOCContainer injector;
protected:
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
    std::unique_ptr<IDataReader> dataReader;
    std::shared_ptr<ChartCreator> chartCreator;
    QList<QPair<QString, float_t>> _data;


};

#endif // MAINWINDOW_H
