/*
 * File CoopSceneHannaDecide.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_COOPSCENEHANNADECIDE_H
#define DIVISACTION_COOPSCENEHANNADECIDE_H

#include "../Module.h"
#include "../Time.h"

namespace Divisaction {

    class CoopSceneHannaDecide : public DecideModule {
        private:
            bool alreadyActed;

            double interval = 2000.0;
            std::shared_ptr<Action> action;
            double startTime = 0;
            bool startCountdown;
        public:
            virtual void execute() override;
    };

} /* namespace Divisaction */

#endif //DIVISACTION_COOPSCENEHANNADECIDE_H
