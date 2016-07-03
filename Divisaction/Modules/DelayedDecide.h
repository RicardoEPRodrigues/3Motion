/*
 * File DelayedDecide.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_DELAYEDDECIDE_H
#define DIVISACTION_DELAYEDDECIDE_H

#include "../Module.h"
#include "../Time.h"

namespace Divisaction {

    class DelayedDecide : public DecideModule {
        private:
            bool alreadyActed;

            double startTime = 0;
            bool startCountdown;
        protected:
            double interval = 2000.0;
            /**
             * This variable is used to store the action to be picked until the agent has to make the action.
             */
            std::shared_ptr<Action> action;

            virtual void selectAction(std::shared_ptr<MentalState> mentalState);
        public:
            void execute() override;
    };

} /* namespace Divisaction */

#endif //DIVISACTION_DELAYEDDECIDE_H
