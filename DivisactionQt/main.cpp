/*
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "divisactionwindow.h"
#include <QApplication>

#include "Looper.h"

using namespace Divisaction;

void callback() {
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DivisactionWindow w;
    w.show();

//    Looper * looper = new Looper(callback, 250);
//    looper->start();

    const int retval = a.exec();

    //Shutdown functions
//    looper->stop();

    return retval;
}
