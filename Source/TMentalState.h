/*
 * File MentalRepresentation.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_MENTALSTATE_H
#define DIVISACTION_MENTALSTATE_H

#include <memory>
#include "TStageType.h"

namespace ThreeMotion {

    class TMentalState {
        public:
            std::weak_ptr<class TIAgent> agent;

            std::shared_ptr<class TAction> action;

            std::shared_ptr<class TEmotion> emotion;

            bool AgentHasName(std::string name) const;

            bool ActionHasName(std::string name) const;

            virtual bool IsActionInStage(TStageType stageType) const;

            bool EmotionHasName(std::string name) const;
    };

} /* namespace ThreeMotion */

#endif //DIVISACTION_MENTALSTATE_H
