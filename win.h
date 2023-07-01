#ifndef WIN_H
#define WIN_H
#include <QtGui>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class Win: public QWidget
{
protected:
    QTextCodec *codec;
    QPushButton * btn;
public:
    Win();
};

#endif // WIN_H
