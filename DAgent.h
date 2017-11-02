/*
 * File Agent.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */

#ifndef AGENT_H_
#define AGENT_H_

#include "TIAgent.h"

#include <vector>
#include <algorithm>    // std::find_if

#include "TAction.h"
#include "TEvent.h"
#include "TEmotion.h"
#include "TActionEvent.h"
#include "TTheoryOfMind.h"
#include "TModule.h"

namespace ThreeMotion {

    class DAgent : public TIAgent {
        public:
            std::shared_ptr<TTheoryOfMind> theoryOfMind;

            std::vector<std::unique_ptr<PerceiveModule>> perceiveModules;
            std::vector<std::unique_ptr<InterpretModule>> interpretModules;
            std::vector<std::unique_ptr<PerformModule>> performModules;

            DAgent();

            virtual void initialize();

            virtual void addAvailableAction(std::shared_ptr<TAction> action);

            virtual void removeAvailableAction(std::shared_ptr<TAction>& action);

            virtual void addAvailableEmotion(std::shared_ptr<TEmotion> emotion);

            virtual void removeAvailableEmotion(std::shared_ptr<TEmotion>& emotion);

            void perceive(const std::vector<std::shared_ptr<TEvent>>& events);

            void interpret();

            const std::vector<std::shared_ptr<TEvent>> perform();
    };

} /* namespace ThreeMotion */

#endif /* AGENT_H_ */
