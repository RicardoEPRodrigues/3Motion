/*
 * File Follow.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "Follow.h"

using namespace std;

namespace Divisaction {

    Follow::Follow(std::weak_ptr<IAgent> agent) : Action() {
        if (auto agentshr = agent.lock()) {
            auto anticipation = make_shared<TimeProgressiveStage>(string("starts to follow " + agentshr->getName()), 4000, 10000);
            this->setStage(StageType::ANTICIPATION_INTERRUPTIBLE, anticipation);

//        auto execution = make_shared<TimeProgressiveStage>(string("starts to walk"), 10);
//        execution->setTimeToPerceive(1000);
//        this->setStage(StageType::ANTICIPATION_UNINTERRUPTIBLE, execution);

            auto finished = make_shared<TimeProgressiveStage>(string("stops following " + agentshr->getName()), 4000, 7000);
            this->setStage(StageType::FOLLOW_THROUGH, finished);

            auto cancel = make_shared<TimeProgressiveStage>(string("stopped following " + agentshr->getName() + " abruptly"), 1000, 3000);
            this->setStage(StageType::CANCEL, cancel);
        }
    }

} /* namespace Divisaction */