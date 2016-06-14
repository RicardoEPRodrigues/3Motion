/*
 * File LongWalk.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "LongWalk.h"

using namespace std;

namespace Divisaction {

    LongWalk::LongWalk() : Action() {
        auto anticipation = make_shared<TimeProgressiveStage>(string("starts to walk"), 5000);
        anticipation->setTimeToPerceive(1000);
        this->setStage(StageType::ANTICIPATION_INTERRUPTIBLE, anticipation);

//        auto execution = make_shared<TimeProgressiveStage>(string("starts to walk"), 10);
//        execution->setTimeToPerceive(1000);
//        this->setStage(StageType::ANTICIPATION_UNINTERRUPTIBLE, execution);

        auto finished = make_shared<TimeProgressiveStage>(string("stops"), 1000);
        finished->setTimeToPerceive(1000);
        this->setStage(StageType::FOLLOW_THROUGH, finished);

        auto cancel = make_shared<TimeProgressiveStage>(string("stopped walking abruptly"), 1000);
        cancel->setTimeToPerceive(1000);
        this->setStage(StageType::CANCEL, cancel);
    }

    LongWalk::~LongWalk() {
    }

} /* namespace Divisaction */
