/*
 * File Agent.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Agent.h"

using namespace std;

namespace Divisaction {

    Agent::Agent() : mentalState(make_shared<TheoryOfMind>()) {}


    void Agent::initialize() {
        mentalState->initialize(shared_from_this());

        for (auto perceiveModule = perceiveModules.begin();
             perceiveModule != perceiveModules.end(); ++perceiveModule) {
            (*perceiveModule)->initialize(mentalState);
        }
        for (auto reactModule = interpretModules.begin();
             reactModule != interpretModules.end(); ++reactModule) {
            (*reactModule)->initialize(mentalState);
        }
        for (auto performModule = performModules.begin();
             performModule != performModules.end(); ++performModule) {
            (*performModule)->initialize(mentalState);
        }
    }

    void Agent::addAvailableAction(std::shared_ptr<Action> action) {
        mentalState->self.addAction(action);
    }

    void Agent::removeAvailableAction(std::shared_ptr<Action>& action) {
        mentalState->self.removeAction(action);
    }

    void Agent::addAvailableEmotion(std::shared_ptr<Emotion> emotion) {
        mentalState->self.addEmotion(emotion);
    }

    void Agent::removeAvailableEmotion(std::shared_ptr<Emotion>& emotion) {
        mentalState->self.removeEmotion(emotion);
    }

    void Agent::perceive(const vector<std::shared_ptr<Event>>& events) {
        for (auto perceiveModule = perceiveModules.begin();
             perceiveModule != perceiveModules.end(); ++perceiveModule) {
            (*perceiveModule)->execute(events);
        }
    }

    void Agent::interpret() {
        for (auto interpretModule = interpretModules.begin();
             interpretModule != interpretModules.end(); ++interpretModule) {
            (*interpretModule)->execute();
        }
    }

    const vector<std::shared_ptr<Event>> Agent::perform() {
        auto eventsToSend = vector<std::shared_ptr<Event>>();
        for (auto performModule = performModules.begin();
             performModule != performModules.end(); ++performModule) {
            (*performModule)->execute(eventsToSend);
        }
        return eventsToSend;
    }

} /* namespace Divisaction */
