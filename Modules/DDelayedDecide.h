/*
 * File DelayedDecide.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_DELAYEDDECIDE_H
#define DIVISACTION_DELAYEDDECIDE_H

#include "../TModule.h"
#include "../DTime.h"

namespace ThreeMotion {

    class DDelayedDecide : public InterpretModule {
        public:
            DDelayedDecide();

            DDelayedDecide(milliseconds interval);

        protected:
            milliseconds interval;
            /**
             * This variable is used to store the action to be picked until the agent has to make the action.
             */
            std::shared_ptr<TAction> action;

            virtual void selectAction(std::shared_ptr<TTheoryOfMind> mentalState);

            virtual void _execute() override;

        private:
            bool alreadyActed;

            std::shared_ptr<DTimer> timer;
    };

} /* namespace ThreeMotion */

#endif //DIVISACTION_DELAYEDDECIDE_H
