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
        for (IAgent *agent : agents) {
            delete agent;
        }
    }

    const vector<IAgent *> &WorldManager::getAgents() const {
        return agents;
    }

    void WorldManager::play() {
        this->playing = true;
    }

    void WorldManager::pause() {
        this->playing = false;
    }

    void WorldManager::addAgent(IAgent *agent) {
        if (agent) {
            this->agents.push_back(agent);
        }
    }

    void WorldManager::update() {
        if (playing) {
            for (IAgent *agent : agents) {
                agent->perceive(events);
            }
            events.clear();
            for (IAgent *agent : agents) {
                agent->react();
            }
            for (IAgent *agent : agents) {
                agent->decide();
            }
            for (IAgent *agent : agents) {
                vector<Event> events = agent->perform();
                for (Event event : events) {
                    this->events.push_back(event);
                }
            }

        }
    }

} /* namespace Divisaction */
