/*
 * File Agent.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Agent.h"

namespace Divisaction {

    Agent::Agent() {
        worldManager = nullptr;
        action = nullptr;
        alreadyActed = false;
    }

    Agent::~Agent() {
        for (Action* action : possibleActions) {
            delete action;
        }
    }

    void Agent::setWorldManager(class WorldManager* worldManager) {
        this->worldManager = worldManager;
    }

    void Agent::addPossibleAction(Action* action) {
        this->possibleActions.push_back(action);
    }

    void Agent::removePossibleAction(Action* action) {
        for (std::vector<Action *>::iterator it = possibleActions.begin(); it != possibleActions.end(); ++it) {
            if (*it == action) {
                possibleActions.erase(it);
                break;
            }
        }
    }

    void Agent::perceive() {
    }

    void Agent::decide() {
    }

    void Agent::act() {
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
