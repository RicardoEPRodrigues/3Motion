/*
 * File Agent.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "DAgent.h"

using namespace std;

namespace ThreeMotion {

    DAgent::DAgent() : theoryOfMind(make_shared<TTheoryOfMind>()) {}


    void DAgent::initialize() {
        theoryOfMind->Initialize(shared_from_this());

        for (auto perceiveModule = perceiveModules.begin();
             perceiveModule != perceiveModules.end(); ++perceiveModule) {
            (*perceiveModule)->Initialize(theoryOfMind);
        }
        for (auto reactModule = interpretModules.begin();
             reactModule != interpretModules.end(); ++reactModule) {
            (*reactModule)->Initialize(theoryOfMind);
        }
        for (auto performModule = performModules.begin();
             performModule != performModules.end(); ++performModule) {
            (*performModule)->Initialize(theoryOfMind);
        }
    }

    void DAgent::addAvailableAction(std::shared_ptr<TAction> action) {
        theoryOfMind->self.addAction(action);
    }

    void DAgent::removeAvailableAction(std::shared_ptr<TAction>& action) {
        theoryOfMind->self.removeAction(action);
    }

    void DAgent::addAvailableEmotion(std::shared_ptr<TEmotion> emotion) {
        theoryOfMind->self.addEmotion(emotion);
    }

    void DAgent::removeAvailableEmotion(std::shared_ptr<TEmotion>& emotion) {
        theoryOfMind->self.removeEmotion(emotion);
    }

    void DAgent::perceive(const vector<std::shared_ptr<TEvent>>& events) {
        for (auto perceiveModule = perceiveModules.begin();
             perceiveModule != perceiveModules.end(); ++perceiveModule) {
            (*perceiveModule)->Execute(events);
        }
    }

    void DAgent::interpret() {
        for (auto interpretModule = interpretModules.begin();
             interpretModule != interpretModules.end(); ++interpretModule) {
            (*interpretModule)->Execute();
        }
    }

    const vector<std::shared_ptr<TEvent>> DAgent::perform() {
        auto eventsToSend = vector<std::shared_ptr<TEvent>>();
        for (auto performModule = performModules.begin();
             performModule != performModules.end(); ++performModule) {
            (*performModule)->Execute(eventsToSend);
        }
        return eventsToSend;
    }

} /* namespace ThreeMotion */
