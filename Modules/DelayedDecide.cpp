/*
 * File DelayedDecide.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "DelayedDecide.h"

namespace Divisaction {
    DelayedDecide::DelayedDecide() : DelayedDecide(2000) {}

    DelayedDecide::DelayedDecide(milliseconds interval) : DModule(), interval(interval) {}

    void DelayedDecide::_execute() {
        if (!alreadyActed) {
            if (auto mentalState = mentalStateWeak.lock()) {
                if (!mentalState->self.action) {
                    this->selectAction(mentalState);
                }
            }
            if (this->action && !timer) {
                timer = wait(interval, [this]() {
                    if (auto mentalState = mentalStateWeak.lock()) {
                        mentalState->self.action = action;
                        alreadyActed = true;
                    }
                });
            }
        }
    }

    void DelayedDecide::selectAction(std::shared_ptr<MentalState> mentalState) {
        if (!this->action || this->action != mentalState->self.getAction(0)) {
            this->action = mentalState->self.getAction(0);
        }
    }
} /* namespace Divisaction */
