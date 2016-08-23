/*
 * File OthersMentalRepresentation.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "OthersMentalRepresentation.h"

namespace Divisaction {
    bool OthersMentalRepresentation::actionInStage(StageType stageType) const {
        return this->state == stageType;
    }
} /* namespace Divisaction */