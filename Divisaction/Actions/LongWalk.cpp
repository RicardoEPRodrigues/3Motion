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
        anticipation->setTimeToPerceive(1000);
        this->setStage(StageType::ANTICIPATION, anticipation);

        TimeProgressiveStage* execution = new TimeProgressiveStage(string("Starts Walking"), 10, true);
        execution->setTimeToPerceive(1000);
        this->setStage(StageType::EXECUTION, execution);

        TimeProgressiveStage* followThrough = new TimeProgressiveStage(string("Walks"), 10000, true);
        followThrough->setTimeToPerceive(1000);
        this->setStage(StageType::FOLLOW_THROUGH, followThrough);

        TimeProgressiveStage* cancel = new TimeProgressiveStage(string("Stopped Walking"), 100, true);
        cancel->setTimeToPerceive(1000);
        this->setStage(StageType::CANCEL, cancel);
    }

    LongWalk::~LongWalk() {
    }

} /* namespace Divisaction */
