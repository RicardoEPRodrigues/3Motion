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
#include <functional>
#include <unordered_map>

#include "Executable.h"
#include "Action.h"
#include "StageType.h"
#include "Event.h"
#include "Time.h"
#include "Emotion.h"
#include "Events/ActionEvent.h"
#include "Events/ReplyEvent.h"

namespace Divisaction {

    class Agent : public IAgent {
        private:

            std::vector<std::pair<double, std::shared_ptr<Event>>> eventsBeingPerceived;
        protected:

            struct EmotionalReply {
                std::shared_ptr<IAgent> sender;
                std::shared_ptr<Emotion> emotion;
                std::shared_ptr<Event> original;

                bool hasGenerated = false;

                std::shared_ptr<Event> generateEvent();
            };

            std::vector<std::shared_ptr<Action>> possibleActions;
            std::shared_ptr<Action> selectedAction;

            std::vector<std::shared_ptr<Emotion>> availableEmotions;
            std::shared_ptr<Emotion> selectedEmotion;

            std::vector<std::shared_ptr<Event>> eventsPerceived;

            std::vector<EmotionalReply> emotionalReplies;

            std::unique_ptr<Event> performedEvent;

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
