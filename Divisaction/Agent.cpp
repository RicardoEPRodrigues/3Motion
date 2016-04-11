/*
 * File Agent.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Agent.h"

using namespace std::placeholders;

namespace Divisaction {

    Agent::Agent() {
        worldManager = nullptr;
        action = nullptr;
        eventToSend = nullptr;
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
        action->started = bind(&Agent::actionStarted, this, _1);
        action->changed = bind(&Agent::actionChanged, this, _1, _2);
        action->finished = bind(&Agent::actionFinished, this, _1);
        this->possibleActions.push_back(action);
    }

    void Agent::removePossibleAction(Action* action) {
        std::vector<Action *>::iterator it = std::find(
                possibleActions.begin(), possibleActions.end(), action);
        if (it != possibleActions.end()) {
            possibleActions.erase(it);
        }
    }

    const std::string& Agent::getName() const {
        return name;
    }

    void Agent::setName(const std::string& name) {
        this->name = name;
    }

    void Agent::perceive(vector<Event> events) {
    }

    void Agent::react() {
    }

    void Agent::decide() {
    }

    Event* Agent::perform() {
        eventToSend = nullptr; // It may be modified if there are changes in the action that is being executed
        if (action) {
            if(action->execute()) {
            }
        }
        return eventToSend;
    }

    void Agent::actionStarted(Action* action) {
        this->eventToSend = generateEvent(this, action);
    }

    void Agent::actionChanged(Action* action, StageType stage) {
        if (stage != StageType::EXECUTION) {
            this->eventToSend = generateEvent(this, action);
        }
    }

    void Agent::actionFinished(Action* action) {
        this->eventToSend = generateEvent(this, action);
        this->action = nullptr;
    }

    Event* Agent::generateEvent(Agent* agent, Action* action) {
        return new Event(agent, action->getCurrentStageType(), action->getCurrentStage());
    }

} /* namespace Divisaction */
