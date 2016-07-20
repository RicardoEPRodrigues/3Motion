/*
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */
#include "agentviewwindow.h"
#include "ui_agentviewwindow.h"

using namespace std;
using namespace Divisaction;

AgentViewWindow::AgentViewWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AgentViewWindow)
{
    ui->setupUi(this);

    QShortcut *shortcut = new QShortcut(QKeySequence("SPACE"), this);
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(on_playPauseButton_clicked()));

    worldManager = Examples::example2();
    this->pause();
    QLabel* descriptionLabel = new QLabel();
    descriptionLabel->setText(QString(worldManager->getDescription().c_str()));
    descriptionLabel->setAlignment(Qt::AlignCenter);
    ui->gridLayout->addWidget(descriptionLabel, 0, 0, 1, 2);

    for (auto agent : worldManager->getAgents()) {
        AgentStatus* status = new AgentStatus(this);
        status->set(agent);
        agentsStatus.push_back(status);
        ui->gridLayout->addWidget(status);
    }

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateWorld()));
    Time::update();
    timer->start(20);
}

AgentViewWindow::~AgentViewWindow()
{
    delete ui;
}

void AgentViewWindow::updateWorld() {
    Time::update();
    if (worldManager && !worldManager->isPaused()) {
        worldManager->update();

        this->updateProgress();
    }
}

void AgentViewWindow::updateProgress() {
    if (worldManager) {
        for(AgentStatus* status : agentsStatus) {
            status->update(worldManager->getCurrentEvents());
        }
    }
}

void AgentViewWindow::play()
{
    if (worldManager) {
        ui->playPauseButton->setText("Pause (space)");
        Time::play();
        worldManager->play();
    }
}

void AgentViewWindow::pause()
{
    if (worldManager) {
        ui->playPauseButton->setText("Play (space)");
        Time::pause();
        worldManager->pause();
    }
}

void AgentViewWindow::on_playPauseButton_clicked()
{
    if (worldManager) {
        if (worldManager->isPaused()) {
            this->play();
        } else {
            this->pause();
        }
    }
}
