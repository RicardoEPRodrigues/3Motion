/*
 * File SelfMentalRepresentation.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_SELFMENTALSTATE_H
#define DIVISACTION_SELFMENTALSTATE_H

#include <vector>
#include <algorithm>    // std::find_if
#include "../TAction.h"

#include "../Extra/StdExtras.h"
#include "../TMentalState.h"
#include "../TIAgent.h"
#include "TEmotionEvent.h"

namespace ThreeMotion {

    class TSelfMentalState : public TMentalState {
        private:
            /**
             * Contains the available actions an agent can perform
             */
            std::vector<std::shared_ptr<TAction>> availableActions;

            /**
             * Contains the available emotions an agent can express
             */
            std::vector<std::shared_ptr<TEmotion>> availableEmotions;

        public:
            typedef std::vector<std::shared_ptr<TEmotionEvent>> AgentsReplies;
            /**
             * Contains the other agents' replies to this agent's actions
             * @note The collection should be emptied after the first usage
             */
            AgentsReplies replies;

            bool updateReplies;

            virtual void addAction(std::shared_ptr<TAction> const & action);

            virtual void removeAction(std::shared_ptr<TAction> const & action);

            std::shared_ptr<TAction> getAction(unsigned int index) const;

            std::shared_ptr<TAction> getAction(const std::string& name) const;

            std::shared_ptr<TAction> getAction(const std::shared_ptr<TAction>& action) const;

            unsigned long countActions() const;

            virtual void addEmotion(std::shared_ptr<TEmotion> const & emotion);

            virtual void removeEmotion(std::shared_ptr<TEmotion> const & emotion);

            std::shared_ptr<TEmotion> getEmotion(unsigned int index) const;

            std::shared_ptr<TEmotion> getEmotion(const std::string& name) const;

            std::shared_ptr<TEmotion> getEmotion(const std::shared_ptr<TEmotion>& emotion) const;

            unsigned long countEmotions() const;

    };

} /* namespace ThreeMotion */

#endif //DIVISACTION_SELFMENTALSTATE_H
