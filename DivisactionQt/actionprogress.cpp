/*
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "actionprogress.h"
#include "ui_actionprogress.h"

using namespace std;

ActionProgress::ActionProgress(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ActionProgress)
{
    ui->setupUi(this);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);

    opacity = new QGraphicsOpacityEffect;
    animationOpacity = new QPropertyAnimation(opacity, "opacity");
    ui->actionProgressHolder->setGraphicsEffect(opacity);

    animationOpacity->setDuration(500);
    animationOpacity->setStartValue(0.0);
    animationOpacity->setEndValue(1.0);
    animationOpacity->setEasingCurve( QEasingCurve::InCubic );
    animationOpacity->start();

    ui->repliesHolder->setVisible(false);
}

ActionProgress::~ActionProgress()
{
    delete ui;
    delete animationOpacity;
    delete opacity;
}

void ActionProgress::set(shared_ptr<IAgent>& agent, shared_ptr<Stage> stage)
{
    this->stage = std::dynamic_pointer_cast<TimeProgressiveStage>(stage);
    if (this->stage) {
        concatDescription(QString(agent->getName().c_str()) + " " + QString(this->stage->getName().c_str()));
        ui->progressBar->setValue(floor(this->stage->getProgress() * 100));
    }
    this->agent = agent;
}

void ActionProgress::update()
{
    if (this->stage) {
        auto progress = this->stage->getProgress() * 100;
        progress = ui->progressBar->value() > progress ? ui->progressBar->value() : progress;
        ui->progressBar->setValue(progress);
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

void ActionProgress::addEmotion(std::shared_ptr<Emotion> emotion) {
    if (emotion) {
        concatDescription(QString(emotion->getStage()->getName().c_str()));
    }
}

void ActionProgress::concatDescription(QString text) {
    if (this->ui->Description->text().length() > 0) {
        this->ui->Description->setText(this->ui->Description->text() + " and " + text);
    } else {
        this->ui->Description->setText(text);
    }
}

void ActionProgress::addReply(shared_ptr<Event> reply) {
    shared_ptr<EmotionEvent> emotionEvent = dynamic_pointer_cast<EmotionEvent>(reply);
    if (emotionEvent) {
        if (auto sender = emotionEvent->sender.lock()) {
            ActionProgress * actionProgress = new ActionProgress(this);
            actionProgress->set(sender, emotionEvent->emotion->getStage());
            this->replies.push_back(actionProgress);
            this->ui->replies->addWidget(actionProgress);
        }
    }
}
