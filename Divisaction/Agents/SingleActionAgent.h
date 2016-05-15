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
            virtual void actionStarted();

            virtual void actionChanged(StageType stage);

            virtual void actionFinished();

        public:
            SingleActionAgent();

            void decide() override;

            virtual void react() override;

            virtual void addPossibleAction(std::shared_ptr<Action>& action) override;
    };

} /* namespace Divisaction */

#endif /* EXAMPLES_SINGLEACTIONAGENT_H_ */
