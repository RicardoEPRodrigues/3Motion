/*
 * File OthersMentalRepresentation.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_OTHERMENTALSTATE_H
#define DIVISACTION_OTHERMENTALSTATE_H

#include "../DMentalState.h"

namespace ThreeMotion {

    class DOtherMentalState : public DMentalState {
        public:
            DStageType stage;

            bool updateAction;

            bool updateEmotion;

            bool actionInStage(DStageType stageType) const override;

    };

} /* namespace ThreeMotion */

#endif //DIVISACTION_OTHERMENTALSTATE_H
