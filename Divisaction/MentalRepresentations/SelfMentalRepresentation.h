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
#include "../MentalRepresentation.h"
#include "../IAgent.h"
#include "../Events/EmotionEvent.h"

namespace Divisaction {

    class SelfMentalRepresentation : public MentalRepresentation {
        public:
            typedef std::vector<std::shared_ptr<EmotionEvent>> AgentsReplies;
            /**
             * Contains the other agents' replies to this agent's actions
             * @note The collection should be emptied after the first analysis
             */
            AgentsReplies replies;

            bool updateReplies;

            virtual void addAction(std::shared_ptr<Action> action);

            virtual void removeAction(std::shared_ptr<Action>& action);

            std::shared_ptr<Action> getAction(unsigned int index) const;

            std::shared_ptr<Action> getAction(const std::shared_ptr<Action> action) const;

            unsigned long countActions() const;

            virtual void addEmotion(std::shared_ptr<Emotion> emotion);

            virtual void removeEmotion(std::shared_ptr<Emotion>& emotion);

            std::shared_ptr<Emotion> getEmotion(unsigned int index) const;

            std::shared_ptr<Emotion> getEmotion(const std::shared_ptr<Emotion> emotion) const;

            unsigned long countEmotions() const;

        private:
            /**
             * Contains the available actions an agent can perform
             */
            std::vector<std::shared_ptr<Action>> availableActions;

            /**
             * Contains the available emotions an agent can express
             */
            std::vector<std::shared_ptr<Emotion>> availableEmotions;
    };

} /* namespace Divisaction */

#endif //DIVISACTION_SELFMENTALREPRESENTATION_H
