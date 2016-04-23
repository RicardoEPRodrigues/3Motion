/*
 * File SingleActionAgent.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef EXAMPLES_SINGLEACTIONAGENT_H_
#define EXAMPLES_SINGLEACTIONAGENT_H_

#include "../Agent.h"

namespace Divisaction {

    class SingleActionAgent : public Agent {
        private:
            bool alreadyActed;

        protected:

            virtual void actionStarted(Action *action);

            virtual void actionChanged(Action *action, StageType stage);

            virtual void actionFinished(Action *action);

        public:
            SingleActionAgent();

            virtual ~SingleActionAgent();

            void decide() override;

            virtual void addPossibleAction(Action *action) override;
    };

} /* namespace Divisaction */

#endif /* EXAMPLES_SINGLEACTIONAGENT_H_ */
