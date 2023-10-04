#ifndef PAINT_H
#define PAINT_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QFileDialog>
#include "painter.h"

QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE

class Paint : public QMainWindow
{
    Q_OBJECT
public:
    Paint(QWidget *parent = nullptr);
    ~Paint();

    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent *event);

    void actionSave();
    void actionClear();

    void action3px();
    void action5px();
    void action7px();
    void action9px();

    void actionBlack();
    void actionRed();
    void actionGreen();
    void actionYellow();
    void actionErase();



private:
    Ui::MainWindow *ui;
    Painter *p;

};

#endif // PAINT_H
