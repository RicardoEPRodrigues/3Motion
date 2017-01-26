/*
 * File MentalRepresentation.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */

#include "MentalRepresentation.h"
#include "IAgent.h"
#include "Action.h"
#include "Emotion.h"

namespace Divisaction {

    bool MentalRepresentation::agentHasName(std::string name) const {
        if (std::shared_ptr<IAgent> iAgent = this->agent.lock()) {
            return iAgent->name.compare(name) == 0;
        }
        return false;
    }

    bool MentalRepresentation::actionHasName(std::string name) const {
        return action && action->getName().compare(name) == 0;
    }

    bool MentalRepresentation::actionInStage(StageType stageType) const {
        return action && action->getCurrentStageType() == stageType;
    }

    bool MentalRepresentation::emotionHasName(std::string name) const {
        return emotion && emotion->getName().compare(name) == 0;
    }
}