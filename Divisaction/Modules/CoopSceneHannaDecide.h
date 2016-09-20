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

    class CoopSceneHannaDecide : public DecideModule {
        public:
            CoopSceneHannaDecide();

        protected:
            virtual void _execute() override;

            milliseconds interval;
        private:
            bool alreadyActed;

            std::shared_ptr<DTimer> timer;
    };

} /* namespace Divisaction */

#endif //DIVISACTION_COOPSCENEHANNADECIDE_H
