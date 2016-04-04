/*
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef DIVISACTIONWINDOW_H
#define DIVISACTIONWINDOW_H

#include <QMainWindow>
#include "actionprogress.h"
#include "Stage.h"
#include <QTimer>
#include <QScrollArea>
#include <QScrollBar>

namespace Ui {
class DivisactionWindow;
}

class DivisactionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DivisactionWindow(QWidget *parent = 0);
    ~DivisactionWindow();

private:
    Ui::DivisactionWindow *ui;
    QScrollBar* scrollbar;

private slots:
    void updateWorld();
    void moveScrollBarToBottom(int min, int max);
};

#endif // DIVISACTIONWINDOW_H
