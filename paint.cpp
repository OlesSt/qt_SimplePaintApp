#include "paint.h"
#include "./ui_paint.h"

Paint::Paint(QWidget *parent) : QMainWindow(parent)
{
    ui = new Ui::MainWindow();
    ui->setupUi(this);

}

Paint::~Paint()
{

}
