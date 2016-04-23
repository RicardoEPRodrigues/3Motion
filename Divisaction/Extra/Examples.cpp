/*
 * File Example1.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Examples.h"

using namespace std;

namespace Divisaction {

    Examples::Examples() {
    }

    Examples::~Examples() {
    }

    WorldManager* Examples::example1() {
        Time::setTimeCalculator(new ChronoTimeCalculator());

        WorldManager* worldManager = new WorldManager();

        Agent * agentBob = new SingleActionAgent();
        agentBob->setName(string("Bob"));
        agentBob->addPossibleAction(new LongWalk());
        worldManager->addAgent(agentBob);

        Agent * agentHanna = new SingleReplyAgent();
        agentHanna->setName(string("Hanna"));
        agentHanna->setTimeToPerceive(1000);
        worldManager->addAgent(agentHanna);

        return worldManager;
    }

} /* namespace Divisaction */
