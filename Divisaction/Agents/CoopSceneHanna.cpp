/*
 * File CoopSceneHanna.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "CoopSceneHanna.h"

using namespace std;
using namespace placeholders;

namespace Divisaction {
    CoopSceneHanna::CoopSceneHanna()
            : Agent() {
        perceiveModules.push_back(std::make_unique<DelayPerceive>());

        reactModules.push_back(std::make_unique<CoopSceneHannaReact>());

        decideModules.push_back(std::make_unique<CoopSceneHannaDecide>());

        performModules.push_back(std::make_unique<Perform>());
    }

    void CoopSceneHanna::addAvailableAction(shared_ptr<Action> action) {
        Agent::addAvailableAction(action);
        action->started = bind(&CoopSceneHanna::actionStarted, this);
        action->changed = bind(&CoopSceneHanna::actionChanged, this, _1);
        action->finished = bind(&CoopSceneHanna::actionFinished, this);
    }

    void CoopSceneHanna::addAvailableEmotion(std::shared_ptr<Emotion> emotion) {
        Agent::addAvailableEmotion(emotion);
        emotion->started = bind(&CoopSceneHanna::emotionStarted, this);
        emotion->finished = bind(&CoopSceneHanna::emotionFinished, this);
    }

    void CoopSceneHanna::actionStarted() {
        mentalState->self.addEvent(make_shared<ActionEvent>(shared_from_this(), mentalState->self.action));
    }

    void CoopSceneHanna::actionChanged(StageType stage) {
        mentalState->self.addEvent(make_shared<ActionEvent>(shared_from_this(), mentalState->self.action, stage));
    }

    void CoopSceneHanna::actionFinished() {
        mentalState->self.addEvent(make_shared<ActionEvent>(shared_from_this(), mentalState->self.action));
    }

    void CoopSceneHanna::emotionStarted() {
        mentalState->self.addEvent(make_shared<EmotionEvent>(shared_from_this(), mentalState->self.emotion));
    }

    void CoopSceneHanna::emotionFinished() {
//        mentalState->self.addEvent(make_shared<EmotionEvent>(shared_from_this(), mentalState->self.stage));
    }
} /* namespace Divisaction */