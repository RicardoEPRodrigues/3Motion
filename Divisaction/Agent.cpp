/*
 * File Agent.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Agent.h"

using namespace std;
using namespace std::placeholders;

namespace Divisaction {

    Agent::Agent() {
        executable = nullptr;
        performedEvent = nullptr;
    }

    Agent::~Agent() {
        for (Action* action : possibleActions) {
            delete action;
        }
    }

    Executable* Agent::getCurrentExecutable() const {
        return executable;
    }

    void Agent::addPossibleAction(Action* action) {
        action->started = bind(&Agent::actionStarted, this, _1);
        action->changed = bind(&Agent::actionChanged, this, _1, _2);
        action->finished = bind(&Agent::actionFinished, this, _1);
        this->possibleActions.push_back(action);
    }

    void Agent::removePossibleAction(Action* action) {
        std::vector<Action *>::iterator it = std::find(possibleActions.begin(),
                possibleActions.end(), action);
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

    vector<Event*> Agent::perform() {
        performedEvent = nullptr; // It may be modified if there are changes in the action that is being executed
        if (executable) {
            if (executable->execute()) {
                this->executable = nullptr;
            }
        }
        // Sends the event about the action of the current agent
        vector<Event*> responseEvents;
        if (performedEvent) {
            responseEvents.push_back(performedEvent);
            performedEvent = nullptr;
        }
        // Sends events as replies about other agents' actions
        for (Event* event : eventResponses) {
            responseEvents.push_back(event);
        }
        eventResponses.clear();

        return responseEvents;
    }

    void Agent::actionStarted(Action* action) {
        this->performedEvent = generateEvent(this, action);
    }

    void Agent::actionChanged(Action* action, StageType stage) {
        if (stage != StageType::EXECUTION) {
            this->performedEvent = generateEvent(this, action);
        }
    }

    void Agent::actionFinished(Action* action) {
        this->performedEvent = generateEvent(this, action);
    }

    Event* Agent::generateEvent(Agent* agent, Action* action) {
        return new Event(agent, action->getCurrentStageType(),
                action->getCurrentStage());
    }

} /* namespace Divisaction */
