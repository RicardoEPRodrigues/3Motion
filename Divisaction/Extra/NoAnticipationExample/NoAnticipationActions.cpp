/*
 * File ReactiveActions.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "NoAnticipationActions.h"
#include "../Stages/TimeProgressiveStage.h"

using namespace std;

namespace Divisaction {

    ReactiveFollow::ReactiveFollow(std::weak_ptr<IAgent> agent) : Action() {
        this->setName("Follow");

        if (auto agentshr = agent.lock()) {
//            auto anticipation = make_shared<TimeProgressiveStage>(string("starts to follow " + agentshr->getName()),
//                                                                  4000, 10000);
//            this->setStage(StageType::ANTICIPATION_INTERRUPTIBLE, anticipation);

            auto finished = make_shared<TimeProgressiveStage>(string("follows " + agentshr->getName()), 1000, 7000);
            this->setStage(StageType::FOLLOW_THROUGH, finished);

//            auto cancel = make_shared<TimeProgressiveStage>(
//                    string("stopped following " + agentshr->getName() + " abruptly"), 1000, 3000);
//            this->setStage(StageType::CANCEL, cancel);
        }
    }

    ReactiveLongWalk::ReactiveLongWalk() : Action() {
        this->setName("Long Walk");

//        auto anticipation = make_shared<TimeProgressiveStage>(string("starts crossing the bridge"), 4000, 10000);
//        this->setStage(StageType::ANTICIPATION_INTERRUPTIBLE, anticipation);

        auto finished = make_shared<TimeProgressiveStage>(string("crosses the bridge"), 1000, 7000);
        this->setStage(StageType::FOLLOW_THROUGH, finished);

//        auto cancel = make_shared<TimeProgressiveStage>(
//                string("stopped walking abruptly before reaching the end of the bridge"), 1000, 3000);
//        this->setStage(StageType::CANCEL, cancel);
    }

    ReactiveThrowBall::ReactiveThrowBall() {
        this->setName("Throw Ball");

//        auto anticipation = make_shared<TimeProgressiveStage>(string("starts swinging his arm to throw the ball"), 1000,
//                                                              2000);
//        this->setStage(StageType::ANTICIPATION_INTERRUPTIBLE, anticipation);
//
//        auto execution = make_shared<TimeProgressiveStage>(string("throws the ball"), 1000, 5000);
//        this->setStage(StageType::ANTICIPATION_UNINTERRUPTIBLE, execution);

        auto finished = make_shared<TimeProgressiveStage>(string("throws the ball and hits the target"), 1000, 1000);
        this->setStage(StageType::FOLLOW_THROUGH, finished);

//        auto cancel = make_shared<TimeProgressiveStage>(string("stops his swing and doesn't throw the ball"), 1000,
//                                                        1000);
//        this->setStage(StageType::CANCEL, cancel);
    }

} /* namespace Divisaction */