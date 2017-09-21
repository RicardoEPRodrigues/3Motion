/*
 * File DelayedDecide.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "DDelayedDecide.h"

namespace ThreeMotion {
    DDelayedDecide::DDelayedDecide() : DDelayedDecide(2000) {}

    DDelayedDecide::DDelayedDecide(milliseconds interval) : DModule(), interval(interval) {}

    void DDelayedDecide::_execute() {
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

    void DDelayedDecide::selectAction(std::shared_ptr<DTheoryOfMind> mentalState) {
        if (!this->action || this->action != mentalState->self.getAction(0)) {
            this->action = mentalState->self.getAction(0);
        }
    }
} /* namespace ThreeMotion */
