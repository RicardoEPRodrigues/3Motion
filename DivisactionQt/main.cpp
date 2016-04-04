/*
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "divisactionwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DivisactionWindow w;
    w.show();

    const int retval = a.exec();

    //Shutdown functions

    return retval;
}
