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

    shared_ptr<WorldManager> Examples::example1() {
        Time::setTimeCalculator(new ChronoTimeCalculator());

        auto worldManager = make_shared<WorldManager>();

        auto agentBob = make_shared<SingleActionAgent>();
        agentBob->setName(string("Bob"));
        agentBob->addAvailableAction(make_shared<LongWalk>());
        agentBob->addAvailableEmotion(make_shared<Confidence>());
        agentBob->initialize();
        worldManager->addAgent(agentBob);

        auto agentHanna = make_shared<SingleReplyAgent>();
        agentHanna->setName(string("Hanna"));
        agentHanna->addAvailableEmotion(make_shared<Confidence>());
        agentHanna->initialize();
        worldManager->addAgent(agentHanna);

        return worldManager;
    }

} /* namespace Divisaction */
