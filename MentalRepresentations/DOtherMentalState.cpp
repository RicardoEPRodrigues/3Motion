/*
 * File OthersMentalRepresentation.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "DOtherMentalState.h"

namespace ThreeMotion {
    bool DOtherMentalState::actionInStage(DStageType stageType) const {
        return this->stage == stageType;
    }
} /* namespace ThreeMotion */