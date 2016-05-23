/*
 * File LongWalk.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "LongWalk.h"

using namespace std;

namespace Divisaction {

    LongWalk::LongWalk() : Action() {
        auto anticipation = make_shared<TimeProgressiveStage>(string("prepares to Walk"), 5000, true);
        anticipation->setTimeToPerceive(1000);
        this->setStage(StageType::ANTICIPATION, anticipation);

        auto execution = make_shared<TimeProgressiveStage>(string("starts Walking"), 10, true);
        execution->setTimeToPerceive(1000);
        this->setStage(StageType::EXECUTION, execution);

        auto followThrough = make_shared<TimeProgressiveStage>(string("walks"), 10000, true);
        followThrough->setTimeToPerceive(1000);
        this->setStage(StageType::FOLLOW_THROUGH, followThrough);

        auto finished = make_shared<TimeProgressiveStage>(string("finishes Walk"), 10, true);
        finished->setTimeToPerceive(3000);
        this->setStage(StageType::FINISHED, finished);

        auto cancel = make_shared<TimeProgressiveStage>(string("stopped Walking"), 100, true);
        cancel->setTimeToPerceive(1000);
        this->setStage(StageType::CANCEL, cancel);
    }

    LongWalk::~LongWalk() {
    }

} /* namespace Divisaction */
