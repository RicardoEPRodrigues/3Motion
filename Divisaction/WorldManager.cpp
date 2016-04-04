/*
 * File WorldManager.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "WorldManager.h"

namespace Divisaction {

    WorldManager::WorldManager() {

    }

    WorldManager::~WorldManager() {
        for (Agent * agent : agents) {
            delete agent;
        }
    }

    void WorldManager::update() {
        for (Agent * agent : agents) {
            agent->perceive();
        }
        for (Agent* agent : agents) {
            agent->decide();
        }
        for (Agent* agent : agents) {
            agent->act();
        }
    }

} /* namespace Divisaction */
