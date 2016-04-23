/*
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "divisactionwindow.h"
#include "ui_divisactionwindow.h"

using namespace Divisaction;

DivisactionWindow::DivisactionWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DivisactionWindow)
{
    ui->setupUi(this);
    ui->ActionStackLayout->setAlignment(Qt::AlignTop);

    scrollbar = ui->StagesScroll->verticalScrollBar();
    QObject::connect(scrollbar, SIGNAL(rangeChanged(int,int)), this, SLOT(moveScrollBarToBottom(int, int)));

    worldManager = Examples::example1();
    this->on_pauseButton_clicked();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateWorld()));
    Time::update();
    timer->start(10);
}

DivisactionWindow::~DivisactionWindow()
{
    delete ui;
}


void DivisactionWindow::updateWorld() {
    Time::update();
    if (worldManager) {
        worldManager->update();

        this->updateProgress();
    }
}

void DivisactionWindow::updateProgress()
{
    if (worldManager) {
        for(Agent * agent: worldManager->getAgents()) {
            Action * action = dynamic_cast<Action*>(agent->getCurrentExecutable());

            if (action) {
                Stage * stage = action->getCurrentStage();

                std::map<Stage *, ActionProgress *>::iterator it = actionsProgress.find(stage);
                if (it == actionsProgress.end()) {
                    ActionProgress * actionProgress = new ActionProgress();
                    actionProgress->set(agent, stage);
                    ui->ActionStackLayout->addWidget(actionProgress);
                    actionsProgress[stage] = actionProgress;
                }
            }
        }
        for (Event event : worldManager->getCurrentEvents()) {
            if (event.type == EventType::REPLY) {
                std::map<Stage *, ActionProgress *>::iterator it = actionsProgress.find(event.reply->stage);
                if (it != actionsProgress.end()) {
                    it->second->addReply(event);
                }
            }
        }

        for(std::map<Stage *, ActionProgress *>::iterator it = actionsProgress.begin(); it != actionsProgress.end(); ++it) {
            it->second->update();
        }
    }
}


// Utilities

void DivisactionWindow::moveScrollBarToBottom(int min, int max) {
    Q_UNUSED(min);
    this->scrollbar->setValue(max); // Moves the scroll bar to the bottom so that new stage are seen first.
}

void DivisactionWindow::on_playButton_clicked()
{
    if (worldManager) {
        worldManager->play();
        ui->playButton->setEnabled(false);
        ui->pauseButton->setEnabled(true);
    }
}

void DivisactionWindow::on_pauseButton_clicked()
{
    if (worldManager) {
        worldManager->pause();
        ui->playButton->setEnabled(true);
        ui->pauseButton->setEnabled(false);
    }
}
