#include "divisactionwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DivisactionWindow w;
    w.show();

    return a.exec();
}
