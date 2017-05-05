/*
 * File WorldManager.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "WorldManager.h"

using namespace std;

namespace Divisaction {

    WorldManager::WorldManager() {}

    WorldManager::~WorldManager() {}

    void WorldManager::update() {
        updateEvents(this->events);
        events.clear();
        updateInterpret();
        updatePerform(this->events);
    }

    void WorldManager::updateEvents(const std::vector<std::shared_ptr<Event>>& events) {
        for (auto agent = agents.begin(); agent != agents.end(); ++agent) {
            (*agent)->perceive(events);
        }
    }

    void WorldManager::updateInterpret() {
        for (auto agent = agents.begin(); agent != agents.end(); ++agent) {
            (*agent)->interpret();
        }
    }

    void WorldManager::updatePerform(std::vector<std::shared_ptr<Event>>& events) {
        for (auto agent = agents.begin(); agent != agents.end(); ++agent) {
            vector<shared_ptr<Event>> agentEvents = (*agent)->perform();
            events.insert(std::end(events), std::begin(agentEvents), std::end(agentEvents));
        }
    }

} /* namespace Divisaction */
