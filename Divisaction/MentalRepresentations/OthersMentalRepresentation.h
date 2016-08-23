/*
 * File OthersMentalRepresentation.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_OTHERSMENTALREPRESENTATION_H
#define DIVISACTION_OTHERSMENTALREPRESENTATION_H

#include "../MentalRepresentation.h"

namespace Divisaction {

    class OthersMentalRepresentation : public MentalRepresentation {
        public:
            StageType state;

            bool updateAction;

            bool updateEmotion;

            bool actionInStage(StageType stageType) const override;

    };

} /* namespace Divisaction */

#endif //DIVISACTION_OTHERSMENTALREPRESENTATION_H
