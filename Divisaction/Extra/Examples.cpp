/*
 * File Example1.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Examples.h"

#include "../Extra/NoAnticipation/Modules/CoopSceneHannaReact.h"
#include "../Extra/NoAnticipation/Modules/CoopSceneBobReact.h"
#include "../Extra/Screening/Modules/CoopSceneBobReact.h"
#include "../Extra/Screening/Modules/CoopSceneHannaReact.h"
#include "../Modules/CoopSceneBobReact.h"
#include "../Modules/CoopSceneBobDecide.h"
#include "../Modules/CoopSceneHannaReact.h"
#include "../Modules/CoopSceneHannaDecide.h"
#include "../Modules/DelayPerceive.h"
#include "../Modules/SingleEmotionReact.h"
#include "../Modules/ReplyReact.h"
#include "../Modules/SingleActionDecide.h"
#include "../Modules/Perform.h"
#include "../Modules/SingleReplyReact.h"

using namespace std;

namespace Divisaction {

    Examples::Examples() {}

    Examples::~Examples() {}

    shared_ptr<WorldManager> Examples::example1() {
        Time::setTimeCalculator(new ChronoTimeCalculator());

        auto worldManager = make_shared<WorldManager>();

        worldManager->description = "This scenario contains 2 agents, Bob and Hanna.\n The agents are near a rope bridge.";

        auto agentBob = make_shared<Agent>();
        agentBob->name = string("Bob");
        agentBob->perceiveModules.push_back(std::make_unique<DelayPerceive>());
        agentBob->reactModules.push_back(std::make_unique<SingleEmotionReact>());
        agentBob->reactModules.push_back(std::make_unique<ReplyReact>());
        agentBob->decideModules.push_back(std::make_unique<SingleActionDecide>());
        agentBob->performModules.push_back(std::make_unique<Perform>());
        agentBob->addAvailableAction(make_shared<LongWalk>());
        agentBob->addAvailableEmotion(make_shared<Confidence>());
        agentBob->addAvailableEmotion(make_shared<Fear>());
        agentBob->addAvailableEmotion(make_shared<Happiness>());
        agentBob->addAvailableEmotion(make_shared<Relief>());
        agentBob->addAvailableEmotion(make_shared<Apprehension>());
        agentBob->initialize();
        worldManager->agents.push_back(agentBob);

        auto agentHanna = make_shared<Agent>();
        agentHanna->name = string("Hanna");
        agentHanna->perceiveModules.push_back(std::make_unique<DelayPerceive>());
        agentHanna->reactModules.push_back(std::make_unique<SingleReplyReact>());
        agentHanna->performModules.push_back(std::make_unique<Perform>());
        agentHanna->addAvailableAction(make_shared<LongWalk>());
        agentHanna->addAvailableEmotion(make_shared<Confidence>());
        agentHanna->addAvailableEmotion(make_shared<Fear>());
        agentHanna->addAvailableEmotion(make_shared<Happiness>());
        agentHanna->addAvailableEmotion(make_shared<Relief>());
        agentHanna->addAvailableEmotion(make_shared<Apprehension>());
        agentHanna->initialize();
        worldManager->agents.push_back(agentHanna);

        return worldManager;
    }

    shared_ptr<WorldManager> Examples::exampleCoop() {
        Time::setTimeCalculator(new ChronoTimeCalculator());

        auto worldManager = make_shared<WorldManager>();
        worldManager->description = "This scenario contains 2 agents, Bob and Hanna.\n The agents are near a rope bridge.";

        auto agentBob = make_shared<Agent>();
        auto agentHanna = make_shared<Agent>();
        agentBob->name = string("Bob");
        agentBob->perceiveModules.push_back(std::make_unique<DelayPerceive>());
        agentBob->reactModules.push_back(std::make_unique<CoopSceneBobReact>());
        agentBob->decideModules.push_back(std::make_unique<CoopSceneBobDecide>());
        agentBob->performModules.push_back(std::make_unique<Perform>());
        agentBob->addAvailableAction(make_shared<LongWalk>());
        agentBob->addAvailableAction(make_shared<Follow>(agentHanna));
        agentBob->addAvailableEmotion(make_shared<Confidence>());
        agentBob->addAvailableEmotion(make_shared<Fear>());
        agentBob->addAvailableEmotion(make_shared<Happiness>());
        agentBob->addAvailableEmotion(make_shared<Relief>());
        agentBob->addAvailableEmotion(make_shared<Apprehension>());
        agentBob->addAvailableEmotion(make_shared<Sadness>());
        agentBob->initialize();
        worldManager->agents.push_back(agentBob);

        agentHanna->name = string("Hanna");
        agentHanna->perceiveModules.push_back(std::make_unique<DelayPerceive>());
        agentHanna->reactModules.push_back(std::make_unique<CoopSceneHannaReact>());
        agentHanna->decideModules.push_back(std::make_unique<CoopSceneHannaDecide>());
        agentHanna->performModules.push_back(std::make_unique<Perform>());
        agentHanna->addAvailableAction(make_shared<LongWalk>());
        agentHanna->addAvailableAction(make_shared<Follow>(agentBob));
        agentHanna->addAvailableEmotion(make_shared<Confidence>());
        agentHanna->addAvailableEmotion(make_shared<Fear>());
        agentHanna->addAvailableEmotion(make_shared<Happiness>());
        agentHanna->addAvailableEmotion(make_shared<Relief>());
        agentHanna->addAvailableEmotion(make_shared<Apprehension>());
        agentHanna->addAvailableEmotion(make_shared<Sadness>());
        agentHanna->initialize();
        worldManager->agents.push_back(agentHanna);

        return worldManager;
    }

    shared_ptr<WorldManager> Examples::exampleCoopNoAnticipation() {
        Time::setTimeCalculator(new ChronoTimeCalculator());

        auto worldManager = make_shared<WorldManager>();
        worldManager->description = "This scenario contains 2 agents, Bob and Hanna.\n The agents are near a rope bridge.";

        auto agentBob = make_shared<Agent>();
        auto agentHanna = make_shared<Agent>();
        agentBob->name = string("Bob");
        agentBob->perceiveModules.push_back(std::make_unique<DelayPerceive>());
        agentBob->reactModules.push_back(std::make_unique<NoAnticipation::CoopSceneBobReact>());
        agentBob->decideModules.push_back(std::make_unique<CoopSceneBobDecide>());
        agentBob->performModules.push_back(std::make_unique<Perform>());
        agentBob->addAvailableAction(make_shared<NoAnticipation::LongWalk>());
        agentBob->addAvailableAction(make_shared<NoAnticipation::Follow>(agentHanna));
        agentBob->addAvailableEmotion(make_shared<Confidence>());
        agentBob->addAvailableEmotion(make_shared<Fear>());
        agentBob->addAvailableEmotion(make_shared<Happiness>());
        agentBob->addAvailableEmotion(make_shared<Relief>());
        agentBob->addAvailableEmotion(make_shared<Apprehension>());
        agentBob->addAvailableEmotion(make_shared<Sadness>());
        agentBob->initialize();
        worldManager->agents.push_back(agentBob);

        agentHanna->name = string("Hanna");
        agentHanna->perceiveModules.push_back(std::make_unique<DelayPerceive>());
        agentHanna->reactModules.push_back(std::make_unique<NoAnticipation::CoopSceneHannaReact>());
        agentHanna->decideModules.push_back(std::make_unique<CoopSceneHannaDecide>());
        agentHanna->performModules.push_back(std::make_unique<Perform>());
        agentHanna->addAvailableAction(make_shared<NoAnticipation::LongWalk>());
        agentHanna->addAvailableAction(make_shared<NoAnticipation::Follow>(agentBob));
        agentHanna->addAvailableEmotion(make_shared<Confidence>());
        agentHanna->addAvailableEmotion(make_shared<Fear>());
        agentHanna->addAvailableEmotion(make_shared<Happiness>());
        agentHanna->addAvailableEmotion(make_shared<Relief>());
        agentHanna->addAvailableEmotion(make_shared<Apprehension>());
        agentHanna->addAvailableEmotion(make_shared<Sadness>());
        agentHanna->initialize();
        worldManager->agents.push_back(agentHanna);

        return worldManager;
    }

    shared_ptr<WorldManager> Examples::exampleCoopScreening() {
        Time::setTimeCalculator(new ChronoTimeCalculator());

        auto worldManager = make_shared<WorldManager>();
        worldManager->description = "This scenario contains 2 agents, Bob and Hanna.\n The agents are near a rope bridge.";

        auto agentBob = make_shared<Agent>();
        auto agentHanna = make_shared<Agent>();
        agentBob->name = string("Bob");
        agentBob->perceiveModules.push_back(std::make_unique<DelayPerceive>());
        agentBob->reactModules.push_back(std::make_unique<Screening::CoopSceneBobReact>());
        agentBob->decideModules.push_back(std::make_unique<CoopSceneBobDecide>());
        agentBob->performModules.push_back(std::make_unique<Perform>());
        agentBob->addAvailableAction(make_shared<Screening::LongWalk>());
        agentBob->addAvailableAction(make_shared<Screening::Follow>(agentHanna));
        agentBob->addAvailableEmotion(make_shared<Confidence>());
        agentBob->addAvailableEmotion(make_shared<Fear>());
        agentBob->addAvailableEmotion(make_shared<Happiness>());
        agentBob->addAvailableEmotion(make_shared<Relief>());
        agentBob->addAvailableEmotion(make_shared<Apprehension>());
        agentBob->addAvailableEmotion(make_shared<Sadness>());
        agentBob->initialize();
        worldManager->agents.push_back(agentBob);

        agentHanna->name = string("Hanna");
        agentHanna->perceiveModules.push_back(std::make_unique<DelayPerceive>());
        agentHanna->reactModules.push_back(std::make_unique<Screening::CoopSceneHannaReact>());
        agentHanna->decideModules.push_back(std::make_unique<CoopSceneHannaDecide>());
        agentHanna->performModules.push_back(std::make_unique<Perform>());
        agentHanna->addAvailableAction(make_shared<Screening::LongWalk>());
        agentHanna->addAvailableAction(make_shared<Screening::Follow>(agentBob));
        agentHanna->addAvailableEmotion(make_shared<Confidence>());
        agentHanna->addAvailableEmotion(make_shared<Fear>());
        agentHanna->addAvailableEmotion(make_shared<Happiness>());
        agentHanna->addAvailableEmotion(make_shared<Relief>());
        agentHanna->addAvailableEmotion(make_shared<Apprehension>());
        agentHanna->addAvailableEmotion(make_shared<Sadness>());
        agentHanna->initialize();
        worldManager->agents.push_back(agentHanna);

        return worldManager;
    }

} /* namespace Divisaction */
