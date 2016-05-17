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


    void SingleActionAgent::react() { }

    void SingleActionAgent::decide() {
        if (!alreadyActed && !mentalState.self.action && possibleActions.size() > 0) {
            mentalState.self.action = possibleActions[0];
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
        this->performedEvent.reset(new ActionEvent(shared_from_this(), mentalState.self.action));
    }

    void SingleActionAgent::actionChanged(StageType stage) {
        if (stage != StageType::EXECUTION) {
            this->performedEvent.reset(new ActionEvent(shared_from_this(), mentalState.self.action));
        }
    }

    void SingleActionAgent::actionFinished() {
        this->performedEvent.reset(new ActionEvent(shared_from_this(), mentalState.self.action));
    }

} /* namespace Divisaction */
