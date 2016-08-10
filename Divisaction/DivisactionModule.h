
/*
 * File DivisactionModule.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_DIVISACTIONMODULE_H
#define DIVISACTION_DIVISACTIONMODULE_H

#include "TimeUtils/DTimerManager.h"
#include "MentalState.h"

namespace Divisaction {

    class DivisactionModule : public DTimerManager {
        public:
            DivisactionModule();

            virtual ~DivisactionModule();

            void initialize(std::shared_ptr<MentalState> mentalState);

            /* UTILITY FUNCTIONS */
            bool selfInActionStage(std::shared_ptr<MentalState>& mentalState, StageType stageType) const;

            bool otherHasName(std::shared_ptr<IAgent>& otherAgent, std::string name) const;

            bool otherInActionStage(OthersMentalRepresentation& other, StageType stageType) const;

        protected:
            std::weak_ptr<MentalState> mentalStateWeak;
    };

} /* namespace Divisaction */

#endif //DIVISACTION_DIVISACTIONMODULE_H
