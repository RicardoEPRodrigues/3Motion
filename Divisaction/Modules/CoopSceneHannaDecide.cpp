/*
 * File CoopSceneHannaDecide.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "CoopSceneHannaDecide.h"

namespace Divisaction {
    void CoopSceneHannaDecide::execute() {
        if (auto mentalState = mentalStateWeak.lock()) {
            if (!alreadyActed) {
                if (!this->action && !mentalState->self.action && mentalState->self.availableActions.size() > 0) {
                    for (auto other = mentalState->others.begin();
                         other != mentalState->others.end(); ++other) {
                        if (auto agent = other->agent.lock()) {
                            if (agent->getName().compare("Bob") == 0 &&
                                other->action &&
                                other->action->getCurrentStageType() == StageType::ANTICIPATION_INTERRUPTIBLE) {
                                this->action = mentalState->self.availableActions[1];
                            }
                        }
                    }
                }
                if (this->action && !startCountdown) {
                    startTime = Time::now();
                    startCountdown = true;
                }
                if (this->action && startCountdown && Time::now() > startTime + interval) {
                    mentalState->self.action = this->action;
                    alreadyActed = true;
                }
            }
        }
    }
} /* namespace Divisaction */