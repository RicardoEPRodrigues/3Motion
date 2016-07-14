/*
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef DIVISACTIONWINDOW_H
#define DIVISACTIONWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QScrollArea>
#include <QScrollBar>
#include <QLabel>
#include <QShortcut>

#include <vector>
#include <memory>

#include "actionprogress.h"

#include "Divisaction.h"
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

    std::shared_ptr<class WorldManager> worldManager;
    std::vector<ActionProgress *> actionsProgress; // change to have a matrix where the key is the agent and the value a list with the actions he has done.

    void updateProgress();

    void play();
    void pause();
private slots:
    void updateWorld();
    void moveScrollBarToBottom(int min, int max);
    void on_playPauseButton_clicked();
};

#endif // DIVISACTIONWINDOW_H
