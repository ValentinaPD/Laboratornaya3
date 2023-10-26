#ifndef EXPORTER_H
#define EXPORTER_H
#include <QPainter>
#include <QFileDialog>
#include <QPdfWriter>
#include <QDebug>
class Exporter
{
public:
    virtual ~Exporter(){}
    virtual void Export(QPixmap pix) = 0;

};

class PdfExporter: public Exporter
{
    void Export(QPixmap pix) override{
        QString filePath = QFileDialog::getSaveFileName(nullptr, "Экспорт диаграммы", "", "PDF (*.pdf)");
        if (filePath.isEmpty())
            return;
        QPdfWriter pdfWriter(filePath);
        QPainter painter(&pdfWriter);
        int h = pix.height()*(painter.window().width()/pix.width());
        int w = painter.window().width();
        int x = (painter.window().width() / 2) - (w/2);
        int y = (painter.window().height() / 2) - (h/2);

        painter.drawPixmap(x,y,w,h,pix);
        painter.end();
    }
};

#endif // EXPORTER_H
