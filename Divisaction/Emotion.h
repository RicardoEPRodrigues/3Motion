/*
 * File Emotion.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef EMOTION_H_
#define EMOTION_H_

#include <functional>
#include <memory>

#include "Executable.h"

#include "Stage.h"

namespace Divisaction {

    class Emotion : public Executable {
        private:
            bool running;

        protected:
            std::shared_ptr<Stage> stage;
        public:
            std::function<void()> started;
            std::function<void()> finished;

            Emotion();

            virtual bool execute();

            void reset();

            virtual bool isRunning() const;

            std::shared_ptr<Stage> getStage() const;

            void setStage(std::shared_ptr<Stage> emotion);
    };

} /* namespace Divisaction */

#endif /* EMOTION_H_ */
