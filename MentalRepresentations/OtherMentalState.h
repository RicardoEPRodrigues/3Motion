/*
 * File OthersMentalRepresentation.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_OTHERMENTALSTATE_H
#define DIVISACTION_OTHERMENTALSTATE_H

#include "../MentalState.h"

namespace Divisaction {

    class OtherMentalState : public MentalState {
        public:
            StageType state;

            bool updateAction;

            bool updateEmotion;

            bool actionInStage(StageType stageType) const override;

    };

} /* namespace Divisaction */

#endif //DIVISACTION_OTHERMENTALSTATE_H
