/*
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "actionprogress.h"
#include "ui_actionprogress.h"
#include <math.h>

ActionProgress::ActionProgress(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ActionProgress)
{
    ui->setupUi(this);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
}

ActionProgress::~ActionProgress()
{
    delete ui;
}

void ActionProgress::setLabel(QString name)
{
    this->ui->label->setText(name);
}

void ActionProgress::set(Stage* stage)
{
    this->stage = stage;
    ui->label->setText(QString(stage->getName().c_str()));
    ui->progressBar->setValue(floor(stage->getProgress() * 100));
}

void ActionProgress::update()
{
    if (this->stage) {
        ui->progressBar->setValue(stage->getProgress() * 100);
    }
}
