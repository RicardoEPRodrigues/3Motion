/*
 * File CoopSceneBob.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "CoopSceneBob.h"

using namespace std;
using namespace placeholders;

namespace Divisaction {

    CoopSceneBob::CoopSceneBob()
            : Agent() {
        perceiveModules.push_back(std::make_unique<DelayPerceive>());

        reactModules.push_back(std::make_unique<CoopSceneBobReact>());

        decideModules.push_back(std::make_unique<SingleActionDecide>());

        performModules.push_back(std::make_unique<Perform>());
    }

    void CoopSceneBob::addAvailableAction(shared_ptr<Action> action) {
        Agent::addAvailableAction(action);
        action->started = bind(&CoopSceneBob::actionStarted, this);
        action->changed = bind(&CoopSceneBob::actionChanged, this, _1);
        action->finished = bind(&CoopSceneBob::actionFinished, this);
    }

    void CoopSceneBob::addAvailableEmotion(std::shared_ptr<Emotion> emotion) {
        Agent::addAvailableEmotion(emotion);
        emotion->started = bind(&CoopSceneBob::emotionStarted, this);
        emotion->finished = bind(&CoopSceneBob::emotionFinished, this);
    }

    void CoopSceneBob::actionStarted() {
        mentalState->self.addEvent(make_shared<ActionEvent>(shared_from_this(), mentalState->self.action));
    }

    void CoopSceneBob::actionChanged(StageType stage) {
        mentalState->self.addEvent(make_shared<ActionEvent>(shared_from_this(), mentalState->self.action, stage));
    }

    void CoopSceneBob::actionFinished() {
        mentalState->self.addEvent(make_shared<ActionEvent>(shared_from_this(), mentalState->self.action));
    }

    void CoopSceneBob::emotionStarted() {
        mentalState->self.addEvent(make_shared<EmotionEvent>(shared_from_this(), mentalState->self.emotion));
    }

    void CoopSceneBob::emotionFinished() {
//        mentalState->self.addEvent(make_shared<EmotionEvent>(shared_from_this(), mentalState->self.stage));
    }

} /* namespace Divisaction */