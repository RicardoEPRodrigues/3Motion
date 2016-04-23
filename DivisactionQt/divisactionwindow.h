/*
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef DIVISACTIONWINDOW_H
#define DIVISACTIONWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QScrollArea>
#include <QScrollBar>

#include <vector>

#include "actionprogress.h"

#include "Time.h"
#include "WorldManager.h"
#include "Agent.h"
#include "Extra/Examples.h"

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

    WorldManager * worldManager;
    std::map<Stage *, ActionProgress *> actionsProgress;

    void updateProgress();

private slots:
    void updateWorld();
    void moveScrollBarToBottom(int min, int max);
    void on_playButton_clicked();
    void on_pauseButton_clicked();
};

#endif // DIVISACTIONWINDOW_H
