/*
 * File CoopSceneHannaDecide.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "CoopSceneHannaDecide.h"

namespace Divisaction {

    void CoopSceneHannaDecide::selectAction(std::shared_ptr<MentalState> mentalState) {
        for (auto other = mentalState->others.begin();
             other != mentalState->others.end(); ++other) {
            if (auto agent = other->agent.lock()) {
                if (agent->getName().compare("Bob") == 0 &&
                    other->action &&
                    other->action->getCurrentStageType() == StageType::ANTICIPATION_INTERRUPTIBLE) {
                    if (!this->action || this->action != mentalState->self.availableActions[1]) {
                        this->action = mentalState->self.availableActions[1];
                    }
                }
            }
        }
    }
} /* namespace Divisaction */