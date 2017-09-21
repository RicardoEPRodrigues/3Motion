/*
 * File Agent.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "DAgent.h"

using namespace std;

namespace ThreeMotion {

    DAgent::DAgent() : mentalState(make_shared<DTheoryOfMind>()) {}


    void DAgent::initialize() {
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

    void DAgent::addAvailableAction(std::shared_ptr<DAction> action) {
        mentalState->self.addAction(action);
    }

    void DAgent::removeAvailableAction(std::shared_ptr<DAction>& action) {
        mentalState->self.removeAction(action);
    }

    void DAgent::addAvailableEmotion(std::shared_ptr<DEmotion> emotion) {
        mentalState->self.addEmotion(emotion);
    }

    void DAgent::removeAvailableEmotion(std::shared_ptr<DEmotion>& emotion) {
        mentalState->self.removeEmotion(emotion);
    }

    void DAgent::perceive(const vector<std::shared_ptr<DEvent>>& events) {
        for (auto perceiveModule = perceiveModules.begin();
             perceiveModule != perceiveModules.end(); ++perceiveModule) {
            (*perceiveModule)->execute(events);
        }
    }

    void DAgent::interpret() {
        for (auto interpretModule = interpretModules.begin();
             interpretModule != interpretModules.end(); ++interpretModule) {
            (*interpretModule)->execute();
        }
    }

    const vector<std::shared_ptr<DEvent>> DAgent::perform() {
        auto eventsToSend = vector<std::shared_ptr<DEvent>>();
        for (auto performModule = performModules.begin();
             performModule != performModules.end(); ++performModule) {
            (*performModule)->execute(eventsToSend);
        }
        return eventsToSend;
    }

} /* namespace ThreeMotion */
