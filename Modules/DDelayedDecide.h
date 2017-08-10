/*
 * File DelayedDecide.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_DELAYEDDECIDE_H
#define DIVISACTION_DELAYEDDECIDE_H

#include "../DModule.h"
#include "../DTime.h"

namespace Divisaction {

    class DDelayedDecide : public InterpretModule {
        public:
            DDelayedDecide();

            DDelayedDecide(milliseconds interval);

        protected:
            milliseconds interval;
            /**
             * This variable is used to store the action to be picked until the agent has to make the action.
             */
            std::shared_ptr<DAction> action;

            virtual void selectAction(std::shared_ptr<DTheoryOfMind> mentalState);

            virtual void _execute() override;

        private:
            bool alreadyActed;

            std::shared_ptr<DTimer> timer;
    };

} /* namespace Divisaction */

#endif //DIVISACTION_DELAYEDDECIDE_H
