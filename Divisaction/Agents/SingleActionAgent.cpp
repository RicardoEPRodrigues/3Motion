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
        perceiveModules.push_back(std::make_unique<DelayPerceive>());

        reactModules.push_back(std::make_unique<SingleEmotionReact>());
        reactModules.push_back(std::make_unique<ReplyReact>());

        decideModules.push_back(std::make_unique<SingleActionDecide>());

        performModules.push_back(std::make_unique<Perform>());
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
//        mentalState->self.addEvent(make_shared<EmotionEvent>(shared_from_this(), mentalState->self.stage));
    }

} /* namespace Divisaction */
