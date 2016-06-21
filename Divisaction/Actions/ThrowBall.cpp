/*
 * File ThrowBall.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "ThrowBall.h"

using namespace std;

namespace Divisaction {
    ThrowBall::ThrowBall() {

        auto anticipation = make_shared<TimeProgressiveStage>(string("starts swinging his arm to throw the ball"), 1000, 2000);
        this->setStage(StageType::ANTICIPATION_INTERRUPTIBLE, anticipation);

        auto execution = make_shared<TimeProgressiveStage>(string("throws the ball"), 1000, 5000);
        this->setStage(StageType::ANTICIPATION_UNINTERRUPTIBLE, execution);

        auto finished = make_shared<TimeProgressiveStage>(string("sees the ball hit the target"), 1000, 1000);
        this->setStage(StageType::FOLLOW_THROUGH, finished);

        auto cancel = make_shared<TimeProgressiveStage>(string("stops his swing and doesn't throw the ball"), 1000, 1000);
        this->setStage(StageType::CANCEL, cancel);
    }

} /* namespace Divisaction */