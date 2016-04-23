/*
 * File SingleActionAgent.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "SingleActionAgent.h"

using namespace std;
using namespace std::placeholders;

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

    void SingleActionAgent::addPossibleAction(Action *action) {
        Agent::addPossibleAction(action);
        action->started = bind(&SingleActionAgent::actionStarted, this, _1);
        action->changed = bind(&SingleActionAgent::actionChanged, this, _1, _2);
        action->finished = bind(&SingleActionAgent::actionFinished, this, _1);
    }

    void SingleActionAgent::actionStarted(Action *action) {
        this->performedEvent = generateEvent(this, action);
    }

    void SingleActionAgent::actionChanged(Action *action, StageType stage) {
        if (stage != StageType::EXECUTION) {
            this->performedEvent = generateEvent(this, action);
        }
    }

    void SingleActionAgent::actionFinished(Action *action) {
        this->performedEvent = generateEvent(this, action);
    }

} /* namespace Divisaction */
