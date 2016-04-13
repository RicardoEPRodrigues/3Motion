/*
 * File LongWalk.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "LongWalk.h"

using namespace std;

namespace Divisaction {

    LongWalk::LongWalk() : Action() {
        TimeProgressiveStage* anticipation = new TimeProgressiveStage(string("Prepares to Walk"), 5000, true);
        this->setStage(StageType::ANTICIPATION, anticipation);

        TimeProgressiveStage* execution = new TimeProgressiveStage(string("Starts Walking"), 10, true);
        this->setStage(StageType::EXECUTION, execution);

        TimeProgressiveStage* followThrough = new TimeProgressiveStage(string("Walks"), 10000, true);
        this->setStage(StageType::FOLLOW_THROUGH, followThrough);

        TimeProgressiveStage* cancel = new TimeProgressiveStage(string("Stopped Walking"), 100, true);
        this->setStage(StageType::CANCEL, cancel);
    }

    LongWalk::~LongWalk() {
    }

} /* namespace Divisaction */
