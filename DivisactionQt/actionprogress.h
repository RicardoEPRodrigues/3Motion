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

    std::vector<ActionProgress*> replies;

    QGraphicsOpacityEffect* opacity;
    QPropertyAnimation* animationOpacity;
public:
    explicit ActionProgress(QWidget *parent = 0);
    ~ActionProgress();

    std::shared_ptr<IAgent> agent;

    void setLabel(QString name);

    void set(std::shared_ptr<IAgent>& agent, std::shared_ptr<Stage> stage);

    void addReply(std::shared_ptr<Event> reply);

    void update();

    std::shared_ptr<IAgent> getAgent() const;

private:
    Ui::ActionProgress *ui;

};

#endif // ACTIONPROGRESS_H
