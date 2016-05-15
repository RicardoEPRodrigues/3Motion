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


    void SingleActionAgent::react() {
        if (eventsPerceived.size() > 0) {
            this->eventsPerceived.clear();
        }
    }

    void SingleActionAgent::decide() {
        if (!alreadyActed && !selectedAction && possibleActions.size() > 0) {
            selectedAction = possibleActions[0];
            alreadyActed = true;
        }
    }

    void SingleActionAgent::addPossibleAction(shared_ptr<Action>& action) {
        Agent::addPossibleAction(action);
        action->started = bind(&SingleActionAgent::actionStarted, this);
        action->changed = bind(&SingleActionAgent::actionChanged, this, _1);
        action->finished = bind(&SingleActionAgent::actionFinished, this);
    }

    void SingleActionAgent::actionStarted() {
        this->performedEvent.reset(new ActionEvent(shared_from_this(), selectedAction));
    }

    void SingleActionAgent::actionChanged( StageType stage) {
        if (stage != StageType::EXECUTION) {
            this->performedEvent.reset(new ActionEvent(shared_from_this(), selectedAction));
        }
    }

    void SingleActionAgent::actionFinished() {
        this->performedEvent.reset(new ActionEvent(shared_from_this(), selectedAction));
    }

} /* namespace Divisaction */
