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

    QGraphicsOpacityEffect* opacity = new QGraphicsOpacityEffect;
    QPropertyAnimation* animationOpacity = new QPropertyAnimation(opacity, "opacity");
    this->setGraphicsEffect(opacity);

    animationOpacity->setDuration(500);
    animationOpacity->setStartValue(0.0);
    animationOpacity->setEndValue(1.0);
    animationOpacity->setEasingCurve( QEasingCurve::InCubic );
    animationOpacity->start();
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
    this->stage = stage;
    ui->AgentName->setText(QString(agent->getName().c_str()));
    ui->AgentStage->setText(QString(stage->getName().c_str()));
    ui->progressBar->setValue(floor(stage->getProgress() * 100));
}

void ActionProgress::update()
{
    if (this->stage) {
        ui->progressBar->setValue(stage->getProgress() * 100);
    }
}
