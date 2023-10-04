#include "paint.h"
#include "./ui_paint.h"

Paint::Paint(QWidget *parent) : QMainWindow(parent)
{

    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(actionSave()));
    connect(ui->actionClear, SIGNAL(triggered()), this, SLOT(actionClear()));

    ui = new Ui::MainWindow();
    ui->setupUi(this);

    p = new Painter();
    p->setImage(QImage(this->size(), QImage::Format_RGB32));
    p->setDrawing(false);
    p->setBrushColor(Qt::black);
    p->setBrushSize(1);

}

Paint::~Paint()
{
    delete ui;
    delete p;
}

void Paint::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        p->setDrawing(true);
        p->setLastPoint(event->pos());
    }
}

void Paint::mouseMoveEvent(QMouseEvent *event)
{
    if((event->buttons() & Qt::LeftButton) && p->getDrawing())
    {
        QImage img = p->getImage();
        QPainter painter(&img);
        painter.setPen(QPen(p->getBrushColor(), p->getBrushSize(), Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter.drawLine(p->getLastPoint(), event->pos());
        p->setLastPoint(event->pos());
        this->update();
    }
}

void Paint::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        p->setDrawing(false);
    }
}

void Paint::paintEvent(QPaintEvent *event)
{
    QImage img = p->getImage();
    QPainter canvasPainter(this);
    canvasPainter.drawImage(this->rect(), img, img.rect());
}

void Paint::actionSave()
{
    QString filePath = QFileDialog::getSaveFileName(this,
                                                    "Save Image",
                                                    "",
                                                    "PNG(*.png);;"
                                                    "JPEG(*.jpg *.jpeg);;"
                                                    "All files(*.*)");
    if(filePath == "") { return;}
    p->getImage().save(filePath);
}

void Paint::actionClear()
{
    QImage img = p->getImage();
    img.fill(Qt::white);
    p->setImage(img);
}
