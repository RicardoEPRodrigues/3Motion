/*
 * File OthersMentalRepresentation.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_OTHERMENTALSTATE_H
#define DIVISACTION_OTHERMENTALSTATE_H

#include "../TMentalState.h"

namespace ThreeMotion {

    class TOtherMentalState : public TMentalState {
        public:
            TStageType stage = ANTICIPATION_INTERRUPTIBLE;

            bool updateAction{};

            bool updateEmotion{};

            TOtherMentalState() = default;

            bool IsActionInStage(TStageType stageType) const override;

    };

} /* namespace ThreeMotion */

#endif //DIVISACTION_OTHERMENTALSTATE_H
