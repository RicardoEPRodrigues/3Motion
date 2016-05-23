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
            bool alreadyFelt;

        protected:
            virtual void actionStarted();

            virtual void actionChanged(StageType stage);

            virtual void actionFinished();

            void emotionStarted();

            void emotionFinished();

        public:
            SingleActionAgent();

            void decide() override;

            virtual void react() override;

            virtual void addAvailableAction(std::shared_ptr<Action> action) override;

            virtual void addAvailableEmotion(std::shared_ptr<Emotion> emotion) override;
    };

} /* namespace Divisaction */

#endif /* EXAMPLES_SINGLEACTIONAGENT_H_ */
