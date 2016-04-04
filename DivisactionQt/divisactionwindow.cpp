/*
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "divisactionwindow.h"
#include "ui_divisactionwindow.h"

using namespace Divisaction;

std::vector<ActionProgress*> actionProgresses;

DivisactionWindow::DivisactionWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DivisactionWindow)
{
    ui->setupUi(this);
    ui->ActionStackLayout->setAlignment(Qt::AlignTop);

    scrollbar = ui->StagesScroll->verticalScrollBar();
    QObject::connect(scrollbar, SIGNAL(rangeChanged(int,int)), this, SLOT(moveScrollBarToBottom(int, int)));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateWorld()));
    timer->start(100);

    int j = 1;
    std::vector<Stage*> stages (30);
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


void DivisactionWindow::updateWorld() {
    for (ActionProgress * progress : actionProgresses) {
        if (progress) {
            progress->update();
        }
    }
}

void DivisactionWindow::moveScrollBarToBottom(int min, int max) {
    Q_UNUSED(min);
    this->scrollbar->setValue(max); // Moves the scroll bar to the bottom so that new stage are seen first.
}
