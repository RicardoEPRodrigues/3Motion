/*
 * File Agent.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "TAgent.h"

using namespace std;

namespace ThreeMotion {

    TAgent::TAgent() : TIAgent(), theoryOfMind(make_shared<TTheoryOfMind>()) { }

    TAgent::~TAgent() = default;

    void TAgent::AddAvailableAction(std::shared_ptr<TAction> const& action) {
        theoryOfMind->self.AddAction(action);
    }

    void TAgent::RemoveAvailableAction(std::shared_ptr<TAction> const& action) {
        theoryOfMind->self.RemoveAction(action);
    }

    void TAgent::AddAvailableEmotion(std::shared_ptr<TEmotion> const& emotion) {
        theoryOfMind->self.AddEmotion(emotion);
    }

    void
    TAgent::RemoveAvailableEmotion(std::shared_ptr<TEmotion> const& emotion) {
        theoryOfMind->self.RemoveEmotion(emotion);
    }

    void TAgent::Initialize() {
        theoryOfMind->Initialize(shared_from_this());

        for (auto& perceiveModule : perceiveModules) {
            perceiveModule->Initialize(theoryOfMind);
        }
        for (auto& interpretModule : interpretModules) {
            interpretModule->Initialize(theoryOfMind);
        }
        for (auto& performModule : performModules) {
            performModule->Initialize(theoryOfMind);
        }
    }

    void TAgent::Perceive(const vector<shared_ptr<TEvent>>& events) {
        for (auto& perceiveModule : perceiveModules) {
            perceiveModule->Execute(events);
        }
    }

    void TAgent::Interpret() {
        for (auto& interpretModule : interpretModules) {
            interpretModule->Execute();
        }
    }

    const vector<std::shared_ptr<TEvent>> TAgent::Perform() {
        auto eventsToSend = vector<std::shared_ptr<TEvent>>();
        for (auto& performModule : performModules) {
            performModule->Execute(eventsToSend);
        }
        return eventsToSend;
    }

} /* namespace ThreeMotion */
