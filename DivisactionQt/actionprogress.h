/*
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef ACTIONPROGRESS_H
#define ACTIONPROGRESS_H

#include <QWidget>
#include "Agent.h"
#include "Stage.h"
#include <math.h>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>

using namespace Divisaction;

namespace Ui {
    class ActionProgress;
}

class ActionProgress : public QWidget
{
    Q_OBJECT
private:
    Stage *stage;

public:
    explicit ActionProgress(QWidget *parent = 0);
    ~ActionProgress();

    void setLabel(QString name);

    void set(Agent* agent, Stage *stage);

    void update();

private:
    Ui::ActionProgress *ui;

};

#endif // ACTIONPROGRESS_H
