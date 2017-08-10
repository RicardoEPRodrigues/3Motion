/*
 * File SingleActionDecide.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "DSingleActionDecide.h"

namespace Divisaction {

    void DSingleActionDecide::_execute() {
        if (auto mentalState = mentalStateWeak.lock()) {
            if (!alreadyActed && !mentalState->self.action &&
                mentalState->self.countActions() > 0) {
                mentalState->self.action = mentalState->self.getAction(0);
                alreadyActed = true;
            }
        }
    }
} /* namespace Divisaction */