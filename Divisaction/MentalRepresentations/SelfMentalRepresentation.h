/*
 * File SelfMentalRepresentation.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_SELFMENTALREPRESENTATION_H
#define DIVISACTION_SELFMENTALREPRESENTATION_H

#include <vector>
#include <algorithm>    // std::find_if

#include "../Action.h"
#include "../Extra/StdExtras.h"
#include "../Events/ReplyEvent.h"
#include "../MentalRepresentation.h"
#include "../IAgent.h"

namespace Divisaction {

    class SelfMentalRepresentation : public MentalRepresentation {
        public:
            /**
             * Contains the available actions an agent can perform
             */
            std::vector<std::shared_ptr<Action>> availableActions;

            /**
             * Contains the available emotions an agent can express
             */
            std::vector<std::shared_ptr<Emotion>> availableEmotions;

            /**
             * Contains the events the agent will send to the world manager about it's actions
             */
            std::vector<std::shared_ptr<Event>> eventsToSend;

            /**
             * Contains the emotional replies to other's actions.
             * @note The collection should be emptied after the emotions in the reply are executed.
             */
            std::vector<std::shared_ptr<ReplyEvent>> emotionalReplies;

            typedef std::vector<std::shared_ptr<ReplyEvent>> AgentsReplies;

            /**
             * Contains the other agents' replies to this agent's actions
             * @note The collection should be emptied after the first analysis
             */
            AgentsReplies replies;

            bool updateReplies;

            void addEmotionalReply(std::shared_ptr<ReplyEvent>& replyEvent);

            void addEvent(std::shared_ptr<Event> event);

            virtual void addAvailableAction(std::shared_ptr<Action> action);

            virtual void removeAvailableAction(std::shared_ptr<Action>& action);

            std::shared_ptr<Action> getAction(const std::shared_ptr<Action> action) const;

            virtual void addAvailableEmotion(std::shared_ptr<Emotion> emotion);

            virtual void removeAvailableEmotion(std::shared_ptr<Emotion>& emotion);

            std::shared_ptr<Emotion> getEmotion(const std::shared_ptr<Emotion> emotion) const;
    };

} /* namespace Divisaction */

#endif //DIVISACTION_SELFMENTALREPRESENTATION_H
