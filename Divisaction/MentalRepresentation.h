/*
 * File MentalRepresentation.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_MENTALREPRESENTATION_H
#define DIVISACTION_MENTALREPRESENTATION_H

#include <memory>
#include <map>

#include "StageType.h"

namespace Divisaction {

    struct MentalRepresentation {
        std::shared_ptr<class Action> action;

        StageType state;

        std::shared_ptr<class Emotion> emotion;

        bool update;
    };

} /* namespace Divisaction */

#endif //DIVISACTION_MENTALREPRESENTATION_H
