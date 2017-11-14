/*
 * File SingleActionDecide.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "DSingleActionDecide.h"

namespace ThreeMotion {

    void DSingleActionDecide::_execute() {
        if (auto mentalState = theoryOfMindWeak.lock()) {
            if (!alreadyActed && !mentalState->self.action &&
                    mentalState->self.CountActions() > 0) {
                mentalState->self.action = mentalState->self.GetAction(0);
                alreadyActed = true;
            }
        }
    }
} /* namespace ThreeMotion */