#ifndef PAINT_H
#define PAINT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE

class Paint : public QMainWindow
{
    Q_OBJECT
public:
    Paint(QWidget *parent = nullptr);
    ~Paint();

private:
    Ui::MainWindow *ui;

};

#endif // PAINT_H
