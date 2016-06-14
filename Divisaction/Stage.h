/*
 * File Stage.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */
#ifndef STAGE_H_
#define STAGE_H_

#include <string>

namespace Divisaction {

    class Stage {
        private:
            std::string name;
            bool complete;
            bool playing;
            double timeToPerceive;
        protected:
            virtual void onStart() = 0;

            virtual void onUpdate() = 0;

        public:

            Stage();

            Stage(std::string name);

            virtual ~Stage();

            void start();

            /**
             * Updates the current action
             * @return Progress value between 0 and 1. If the action hasn't been started it'll return 0. If the action is complete it'll always return 1.
             */
            void update();

            void endStage();

            bool isPlaying() const;

            bool isComplete() const;

            const std::string& getName() const;

            void setName(const std::string& name);

            double getTimeToPerceive() const;

            void setTimeToPerceive(double timeToPerceive);

            inline bool operator==(const Stage& other);

            inline bool operator!=(const Stage& other);

            inline bool operator<(const Stage& other);

            inline bool operator>(const Stage& other);
    };

} /* namespace Divisaction */

#endif /* STAGE_H_ */
