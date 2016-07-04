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

            std::string replyText;

            bool throwEvents;
        public:
            Emotion();

            virtual ExecutionState execute();

            void reset();

            virtual bool isRunning() const;

            std::shared_ptr<Stage> getStage() const;

            void setStage(std::shared_ptr<Stage> emotion);

            const std::string& getReplyText() const {
                return replyText;
            }

            void setReplyText(const std::string& replyText) {
                Emotion::replyText = replyText;
            }

            bool isThrowEvents() const {
                return throwEvents;
            }

            void setThrowEvents(bool throwEvents) {
                Emotion::throwEvents = throwEvents;
            }
    };

} /* namespace Divisaction */

#endif /* EMOTION_H_ */
