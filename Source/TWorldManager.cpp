/*
 * File WorldManager.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "TWorldManager.h"

using namespace std;

namespace ThreeMotion {

    TWorldManager::TWorldManager() = default;

    TWorldManager::~TWorldManager() = default;

    void TWorldManager::Initialize() {
        for (auto& agent:  agents) {
            agent->Initialize();
        }
    }

    void TWorldManager::Update() {
        UpdatePerceive(this->events);
        events.clear();
        UpdateInterpret();
        UpdatePerform(this->events);
    }

    void TWorldManager::UpdatePerceive(
            const std::vector<std::shared_ptr<TEvent>>& events) {
        for (auto& agent : agents) {
            agent->Perceive(events);
        }
    }

    void TWorldManager::UpdateInterpret() {
        for (auto& agent : agents) {
            agent->Interpret();
        }
    }

    void TWorldManager::UpdatePerform(
            std::vector<std::shared_ptr<TEvent>>& events) {
        for (auto& agent : agents) {
            vector<shared_ptr<TEvent>> agentEvents = agent->Perform();
            events.insert(std::end(events), std::begin(agentEvents),
                          std::end(agentEvents));
        }
    }

} /* namespace ThreeMotion */
