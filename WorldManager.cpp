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
        updateReact();
        updateDecide();
        updatePerform(this->events);
    }

    void WorldManager::updateEvents(const std::vector<std::shared_ptr<Event>>& events) {
        for (auto agent = agents.begin(); agent != agents.end(); ++agent) {
            (*agent)->perceive(events);
        }
    }

    void WorldManager::updateReact() {
        for (auto agent = agents.begin(); agent != agents.end(); ++agent) {
            (*agent)->react();
        }
    }

    void WorldManager::updateDecide() {
        for (auto agent = agents.begin(); agent != agents.end(); ++agent) {
            (*agent)->decide();
        }
    }

    void WorldManager::updatePerform(std::vector<std::shared_ptr<Event>>& events) {
        for (auto agent = agents.begin(); agent != agents.end(); ++agent) {
            vector<shared_ptr<Event>> agentEvents = (*agent)->perform();
            events.insert(std::end(events), std::begin(agentEvents), std::end(agentEvents));
        }
    }

} /* namespace Divisaction */
