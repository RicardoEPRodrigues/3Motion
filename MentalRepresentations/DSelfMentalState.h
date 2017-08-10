/*
 * File SelfMentalRepresentation.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_SELFMENTALSTATE_H
#define DIVISACTION_SELFMENTALSTATE_H

#include <vector>
#include <algorithm>    // std::find_if
#include "../DAction.h"

#include "../Extra/StdExtras.h"
#include "../DMentalState.h"
#include "../DIAgent.h"
#include "../Events/DEmotionEvent.h"

namespace Divisaction {

    class DSelfMentalState : public DMentalState {
        public:
            typedef std::vector<std::shared_ptr<DEmotionEvent>> AgentsReplies;
            /**
             * Contains the other agents' replies to this agent's actions
             * @note The collection should be emptied after the first analysis
             */
            AgentsReplies replies;

            bool updateReplies;

            virtual void addAction(std::shared_ptr<DAction> action);

            virtual void removeAction(std::shared_ptr<DAction>& action);

            std::shared_ptr<DAction> getAction(unsigned int index) const;

            std::shared_ptr<DAction> getAction(const std::string name) const;

            std::shared_ptr<DAction> getAction(const std::shared_ptr<DAction> action) const;

            unsigned long countActions() const;

            virtual void addEmotion(std::shared_ptr<DEmotion> emotion);

            virtual void removeEmotion(std::shared_ptr<DEmotion>& emotion);

            std::shared_ptr<DEmotion> getEmotion(unsigned int index) const;

            std::shared_ptr<DEmotion> getEmotion(const std::string name) const;

            std::shared_ptr<DEmotion> getEmotion(const std::shared_ptr<DEmotion> emotion) const;

            unsigned long countEmotions() const;

        private:
            /**
             * Contains the available actions an agent can perform
             */
            std::vector<std::shared_ptr<DAction>> availableActions;

            /**
             * Contains the available emotions an agent can express
             */
            std::vector<std::shared_ptr<DEmotion>> availableEmotions;
    };

} /* namespace Divisaction */

#endif //DIVISACTION_SELFMENTALSTATE_H
