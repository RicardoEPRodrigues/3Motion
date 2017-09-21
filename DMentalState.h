/*
 * File MentalRepresentation.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_MENTALSTATE_H
#define DIVISACTION_MENTALSTATE_H

#include <memory>
#include "DStageType.h"

namespace ThreeMotion {

    class DMentalState {
        public:
            std::weak_ptr<class DIAgent> agent;

            std::shared_ptr<class DAction> action;

            std::shared_ptr<class DEmotion> emotion;

            bool agentHasName(std::string name) const;

            bool actionHasName(std::string name) const;

            virtual bool actionInStage(DStageType stageType) const;

            bool emotionHasName(std::string name) const;
    };

} /* namespace ThreeMotion */

#endif //DIVISACTION_MENTALSTATE_H
