/*
 * File Agent.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */

#ifndef AGENT_H_
#define AGENT_H_

#include "IAgent.h"

#include <vector>
#include <algorithm>    // std::find_if

#include "Action.h"
#include "Event.h"
#include "Emotion.h"
#include "Events/ActionEvent.h"
#include "TheoryOfMind.h"
#include "DModule.h"

namespace Divisaction {

    class Agent : public IAgent {
        public:
            std::shared_ptr<TheoryOfMind> mentalState;

            std::vector<std::unique_ptr<PerceiveModule>> perceiveModules;
            std::vector<std::unique_ptr<InterpretModule>> interpretModules;
            std::vector<std::unique_ptr<PerformModule>> performModules;

            Agent();

            virtual void initialize();

            virtual void addAvailableAction(std::shared_ptr<Action> action);

            virtual void removeAvailableAction(std::shared_ptr<Action>& action);

            virtual void addAvailableEmotion(std::shared_ptr<Emotion> emotion);

            virtual void removeAvailableEmotion(std::shared_ptr<Emotion>& emotion);

            void perceive(const std::vector<std::shared_ptr<Event>>& events);

            void interpret();

            const std::vector<std::shared_ptr<Event>> perform();
    };

} /* namespace Divisaction */

#endif /* AGENT_H_ */
