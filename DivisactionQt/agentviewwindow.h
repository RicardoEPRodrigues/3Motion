/*
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */
#ifndef AGENTVIEWWINDOW_H
#define AGENTVIEWWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QShortcut>
#include <QTimer>

#include "Divisaction.h"
#include "Extra/Examples.h"
#include "agentstatus.h"

namespace Ui {
class AgentViewWindow;
}

class AgentViewWindow : public QMainWindow {
    Q_OBJECT

  public:
    explicit AgentViewWindow(QWidget *parent = 0);
    ~AgentViewWindow();

  private:
    Ui::AgentViewWindow *ui;

    std::shared_ptr<class Divisaction::WorldManager> worldManager;
    std::vector<AgentStatus *> agentsStatus; // TODO change to have a matrix
                                             // where the key is the agent and
                                             // the value a list with the
                                             // actions he has done.

    QTimer* updateTimer;
    void updateProgress();

    void init();
    void restart();

    void play();
    void pause();
  private slots:
    void updateWorld();
    void on_playPauseButton_clicked();
    void on_actionLog_View_triggered();
    void on_actionExit_triggered();
    void on_actionRestart_triggered();
};

#endif // AGENTVIEWWINDOW_H
