/*
 * File Emotion.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef EMOTION_H_
#define EMOTION_H_

#include <functional>
#include <memory>

#include "DExecutable.h"

#include "DStage.h"

namespace Divisaction {

    class DEmotion : public DExecutable {
        private:
            bool running;

        protected:
            std::shared_ptr<DStage> stage;

            std::string replyText;

            std::weak_ptr<class DIAgent> replyTo;
        public:
            DEmotion();

            DEmotion(std::string name, std::shared_ptr<DStage> stage, std::string replyText);

            DEmotion(const DEmotion& other);

            ~DEmotion();

            virtual ExecutionState execute();

            void reset();

            virtual bool isRunning() const;

            std::shared_ptr<DStage> getStage() const;

            void setStage(std::shared_ptr<DStage> emotion);

            const std::weak_ptr<class DIAgent>& getReplyAgent() const;

            void replyToAgent(const std::shared_ptr<class DIAgent>& replyTo);

            const std::string& getReplyText() const {
                return replyText;
            }

            void setReplyText(const std::string& replytext) {
                DEmotion::replyText = replytext;
            }
    };

} /* namespace Divisaction */

#endif /* EMOTION_H_ */
