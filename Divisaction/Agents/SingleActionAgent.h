/*
 * File SingleActionAgent.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef EXAMPLES_SINGLEACTIONAGENT_H_
#define EXAMPLES_SINGLEACTIONAGENT_H_

#include "../Agent.h"
#include "../Modules/DelayPerceive.h"
#include "../Modules/SingleEmotionReact.h"
#include "../Modules/ReplyReact.h"
#include "../Modules/SingleActionDecide.h"
#include "../Modules/Perform.h"

namespace Divisaction {

    class SingleActionAgent : public Agent {
        protected:
            virtual void actionStarted();

            virtual void actionChanged(StageType stage);

            virtual void actionFinished();

            virtual void emotionStarted();

            virtual void emotionFinished();

        public:
            SingleActionAgent();

            virtual void addAvailableAction(std::shared_ptr<Action> action) override;

            virtual void addAvailableEmotion(std::shared_ptr<Emotion> emotion) override;
    };

} /* namespace Divisaction */

#endif /* EXAMPLES_SINGLEACTIONAGENT_H_ */
