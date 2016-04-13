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
                vector<Event*> events = agent->perform();
                for (Event* event : events) {
                    if (event) {
                        this->events.push_back(*event);
                    }
                }
            }

        }
    }

} /* namespace Divisaction */
