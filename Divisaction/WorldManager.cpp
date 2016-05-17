/*
 * File WorldManager.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "WorldManager.h"

using namespace std;

namespace Divisaction {

    WorldManager::WorldManager() {
        playing = true;
    }

    WorldManager::~WorldManager() { }

    const vector<std::shared_ptr<IAgent>> &WorldManager::getAgents() const {
        return agents;
    }

    void WorldManager::play() {
        this->playing = true;
    }

    void WorldManager::pause() {
        this->playing = false;
    }

    void WorldManager::addAgent(IAgent* agent) {
        if (agent) {
            this->agents.push_back(shared_ptr<IAgent> {agent});
        }
    }

    void WorldManager::addAgent(shared_ptr<IAgent>& agent) {
        if (agent) {
            this->agents.push_back(agent);
        }
    }

    void WorldManager::update() {
        if (playing) {
            for (auto agent = agents.begin(); agent != agents.end(); ++agent) {
                (*agent)->perceive(events);
            }
            events.clear();
            for (auto agent = agents.begin(); agent != agents.end(); ++agent) {
                (*agent)->react();
            }
            for (auto agent = agents.begin(); agent != agents.end(); ++agent) {
                (*agent)->decide();
            }
            for (auto agent = agents.begin(); agent != agents.end(); ++agent) {
                vector<shared_ptr<Event>> events = (*agent)->perform();
                this->events.insert(std::end(this->events), std::begin(events), std::end(events));
            }

        }
    }

} /* namespace Divisaction */
