/*
 * File Agent.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */

#ifndef AGENT_H_
#define AGENT_H_

#include "DIAgent.h"

#include <vector>
#include <algorithm>    // std::find_if

#include "DAction.h"
#include "DEvent.h"
#include "DEmotion.h"
#include "Events/DActionEvent.h"
#include "DTheoryOfMind.h"
#include "DModule.h"

namespace ThreeMotion {

    class DAgent : public DIAgent {
        public:
            std::shared_ptr<DTheoryOfMind> mentalState;

            std::vector<std::unique_ptr<PerceiveModule>> perceiveModules;
            std::vector<std::unique_ptr<InterpretModule>> interpretModules;
            std::vector<std::unique_ptr<PerformModule>> performModules;

            DAgent();

            virtual void initialize();

            virtual void addAvailableAction(std::shared_ptr<DAction> action);

            virtual void removeAvailableAction(std::shared_ptr<DAction>& action);

            virtual void addAvailableEmotion(std::shared_ptr<DEmotion> emotion);

            virtual void removeAvailableEmotion(std::shared_ptr<DEmotion>& emotion);

            void perceive(const std::vector<std::shared_ptr<DEvent>>& events);

            void interpret();

            const std::vector<std::shared_ptr<DEvent>> perform();
    };

} /* namespace ThreeMotion */

#endif /* AGENT_H_ */
