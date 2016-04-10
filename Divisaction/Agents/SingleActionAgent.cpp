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

    Event * SingleActionAgent::perform() {
        Event* event = nullptr;
        if (!alreadyActed && !action && possibleActions.size() > 0) {
            action = possibleActions[0];
            event = new Event(this);
        }
        if (action) {
            if(action->execute()) {
                alreadyActed = true;
                action = nullptr;
                // completed action
            }
            if (event) {
                event->stage = action->getCurrentStage();
            }
        }
        return event;
    }

} /* namespace Divisaction */
