/*
 * File OthersMentalRepresentation.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "OtherMentalState.h"

namespace Divisaction {
    bool OtherMentalState::actionInStage(StageType stageType) const {
        return this->state == stageType;
    }
} /* namespace Divisaction */