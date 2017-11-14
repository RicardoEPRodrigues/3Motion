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

            virtual void AddAction(std::shared_ptr<TAction> const& action);

            virtual void RemoveAction(std::shared_ptr<TAction> const& action);

            std::shared_ptr<TAction> GetAction(unsigned int index) const;

            std::shared_ptr<TAction> GetAction(const std::string& name) const;

            std::shared_ptr<TAction> GetAction(
                    const std::shared_ptr<TAction>& action) const;

            unsigned long CountActions() const;

            virtual void AddEmotion(std::shared_ptr<TEmotion> const& emotion);

            virtual void RemoveEmotion(std::shared_ptr<TEmotion> const& emotion);

            std::shared_ptr<TEmotion> GetEmotion(unsigned int index) const;

            std::shared_ptr<TEmotion> GetEmotion(const std::string& name) const;

            std::shared_ptr<TEmotion> GetEmotion(
                    const std::shared_ptr<TEmotion>& emotion) const;

            unsigned long CountEmotions() const;

    };

} /* namespace ThreeMotion */

#endif //DIVISACTION_SELFMENTALSTATE_H
