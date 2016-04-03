/*
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "divisactionwindow.h"
#include "ui_divisactionwindow.h"

#include "actionprogress.h"
#include "Stage.h"
#include <QTimer>

using namespace Divisaction;

std::vector<ActionProgress*> actionProgresses;

void DivisactionWindow::updateStages() {
    for (ActionProgress * progress : actionProgresses) {
        if (progress) {
            progress->update();
        }
    }
}

DivisactionWindow::DivisactionWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DivisactionWindow)
{
    ui->setupUi(this);
    ui->ActionStackLayout->setAlignment(Qt::AlignTop);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateStages()));
    timer->start(100);

    int j = 1;
    std::vector<Stage*> stages (10);
    for(Stage * stage : stages) {
        stage = new Stage(std::string("Super Action ") + std::to_string(j), j * 1000);

        ActionProgress * actionProgress = new ActionProgress();
        actionProgress->set(stage);
        ui->ActionStackLayout->addWidget(actionProgress);
        actionProgresses.push_back(actionProgress);
        ++j;
    }
}

DivisactionWindow::~DivisactionWindow()
{
    delete ui;
}
