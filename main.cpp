#include <QApplication>
#include "paint.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Paint p;
    p.show();

    return a.exec();
}
