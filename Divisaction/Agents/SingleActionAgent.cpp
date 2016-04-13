/*
 * File SingleActionAgent.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "SingleActionAgent.h"

namespace Divisaction {

    SingleActionAgent::SingleActionAgent()
            : Agent() {
        alreadyActed = false;
    }

    SingleActionAgent::~SingleActionAgent() {
    }

    void SingleActionAgent::decide() {
        if (!alreadyActed && !executable && possibleActions.size() > 0) {
            executable = possibleActions[0];
            alreadyActed = true;
        }
    }

} /* namespace Divisaction */
