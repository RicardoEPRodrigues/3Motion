/*
 * File DelayedDecide.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "DelayedDecide.h"

namespace Divisaction {
    void DelayedDecide::execute() {
        if (!alreadyActed) {
            if (auto mentalState = mentalStateWeak.lock()) {
                if (!mentalState->self.action) {
                    this->selectAction(mentalState);
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

    void DelayedDecide::selectAction(std::shared_ptr<MentalState> mentalState) {
        if (!this->action || this->action != mentalState->self.availableActions[0]) {
            this->action = mentalState->self.availableActions[0];
        }
    }
} /* namespace Divisaction */