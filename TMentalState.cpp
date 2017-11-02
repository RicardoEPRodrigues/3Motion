/*
 * File MentalRepresentation.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */

#include "TMentalState.h"
#include "TIAgent.h"
#include "TAction.h"
#include "TEmotion.h"

namespace ThreeMotion {

    bool TMentalState::agentHasName(std::string name) const {
        if (std::shared_ptr<TIAgent> iAgent = this->agent.lock()) {
            return iAgent->name == name;
        }
        return false;
    }

    bool TMentalState::actionHasName(std::string name) const {
        return action && action->getName() == name;
    }

    bool TMentalState::IsActionInStage(TStageType stageType) const {
        return action && action->GetCurrentStageType() == stageType;
    }

    bool TMentalState::emotionHasName(std::string name) const {
        return emotion && emotion->getName() == name;
    }
}