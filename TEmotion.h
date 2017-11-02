/*
 * File Emotion.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef EMOTION_H_
#define EMOTION_H_

#include <functional>
#include <memory>

#include "TExecutable.h"

#include "TStage.h"

namespace ThreeMotion {

    class TEmotion : public TExecutable {
        private:
            bool running;

        public:

            std::shared_ptr<TStage> stage;

            std::string replyText;

            std::weak_ptr<class TIAgent> replyToAgent;

            TEmotion();

            TEmotion(std::string name, std::shared_ptr<TStage> stage, std::string replyText);

            TEmotion(const TEmotion& other);

            ~TEmotion() override;

            ExecutionState Execute() override;

            void Reset() override;

            bool IsRunning() const override;
    };

} /* namespace ThreeMotion */

#endif /* EMOTION_H_ */
