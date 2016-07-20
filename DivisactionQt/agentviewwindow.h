/*
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */
#ifndef AGENTVIEWWINDOW_H
#define AGENTVIEWWINDOW_H

#include <QMainWindow>
#include <QShortcut>
#include <QLabel>
#include <QTimer>

#include "agentstatus.h"
#include "Divisaction.h"
#include "Extra/Examples.h"

namespace Ui {
    class AgentViewWindow;
}

class AgentViewWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AgentViewWindow(QWidget *parent = 0);
    ~AgentViewWindow();

private:
    Ui::AgentViewWindow *ui;

    std::shared_ptr<class Divisaction::WorldManager> worldManager;
    std::vector<AgentStatus *> agentsStatus; // TODO change to have a matrix where the key is the agent and the value a list with the actions he has done.

    void updateProgress();

    void play();
    void pause();
private slots:
    void updateWorld();
    void on_playPauseButton_clicked();
};

#endif // AGENTVIEWWINDOW_H
