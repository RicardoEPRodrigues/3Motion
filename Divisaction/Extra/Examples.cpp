/*
 * File Example1.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Examples.h"

namespace Divisaction {

    Examples::Examples() {
    }

    Examples::~Examples() {
    }

    WorldManager* Examples::example1() {
        WorldManager* worldManager = new WorldManager();

        Agent * agentBob = new SingleActionAgent();
        agentBob->setName(string("Bob"));
        agentBob->addPossibleAction(new LongWalk());
        worldManager->addAgent(agentBob);

//        Agent * agentHanna = new SingleActionAgent();
//        agentHanna->setName(string("Hanna"));
//        agentHanna->addPossibleAction(new LongWalk());
//        worldManager->addAgent(agentHanna);

        return worldManager;
    }

} /* namespace Divisaction */
