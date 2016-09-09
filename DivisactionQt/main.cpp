/*
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "logviewwindow.h"
#include "agentviewwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file(":/style.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    a.setStyleSheet(styleSheet);

    LogViewWindow w;
//    AgentViewWindow w;
    w.show();

    const int retval = a.exec();

    //Shutdown functions

    return retval;
}
