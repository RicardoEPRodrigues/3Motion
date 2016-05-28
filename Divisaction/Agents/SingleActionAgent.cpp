/*
 * File SingleActionAgent.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "SingleActionAgent.h"

using namespace std;
using namespace std::placeholders;

namespace Divisaction {

    SingleActionAgent::SingleActionAgent()
            : Agent() {
        alreadyActed = false;
        alreadyFelt = false;
    }


    void SingleActionAgent::react() {
        if (!alreadyFelt && !mentalState->self.emotion && mentalState->self.availableEmotions.size() > 0) {
            mentalState->self.emotion = mentalState->self.availableEmotions[0];
            alreadyFelt = true;
        }
    }

    void SingleActionAgent::decide() {
        if (!alreadyActed && !mentalState->self.action && mentalState->self.availableActions.size() > 0) {
            mentalState->self.action = mentalState->self.availableActions[0];
            alreadyActed = true;
        }
    }

    void SingleActionAgent::addAvailableAction(shared_ptr<Action> action) {
        Agent::addAvailableAction(action);
        action->started = bind(&SingleActionAgent::actionStarted, this);
        action->changed = bind(&SingleActionAgent::actionChanged, this, _1);
        action->finished = bind(&SingleActionAgent::actionFinished, this);
    }

    void SingleActionAgent::addAvailableEmotion(std::shared_ptr<Emotion> emotion) {
        Agent::addAvailableEmotion(emotion);
        emotion->started = bind(&SingleActionAgent::emotionStarted, this);
        emotion->finished = bind(&SingleActionAgent::emotionFinished, this);
    }

    void SingleActionAgent::actionStarted() {
        mentalState->self.addEvent(make_shared<ActionEvent>(shared_from_this(), mentalState->self.action));
    }

    void SingleActionAgent::actionChanged(StageType stage) {
        mentalState->self.addEvent(make_shared<ActionEvent>(shared_from_this(), mentalState->self.action, stage));
    }

    void SingleActionAgent::actionFinished() {
        mentalState->self.addEvent(make_shared<ActionEvent>(shared_from_this(), mentalState->self.action));
    }

    void SingleActionAgent::emotionStarted() {
        mentalState->self.addEvent(make_shared<EmotionEvent>(shared_from_this(), mentalState->self.emotion));
    }

    void SingleActionAgent::emotionFinished() {
        mentalState->self.addEvent(make_shared<EmotionEvent>(shared_from_this(), mentalState->self.emotion));
    }

} /* namespace Divisaction */
