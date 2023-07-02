#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFileSystemModel>
#include <QListView>
#include <QStatusBar>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
protected:
    QTextCodec *codec;
    QPushButton * btn;
    QFileSystemModel *tableSysModel;
    QListView *listView;

};

#endif // MAINWINDOW_H
