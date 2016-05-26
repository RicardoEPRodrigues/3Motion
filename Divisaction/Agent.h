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
#include "Time.h"
#include "Emotion.h"
#include "Events/ActionEvent.h"
#include "Events/ReplyEvent.h"
#include "MentalState.h"

namespace Divisaction {

    class Agent : public IAgent {
        private:

            std::vector<std::pair<double, std::shared_ptr<Event>>> eventsBeingPerceived;
            std::vector<std::pair<std::shared_ptr<ReplyEvent>, bool>> emotionalReplies;
            std::vector<std::shared_ptr<Event>> events;

        protected:
            MentalState mentalState;

            std::vector<std::shared_ptr<Action>> availableActions;

            std::vector<std::shared_ptr<Emotion>> availableEmotions;

        public:
            virtual void initialize() override;

            void addEmotionalReply(std::shared_ptr<ReplyEvent>& replyEvent);

            void addEvent(std::shared_ptr<Event> event);

            void addEvent(std::shared_ptr<Event>& event);

        public:
            Agent();

            const std::shared_ptr<Executable> getCurrentExecutable() const;

            virtual void addAvailableAction(std::shared_ptr<Action> action);

            virtual void removeAvailableAction(std::shared_ptr<Action>& action);

            virtual void addAvailableEmotion(std::shared_ptr<Emotion> emotion);

            virtual void removeAvailableEmotion(std::shared_ptr<Emotion>& emotion);

            void perceive(const std::vector<std::shared_ptr<Event>>& events);

            virtual void react();

            virtual void decide();

            const std::vector<std::shared_ptr<Event>> perform();
    };

} /* namespace Divisaction */

#endif /* AGENT_H_ */
