/*
 * File CoopSceneBob.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_COOPSCENEBOB_H
#define DIVISACTION_COOPSCENEBOB_H

#include "../Agent.h"
#include "../Modules/DelayPerceive.h"
#include "../Modules/Perform.h"
#include "../Modules/CoopSceneBobReact.h"
#include "../Modules/SingleActionDecide.h"

namespace Divisaction {

    class CoopSceneBob : public Agent {
        protected:
            virtual void actionStarted();

            virtual void actionChanged(StageType stage);

            virtual void actionFinished();

            virtual void emotionStarted();

            virtual void emotionFinished();

        public:
            CoopSceneBob();

            virtual void addAvailableAction(std::shared_ptr<Action> action) override;

            virtual void addAvailableEmotion(std::shared_ptr<Emotion> emotion) override;

    };

} /* namespace Divisaction */

#endif //DIVISACTION_COOPSCENEBOB_H
