/*
 * File LongWalk.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "LongWalk.h"

namespace Divisaction {

    LongWalk::LongWalk() : Action() {
        Stage* anticipation = new Stage(string("Prepares to Walk"), 5000, true);
        this->setStage(StageType::anticipation, anticipation);

        Stage* execution = new Stage(string("Starts Walking"), 10, true);
        this->setStage(StageType::execution, execution);

        Stage* followThrough = new Stage(string("Walks"), 10000, true);
        this->setStage(StageType::followThrough, followThrough);

        Stage* cancel = new Stage(string("Stopped Walking"), 10, true);
        this->setStage(StageType::cancel, cancel);
    }

    LongWalk::~LongWalk() {
    }

} /* namespace Divisaction */
