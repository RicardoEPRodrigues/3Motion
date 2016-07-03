/*
 * File CoopSceneHannaDecide.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_COOPSCENEHANNADECIDE_H
#define DIVISACTION_COOPSCENEHANNADECIDE_H

#include "DelayedDecide.h"
#include "../Time.h"

namespace Divisaction {

    class CoopSceneHannaDecide : public DelayedDecide {
        protected:
            virtual void selectAction(std::shared_ptr<MentalState> mentalState);
    };

} /* namespace Divisaction */

#endif //DIVISACTION_COOPSCENEHANNADECIDE_H
