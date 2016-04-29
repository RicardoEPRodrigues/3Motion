/*
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef ACTIONPROGRESS_H
#define ACTIONPROGRESS_H

#include <QWidget>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>

#include <math.h>

#include "Agent.h"
#include "Stage.h"
#include "Event.h"
#include "Stages/TimeProgressiveStage.h"

using namespace Divisaction;

namespace Ui {
    class ActionProgress;
}

class ActionProgress : public QWidget
{
    Q_OBJECT
private:
    TimeProgressiveStage *stage;
    Agent* agent;

    std::vector<ActionProgress*> replies;

    QGraphicsOpacityEffect* opacity;
    QPropertyAnimation* animationOpacity;
public:
    explicit ActionProgress(QWidget *parent = 0);
    ~ActionProgress();

    void setLabel(QString name);

    void set(Agent* agent, Stage *stage);

    void addReply(Event reply);

    void update();

    Agent* getAgent() const;

private:
    Ui::ActionProgress *ui;

};

#endif // ACTIONPROGRESS_H
