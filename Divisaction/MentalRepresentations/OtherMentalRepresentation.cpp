/*
 * File OthersMentalRepresentation.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "OtherMentalRepresentation.h"

namespace Divisaction {
    bool OtherMentalRepresentation::actionInStage(StageType stageType) const {
        return this->state == stageType;
    }
} /* namespace Divisaction */