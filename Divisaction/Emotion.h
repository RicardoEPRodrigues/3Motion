/*
 * File Emotion.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef EMOTION_H_
#define EMOTION_H_

#include <functional>

#include "Executable.h"

#include "Stage.h"

namespace Divisaction {

    class Emotion : public Executable {
        private:
            bool running;

        protected:
            Stage *emotion;
        public:
            std::function<void(Emotion *)> started;
            std::function<void(Emotion *)> finished;

            Emotion();

            virtual ~Emotion();

            virtual bool execute();

            void reset();

            virtual bool isRunning() const;

            Stage *getEmotion() const;

            void setEmotion(Stage *emotion);
    };

} /* namespace Divisaction */

#endif /* EMOTION_H_ */
