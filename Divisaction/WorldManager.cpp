/*
 * File WorldManager.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "WorldManager.h"

namespace Divisaction {

    WorldManager::WorldManager() {
        playing = true;
    }

    WorldManager::~WorldManager() {
        for (Agent * agent : agents) {
            delete agent;
        }
    }

    const vector<Agent*>& WorldManager::getAgents() const {
        return agents;
    }

    void WorldManager::play() {
        this->playing = true;
    }

    void WorldManager::pause() {
        this->playing = false;
    }

    void WorldManager::addAgent(Agent* agent) {
        if (agent) {
            agent->setWorldManager(this);
            this->agents.push_back(agent);
        }
    }

    void WorldManager::update() {
        if (playing) {
            for (Agent * agent : agents) {
                agent->perceive(events);
            }
            events.clear();
            for (Agent* agent : agents) {
                agent->decide();
            }
            for (Agent* agent : agents) {
                Event * event = agent->perform();
                if (event) {
                    events.push_back(*event);
                }
            }

        }
    }

} /* namespace Divisaction */
