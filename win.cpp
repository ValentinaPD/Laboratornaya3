#include "win.h"

Win::Win()
{
    codec = QTextCodec::codecForName("utf-8");
    this->setWindowTitle(codec->toUnicode("Построитель диаграмм"));
    btn = new QPushButton(codec->toUnicode("Завершить"),this );
}
