/*
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "actionprogress.h"
#include "ui_actionprogress.h"

ActionProgress::ActionProgress(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ActionProgress)
{
    ui->setupUi(this);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);

//    QGraphicsOpacityEffect* opacity = new QGraphicsOpacityEffect;
//    QPropertyAnimation* animationOpacity = new QPropertyAnimation(opacity, "opacity");
//    this->setGraphicsEffect(opacity);

//    animationOpacity->setDuration(500);
//    animationOpacity->setStartValue(0.0);
//    animationOpacity->setEndValue(1.0);
//    animationOpacity->setEasingCurve( QEasingCurve::InCubic );
//    animationOpacity->start();

    ui->repliesHolder->setVisible(false);
}

ActionProgress::~ActionProgress()
{
    delete ui;
}

void ActionProgress::setLabel(QString name)
{
    this->ui->label->setText(name);
}

void ActionProgress::set(Agent* agent, Stage* stage)
{
    this->stage = dynamic_cast<TimeProgressiveStage*>(stage);
    if (this->stage) {
        ui->AgentName->setText(QString(agent->getName().c_str()));
        ui->AgentStage->setText(QString(this->stage->getName().c_str()));
        ui->progressBar->setValue(floor(this->stage->getProgress() * 100));
    }
    this->agent = agent;
}

void ActionProgress::update()
{
    if (this->stage) {
        ui->progressBar->setValue(this->stage->getProgress() * 100);
        if (this->replies.size() > 0) {
            if (!this->ui->repliesHolder->isVisible()) {
                this->ui->repliesHolder->setVisible(true);
            }
            for (ActionProgress* reply : replies) {
                reply->update();
            }
        }
    }
}

void ActionProgress::addReply(Event reply) {
    ActionProgress * actionProgress = new ActionProgress(this);
    actionProgress->set(reply.sender, reply.stage);
    this->replies.push_back(actionProgress);
    this->ui->replies->addWidget(actionProgress);
}

Agent* ActionProgress::getAgent() const
{
    return agent;
}
