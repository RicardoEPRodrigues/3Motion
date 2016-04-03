/*
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef DIVISACTIONWINDOW_H
#define DIVISACTIONWINDOW_H

#include <QMainWindow>

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

private slots:
    void updateStages();
};

#endif // DIVISACTIONWINDOW_H
