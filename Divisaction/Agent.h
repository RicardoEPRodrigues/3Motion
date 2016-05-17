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

        protected:

//            struct EmotionalReply {
//                std::shared_ptr<IAgent> sender;
//                std::shared_ptr<Emotion> emotion;
//                std::shared_ptr<Event> original;
//
//                bool hasGenerated = false;
//
//                std::shared_ptr<Event> generateEvent();
//            };

            std::vector<std::shared_ptr<Action>> possibleActions;

            std::vector<std::shared_ptr<Emotion>> availableEmotions;

            std::unique_ptr<Event> performedEvent;

            MentalState mentalState;

            void addEmotionalReply(std::shared_ptr<ReplyEvent>& replyEvent);

        public:
            Agent();

            const std::shared_ptr<Executable> getCurrentExecutable() const;

            virtual void addPossibleAction(std::shared_ptr<Action>& action);

            virtual void removePossibleAction(std::shared_ptr<Action>& action);

            virtual void addAvailableEmotion(std::shared_ptr<Emotion>& emotion);

            virtual void removeAvailableEmotion(std::shared_ptr<Emotion>& emotion);

            void perceive(const std::vector<std::shared_ptr<Event>>& events);

            virtual void react();

            virtual void decide();

            const std::vector<std::shared_ptr<Event>> perform();
    };

} /* namespace Divisaction */

#endif /* AGENT_H_ */
