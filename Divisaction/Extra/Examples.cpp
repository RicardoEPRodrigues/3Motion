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

        worldManager->setDescription(
                "This scenario contains 2 agents, Bob and Hanna.\n The agents are near a rope bridge.");

        auto agentBob = make_shared<SingleActionAgent>();
        agentBob->setName(string("Bob"));
        agentBob->addAvailableAction(make_shared<LongWalk>());
        agentBob->addAvailableEmotion(make_shared<Confidence>());
        agentBob->addAvailableEmotion(make_shared<Fear>());
        agentBob->addAvailableEmotion(make_shared<Happiness>());
        agentBob->addAvailableEmotion(make_shared<Relief>());
        agentBob->addAvailableEmotion(make_shared<Apprehension>());
        agentBob->initialize();
        worldManager->addAgent(agentBob);

        auto agentHanna = make_shared<SingleReplyAgent>();
        agentHanna->setName(string("Hanna"));
        agentHanna->addAvailableAction(make_shared<LongWalk>());
        agentHanna->addAvailableEmotion(make_shared<Confidence>());
        agentHanna->addAvailableEmotion(make_shared<Fear>());
        agentHanna->addAvailableEmotion(make_shared<Happiness>());
        agentHanna->addAvailableEmotion(make_shared<Relief>());
        agentHanna->addAvailableEmotion(make_shared<Apprehension>());
        agentHanna->initialize();
        worldManager->addAgent(agentHanna);

        return worldManager;
    }

    shared_ptr<WorldManager> Examples::exampleCoop() {
        Time::setTimeCalculator(new ChronoTimeCalculator());

        auto worldManager = make_shared<WorldManager>();
        worldManager->setDescription(
                "This scenario contains 2 agents, Bob and Hanna.\n The agents are near a rope bridge.");

        auto agentBob = make_shared<CoopSceneBob>();
        auto agentHanna = make_shared<CoopSceneHanna>();
        agentBob->setName(string("Bob"));
        agentBob->addAvailableAction(make_shared<LongWalk>());
        agentBob->addAvailableAction(make_shared<Follow>(agentHanna));
        agentBob->addAvailableEmotion(make_shared<Confidence>());
        agentBob->addAvailableEmotion(make_shared<Fear>());
        agentBob->addAvailableEmotion(make_shared<Happiness>());
        agentBob->addAvailableEmotion(make_shared<Relief>());
        agentBob->addAvailableEmotion(make_shared<Apprehension>());
        agentBob->addAvailableEmotion(make_shared<Sadness>());
        agentBob->initialize();
        worldManager->addAgent(agentBob);

        agentHanna->setName(string("Hanna"));
        agentHanna->addAvailableAction(make_shared<LongWalk>());
        agentHanna->addAvailableAction(make_shared<Follow>(agentBob));
        agentHanna->addAvailableEmotion(make_shared<Confidence>());
        agentHanna->addAvailableEmotion(make_shared<Fear>());
        agentHanna->addAvailableEmotion(make_shared<Happiness>());
        agentHanna->addAvailableEmotion(make_shared<Relief>());
        agentHanna->addAvailableEmotion(make_shared<Apprehension>());
        agentHanna->addAvailableEmotion(make_shared<Sadness>());
        agentHanna->initialize();
        worldManager->addAgent(agentHanna);

        return worldManager;
    }

    shared_ptr<WorldManager> Examples::exampleCoopReactive() {
        Time::setTimeCalculator(new ChronoTimeCalculator());

        auto worldManager = make_shared<WorldManager>();
        worldManager->setDescription(
                "This scenario contains 2 agents, Bob and Hanna.\n The agents are near a rope bridge.");

        auto agentBob = make_shared<CoopSceneBob>();
        auto agentHanna = make_shared<CoopSceneHanna>();
        agentBob->setName(string("Bob"));
        agentBob->addAvailableAction(make_shared<ReactiveLongWalk>());
        agentBob->addAvailableAction(make_shared<ReactiveFollow>(agentHanna));
//        agentBob->addAvailableEmotion(make_shared<Confidence>());
//        agentBob->addAvailableEmotion(make_shared<Fear>());
//        agentBob->addAvailableEmotion(make_shared<Happiness>());
//        agentBob->addAvailableEmotion(make_shared<Relief>());
//        agentBob->addAvailableEmotion(make_shared<Apprehension>());
//        agentBob->addAvailableEmotion(make_shared<Sadness>());
        agentBob->initialize();
        worldManager->addAgent(agentBob);

        agentHanna->setName(string("Hanna"));
        agentHanna->addAvailableAction(make_shared<ReactiveLongWalk>());
        agentHanna->addAvailableAction(make_shared<ReactiveFollow>(agentBob));
//        agentHanna->addAvailableEmotion(make_shared<Confidence>());
//        agentHanna->addAvailableEmotion(make_shared<Fear>());
//        agentHanna->addAvailableEmotion(make_shared<Happiness>());
//        agentHanna->addAvailableEmotion(make_shared<Relief>());
//        agentHanna->addAvailableEmotion(make_shared<Apprehension>());
//        agentHanna->addAvailableEmotion(make_shared<Sadness>());
        agentHanna->initialize();
        worldManager->addAgent(agentHanna);

        return worldManager;
    }

} /* namespace Divisaction */
