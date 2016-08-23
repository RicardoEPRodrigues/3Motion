
/*
 * File DModule.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_DIVISACTIONMODULE_H
#define DIVISACTION_DIVISACTIONMODULE_H

#include "TimeUtils/DTimerManager.h"
#include "MentalState.h"

namespace Divisaction {

    class DModule : public DTimerManager {
        public:
            DModule();

            virtual ~DModule();

            void initialize(std::shared_ptr<MentalState> mentalState);

        protected:
            std::weak_ptr<MentalState> mentalStateWeak;
    };

} /* namespace Divisaction */

#endif //DIVISACTION_DIVISACTIONMODULE_H
