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
    }

    Agent::~Agent() {
        for (Action* action : possibleActions) {
            delete action;
        }
    }

    void Agent::setWorldManager(class WorldManager* worldManager) {
        this->worldManager = worldManager;
    }

    Action* Agent::getCurrentAction() const {
        return action;
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

    const std::string& Agent::getName() const {
        return name;
    }

    void Agent::setName(const std::string& name) {
        this->name = name;
    }

    void Agent::perceive() {
    }

    void Agent::react() {
    }

    void Agent::decide() {
    }

    Event* Agent::perform() {
        return nullptr;
    }

} /* namespace Divisaction */
