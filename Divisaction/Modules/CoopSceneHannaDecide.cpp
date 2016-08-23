/*
 * File CoopSceneHannaDecide.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "CoopSceneHannaDecide.h"

namespace Divisaction {

    void CoopSceneHannaDecide::selectAction(std::shared_ptr<MentalState> mentalState) {
        for (auto otherIter = mentalState->others.begin(); otherIter != mentalState->others.end(); ++otherIter) {
            if ((*otherIter).agentHasName("Bob") &&
                (*otherIter).actionInStage(StageType::ANTICIPATION_INTERRUPTIBLE)) {
                if (!this->action || this->action != mentalState->self.getAction(1)) {
                    this->action = mentalState->self.getAction(1);
                }
            }
        }
    }
} /* namespace Divisaction */