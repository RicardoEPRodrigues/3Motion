/*
 * File Agent.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Agent.h"

using namespace std;

namespace Divisaction {

    Agent::Agent() : mentalState(make_shared<MentalState>()) { }


    void Agent::initialize() {
        mentalState->initialize(shared_from_this());

        for (auto perceiveModule = perceiveModules.begin(); perceiveModule != perceiveModules.end(); ++perceiveModule) {
            (*perceiveModule)->initialize(mentalState);
        }
        for (auto reactModule = reactModules.begin(); reactModule != reactModules.end(); ++reactModule) {
            (*reactModule)->initialize(mentalState);
        }
        for (auto decideModule = decideModules.begin(); decideModule != decideModules.end(); ++decideModule) {
            (*decideModule)->initialize(mentalState);
        }
        for (auto performModule = performModules.begin(); performModule != performModules.end(); ++performModule) {
            (*performModule)->initialize(mentalState);
        }
    }


    const std::shared_ptr<Executable> Agent::getCurrentExecutable() const {
        return mentalState->self.action;
    }

    void Agent::addAvailableAction(std::shared_ptr<Action> action) {
        mentalState->self.addAvailableAction(action);
    }

    void Agent::removeAvailableAction(std::shared_ptr<Action>& action) {
        mentalState->self.removeAvailableAction(action);
    }

    void Agent::addAvailableEmotion(std::shared_ptr<Emotion> emotion) {
        mentalState->self.addAvailableEmotion(emotion);
    }

    void Agent::removeAvailableEmotion(std::shared_ptr<Emotion>& emotion) {
        mentalState->self.removeAvailableEmotion(emotion);
    }

    void Agent::perceive(const vector<std::shared_ptr<Event>>& events) {
        for (auto perceiveModule = perceiveModules.begin(); perceiveModule != perceiveModules.end(); ++perceiveModule) {
            (*perceiveModule)->execute(events);
        }
    }

    void Agent::react() {
        for (auto reactModule = reactModules.begin(); reactModule != reactModules.end(); ++reactModule) {
            (*reactModule)->execute();
        }
    }

    void Agent::decide() {
        for (auto decideModule = decideModules.begin(); decideModule != decideModules.end(); ++decideModule) {
            (*decideModule)->execute();
        }
    }

    const vector<std::shared_ptr<Event>> Agent::perform() {
        auto eventsToSend = vector<std::shared_ptr<Event>>();
        for (auto performModule = performModules.begin(); performModule != performModules.end(); ++performModule) {
            auto events = (*performModule)->execute();
            eventsToSend.insert(std::end(eventsToSend), std::begin(events), std::end(events));
        }
        return eventsToSend;
    }

} /* namespace Divisaction */
