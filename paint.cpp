#include "paint.h"
#include "./ui_paint.h"

#include<QPainter>
#include<QFileDialog>

Paint::Paint(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(actionSave()));
    connect(ui->actionClear, SIGNAL(triggered()), this, SLOT(actionClear()));
    connect(ui->action3px, SIGNAL(triggered()), this, SLOT(action3px()));
    connect(ui->action5px, SIGNAL(triggered()), this, SLOT(action5px()));
    connect(ui->action7px, SIGNAL(triggered()), this, SLOT(action7px()));
    connect(ui->action9px, SIGNAL(triggered()), this, SLOT(action9px()));
    connect(ui->actionBlack, SIGNAL(triggered()), this, SLOT(actionBlack()));
    connect(ui->actionGreen, SIGNAL(triggered()), this, SLOT(actionGreen()));
    connect(ui->actionRed, SIGNAL(triggered()), this, SLOT(actionRed()));
    connect(ui->actionYellow, SIGNAL(triggered()), this, SLOT(actionYellow()));
    connect(ui->actionErase, SIGNAL(triggered()), this, SLOT(actionErase()));

    image = QImage(this->size(), QImage::Format_RGB32);
    image.fill(Qt::white);
    drawing=false;
    brushColor = Qt::black;
    brushSize = 2;
}

Paint::~Paint()
{
    delete ui;
}

void Paint::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        drawing=true;
        lastPoint=event->pos();
    }
}

void Paint::mouseMoveEvent(QMouseEvent *event)
{
    if((event->buttons() & Qt::LeftButton) && drawing) {
        QPainter painter(&image);
        painter.setPen(QPen(brushColor, brushSize, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter.drawLine(lastPoint, event->pos());
        lastPoint = event->pos();
        this->update();
    }
}

void Paint::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        drawing=false;
    }
}

void Paint::paintEvent(QPaintEvent *event)
{
    QPainter canvasPainter(this);
    canvasPainter.drawImage(this->rect(), image, image.rect());
}

void Paint::actionSave()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save Image", "", "PNG(*.png);;JPEG(*.jpg *.jpeg);;All files(*.*)");
    if(filePath == "") { return;}
    image.save(filePath);
}

void Paint::actionClear()
{
    image.fill(Qt::white);
    this->update();
}

void Paint::action3px()     {brushSize=3;}
void Paint::action5px()     {brushSize=5;}
void Paint::action7px()     {brushSize=7;}
void Paint::action9px()     {brushSize=9;}
void Paint::actionBlack()   {brushColor=Qt::black;}
void Paint::actionErase()   {brushColor=Qt::white;}
void Paint::actionRed()     {brushColor=Qt::red;}
void Paint::actionGreen()   {brushColor=Qt::green;}
void Paint::actionYellow()  {brushColor=Qt::yellow;}
