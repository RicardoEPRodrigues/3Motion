/*
 * File SingleActionAgent.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "SingleActionAgent.h"

namespace Divisaction {

    SingleActionAgent::SingleActionAgent() : Agent() {
        alreadyActed = false;
    }

    SingleActionAgent::~SingleActionAgent() {
    }

    void SingleActionAgent::perform() {
        if (!alreadyActed && !action && possibleActions.size() > 0) {
            action = possibleActions[0];
        }
        if (action) {
            if(action->execute()) {
                alreadyActed = true;
                action = nullptr;
                // completed action
            }
        }
    }

} /* namespace Divisaction */
