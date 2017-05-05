/*
 * File MentalRepresentation.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_MENTALSTATE_H
#define DIVISACTION_MENTALSTATE_H

#include <memory>
#include "StageType.h"

namespace Divisaction {

    class MentalState {
        public:
            std::weak_ptr<class IAgent> agent;

            std::shared_ptr<class Action> action;

            std::shared_ptr<class Emotion> emotion;

            bool agentHasName(std::string name) const;

            bool actionHasName(std::string name) const;

            virtual bool actionInStage(StageType stageType) const;

            bool emotionHasName(std::string name) const;
    };

} /* namespace Divisaction */

#endif //DIVISACTION_MENTALSTATE_H
