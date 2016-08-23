/*
 * File LongWalk.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "LongWalk.h"

using namespace std;

namespace Divisaction {

    LongWalk::LongWalk() : Action() {
        this->setName("Long Walk");

        auto anticipation = make_shared<TimeProgressiveStage>(string("starts crossing the bridge"), 4000, 10000);
        this->setStage(StageType::ANTICIPATION_INTERRUPTIBLE, anticipation);

        auto finished = make_shared<TimeProgressiveStage>(string("reaches the end of the bridge"), 4000, 7000);
        this->setStage(StageType::FOLLOW_THROUGH, finished);

        auto cancel = make_shared<TimeProgressiveStage>(string("stopped walking abruptly before reaching the end of the bridge"), 1000, 3000);
        this->setStage(StageType::CANCEL, cancel);
    }

    LongWalk::~LongWalk() {
    }

} /* namespace Divisaction */
