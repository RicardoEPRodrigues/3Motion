/*
 * File MentalRepresentation.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */

#include "DMentalState.h"
#include "DIAgent.h"
#include "DAction.h"
#include "DEmotion.h"

namespace ThreeMotion {

    bool DMentalState::agentHasName(std::string name) const {
        if (std::shared_ptr<DIAgent> iAgent = this->agent.lock()) {
            return iAgent->name.compare(name) == 0;
        }
        return false;
    }

    bool DMentalState::actionHasName(std::string name) const {
        return action && action->getName().compare(name) == 0;
    }

    bool DMentalState::actionInStage(DStageType stageType) const {
        return action && action->getCurrentStageType() == stageType;
    }

    bool DMentalState::emotionHasName(std::string name) const {
        return emotion && emotion->getName().compare(name) == 0;
    }
}