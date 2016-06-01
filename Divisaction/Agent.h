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
#include "Events/ReplyEvent.h"
#include "MentalState.h"
#include "Module.h"

namespace Divisaction {

    class Agent : public IAgent {
        protected:
            std::shared_ptr<MentalState> mentalState;

            std::vector<std::unique_ptr<PerceiveModule>> perceiveModules;
            std::vector<std::unique_ptr<ReactModule>> reactModules;
            std::vector<std::unique_ptr<DecideModule>> decideModules;
            std::vector<std::unique_ptr<PerformModule>> performModules;
        public:
            Agent();

            virtual void initialize() override;

            const std::shared_ptr<Executable> getCurrentExecutable() const;

            virtual void addAvailableAction(std::shared_ptr<Action> action);

            virtual void removeAvailableAction(std::shared_ptr<Action>& action);

            virtual void addAvailableEmotion(std::shared_ptr<Emotion> emotion);

            virtual void removeAvailableEmotion(std::shared_ptr<Emotion>& emotion);

            void perceive(const std::vector<std::shared_ptr<Event>>& events);

            void react();

            void decide();

            const std::vector<std::shared_ptr<Event>> perform();
    };

} /* namespace Divisaction */

#endif /* AGENT_H_ */
