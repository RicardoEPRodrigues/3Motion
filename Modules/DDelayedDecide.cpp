/*
 * File DelayedDecide.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "DDelayedDecide.h"

namespace ThreeMotion {
    DDelayedDecide::DDelayedDecide() : DDelayedDecide(2000) {}

    DDelayedDecide::DDelayedDecide(milliseconds interval) : TModule(), interval(interval) {}

    void DDelayedDecide::_execute() {
        if (!alreadyActed) {
            if (auto mentalState = theoryOfMindWeak.lock()) {
                if (!mentalState->self.action) {
                    this->selectAction(mentalState);
                }
            }
            if (this->action && !timer) {
                timer = Wait(interval, [this]() {
                    if (auto mentalState = theoryOfMindWeak.lock()) {
                        mentalState->self.action = action;
                        alreadyActed = true;
                    }
                });
            }
        }
    }

    void DDelayedDecide::selectAction(std::shared_ptr<TTheoryOfMind> mentalState) {
        if (!this->action || this->action != mentalState->self.GetAction(0)) {
            this->action = mentalState->self.GetAction(0);
        }
    }
} /* namespace ThreeMotion */
