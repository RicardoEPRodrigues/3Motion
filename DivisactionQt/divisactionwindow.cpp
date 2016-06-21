/*
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "divisactionwindow.h"
#include "ui_divisactionwindow.h"

using namespace Divisaction;
using namespace std;

DivisactionWindow::DivisactionWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DivisactionWindow)
{
    ui->setupUi(this);
    ui->ActionStackLayout->setAlignment(Qt::AlignTop);

    scrollbar = ui->StagesScroll->verticalScrollBar();
    QObject::connect(scrollbar, SIGNAL(rangeChanged(int,int)), this, SLOT(moveScrollBarToBottom(int, int)));

    worldManager = Examples::example2();
    this->on_pauseButton_clicked();
    QLabel* descriptionLabel = new QLabel();
    descriptionLabel->setText(QString(worldManager->getDescription().c_str()));
    ui->ActionStackLayout->addWidget(descriptionLabel);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateWorld()));
    Time::update();
    timer->start(20);
}

DivisactionWindow::~DivisactionWindow()
{
    delete ui;
    scrollbar = nullptr;
}


void DivisactionWindow::updateWorld() {
    Time::update();
    if (worldManager) {
        worldManager->update();

        this->updateProgress();
    }
}

struct ActionProgress_stage_equal {
    const std::shared_ptr<Stage> to_find;

    bool operator()(const ActionProgress* other) const {
        return other->stage == to_find;
    }
};

void DivisactionWindow::updateProgress()
{
    if (worldManager) {
        for(shared_ptr<IAgent> iagent: worldManager->getAgents()) {
            shared_ptr<Agent> agent = dynamic_pointer_cast<Agent>(iagent);
            if (agent) {
                shared_ptr<Action> action = dynamic_pointer_cast<Action>(agent->getMentalState()->self.action);
                if (action) {
                    auto stage = action->getCurrentStage();

                    auto it = std::find_if(actionsProgress.begin(), actionsProgress.end(), ActionProgress_stage_equal { stage });
                    if (it == actionsProgress.end()) {
                        ActionProgress * actionProgress = new ActionProgress();
                        actionProgress->set(iagent, stage);
                        ui->ActionStackLayout->addWidget(actionProgress);
                        actionsProgress.push_back(actionProgress);
                    }
                }

//                shared_ptr<Emotion> emotion = dynamic_pointer_cast<Emotion>(agent->getMentalState()->self.emotion);
//                if (emotion) {
//                    auto stage = emotion->getStage();

//                    auto it = actionsProgress.find(stage);
//                    if (it == actionsProgress.end()) {
//                        ActionProgress * actionProgress = new ActionProgress();
//                        actionProgress->set(iagent, stage);
//                        ui->ActionStackLayout->addWidget(actionProgress);
//                        actionsProgress[stage] = actionProgress;
//                    }
//                }
            }
        }
        for (shared_ptr<Event> event : worldManager->getCurrentEvents()) {
            shared_ptr<ReplyEvent> replyEvent = dynamic_pointer_cast<ReplyEvent>(event);
            if (replyEvent) {
                if (shared_ptr<IAgent> origin = replyEvent->origin.lock()) {
                    for(std::vector< ActionProgress *>::reverse_iterator progress = actionsProgress.rbegin(); progress != actionsProgress.rend(); progress++) {
                        if ((*progress)->agent == origin) {
                            (*progress)->addReply(event);
                            break;
                        }
                    }
                }
            } else {
                shared_ptr<EmotionEvent> emotionEvent = dynamic_pointer_cast<EmotionEvent>(event);
                if (emotionEvent) {
                    shared_ptr<Emotion> emotion = dynamic_pointer_cast<Emotion>(emotionEvent->emotion);
                    if (shared_ptr<IAgent> sender = emotionEvent->sender.lock()) {
                        for(std::vector< ActionProgress *>::reverse_iterator progress = actionsProgress.rbegin(); progress != actionsProgress.rend(); progress++) {
                            if ((*progress)->agent == sender) {
//                                (*progress)->addReply(event);
                                (*progress)->addEmotion(emotion);
                                break;
                            }
                        }
                    }
                }
            }
        }

        for(auto it = actionsProgress.begin(); it != actionsProgress.end(); ++it) {
            (*it)->update();
        }
    }
}


// Utilities

void DivisactionWindow::moveScrollBarToBottom(int min, int max) {
    Q_UNUSED(min);
    this->scrollbar->setValue(max); // Moves the scroll bar to the bottom so that new stage are seen first.
}

void DivisactionWindow::on_playButton_clicked()
{
    if (worldManager) {
        worldManager->play();
        ui->playButton->setEnabled(false);
        ui->pauseButton->setEnabled(true);
    }
}

void DivisactionWindow::on_pauseButton_clicked()
{
    if (worldManager) {
        worldManager->pause();
        ui->playButton->setEnabled(true);
        ui->pauseButton->setEnabled(false);
    }
}
