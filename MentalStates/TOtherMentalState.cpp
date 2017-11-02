/*
 * File OthersMentalRepresentation.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "TOtherMentalState.h"

namespace ThreeMotion {
    bool TOtherMentalState::IsActionInStage(TStageType stageType) const {
        return this->stage == stageType;
    }
} /* namespace ThreeMotion */