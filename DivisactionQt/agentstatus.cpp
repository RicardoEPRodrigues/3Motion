/*
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */
#include "agentstatus.h"
#include "ui_agentstatus.h"

using namespace std;
using namespace Divisaction;

AgentStatus::AgentStatus(QWidget *parent)
    : DivisactionWidget(parent), ui(new Ui::AgentStatus) {
    ui->setupUi(this);
}

AgentStatus::~AgentStatus() { delete ui; }

void AgentStatus::set(std::shared_ptr<Divisaction::IAgent> &iagent) {
    this->agent = dynamic_pointer_cast<Agent>(iagent);

    if (agent) {
        this->ui->agentName->setText("<html><head/><body><p><span style=\""
                                     "font-size:20pt; font-weight:600;\">" +
                                     QString::fromStdString(agent->getName()) +
                                     "</span></p></body></html>");
    } else {
        this->ui->agentName->setText(
            "<html><head/><body><p><span style=\""
            "font-size:20pt; font-weight:600;\">Agent is "
            "Null</span></p></body></html>");
    }
}

void AgentStatus::update(std::vector<std::shared_ptr<Event>> events) {
    if (agent) {
        for (shared_ptr<Event> event : events) {
            if (shared_ptr<IAgent> sender = event->sender.lock()) {
                if (agent == sender) {

                    shared_ptr<ActionEvent> actionEvent =
                        dynamic_pointer_cast<ActionEvent>(event);

                    if (actionEvent) {
                        action =
                            std::dynamic_pointer_cast<TimeProgressiveStage>(
                                actionEvent->action->getCurrentStage());

                        ui->actionDescription->setText(QString::fromStdString(
                            agent->getName() + " " +
                            actionEvent->action->getCurrentStage()->getName() +
                            "."));
                    } else {
                        shared_ptr<ReplyEvent> replyEvent =
                            dynamic_pointer_cast<ReplyEvent>(event);
                        if (replyEvent) {
                            emotion =
                                std::dynamic_pointer_cast<TimeProgressiveStage>(
                                    replyEvent->emotion->getStage());

                            if (shared_ptr<IAgent> origin =
                                    replyEvent->origin.lock()) {
                                ui->emotionDescription->setText(
                                    QString::fromStdString(
                                        agent->getName() + " " +
                                        replyEvent->emotion->getReplyText() +
                                        origin->getName() + ". " +
                                        agent->getName() + " " +
                                        replyEvent->emotion->getStage()
                                            ->getName()) +
                                    ".");
                            }
                        } else {
                            shared_ptr<EmotionEvent> emotionEvent =
                                dynamic_pointer_cast<EmotionEvent>(event);
                            if (emotionEvent) {
                                emotion = std::dynamic_pointer_cast<
                                    TimeProgressiveStage>(
                                    emotionEvent->emotion->getStage());

                                ui->emotionDescription->setText(
                                    QString::fromStdString(
                                        agent->getName() + " " +
                                        emotionEvent->emotion->getStage()
                                            ->getName() +
                                        "."));
                            }
                        }
                    }
                }
            }
        }

        if (action) {
            double progress = action->getProgress() * 100;
            ui->actionProgress->setValue(progress);
        }

        if (emotion) {
            double progress = emotion->getProgress() * 100;
            ui->emotionProgress->setValue(progress);
        }
    }
}
