/*
 * File SingleActionDecide.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "SingleActionDecide.h"

namespace Divisaction {

    void SingleActionDecide::execute() {
        if (auto mentalState = mentalStateWeak.lock()) {
            if (!alreadyActed && !mentalState->self.action && mentalState->self.availableActions.size() > 0) {
                mentalState->self.action = mentalState->self.availableActions[0];
                alreadyActed = true;
            }
        }
    }
} /* namespace Divisaction */