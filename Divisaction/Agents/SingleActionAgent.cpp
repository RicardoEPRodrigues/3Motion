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

    void SingleActionAgent::perceive(vector<Event> events) {
    }

    void SingleActionAgent::decide() {
        if (!alreadyActed && !action && possibleActions.size() > 0) {
            action = possibleActions[0];
            alreadyActed = true;
        }
    }

} /* namespace Divisaction */
