/*
 * File WorldManager.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "DWorldManager.h"

using namespace std;

namespace Divisaction {

    DWorldManager::DWorldManager() {}

    DWorldManager::~DWorldManager() {}

    void DWorldManager::update() {
        updateEvents(this->events);
        events.clear();
        updateInterpret();
        updatePerform(this->events);
    }

    void DWorldManager::updateEvents(const std::vector<std::shared_ptr<DEvent>>& events) {
        for (auto agent = agents.begin(); agent != agents.end(); ++agent) {
            (*agent)->perceive(events);
        }
    }

    void DWorldManager::updateInterpret() {
        for (auto agent = agents.begin(); agent != agents.end(); ++agent) {
            (*agent)->interpret();
        }
    }

    void DWorldManager::updatePerform(std::vector<std::shared_ptr<DEvent>>& events) {
        for (auto agent = agents.begin(); agent != agents.end(); ++agent) {
            vector<shared_ptr<DEvent>> agentEvents = (*agent)->perform();
            events.insert(std::end(events), std::begin(agentEvents), std::end(agentEvents));
        }
    }

} /* namespace Divisaction */
