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
        shared_ptr<Action> longWalk = make_shared<LongWalk>();
        agentBob->addPossibleAction(longWalk);
        worldManager->addAgent(agentBob);

        auto agentHanna = make_shared<SingleReplyAgent>();
        agentHanna->setName(string("Hanna"));
        shared_ptr<Emotion> confidence = make_shared<Confidence>();
        agentHanna->addAvailableEmotion(confidence);
        worldManager->addAgent(agentHanna);

        return worldManager;
    }

} /* namespace Divisaction */
