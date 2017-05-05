/*
 * File MentalRepresentation.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */

#include "MentalState.h"
#include "IAgent.h"
#include "Action.h"
#include "Emotion.h"

namespace Divisaction {

    bool MentalState::agentHasName(std::string name) const {
        if (std::shared_ptr<IAgent> iAgent = this->agent.lock()) {
            return iAgent->name.compare(name) == 0;
        }
        return false;
    }

    bool MentalState::actionHasName(std::string name) const {
        return action && action->getName().compare(name) == 0;
    }

    bool MentalState::actionInStage(StageType stageType) const {
        return action && action->getCurrentStageType() == stageType;
    }

    bool MentalState::emotionHasName(std::string name) const {
        return emotion && emotion->getName().compare(name) == 0;
    }
}