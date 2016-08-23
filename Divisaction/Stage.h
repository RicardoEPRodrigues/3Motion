/*
 * File Stage.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */
#ifndef STAGE_H_
#define STAGE_H_

#include <string>
#include <memory>
#include "Time.h"
#include "Executable.h"

namespace Divisaction {

    class Stage : public Executable {
        public:

            Stage();

            Stage(std::string name, double timeToPerceive);

            Stage(const Stage& other);

            virtual ~Stage();

            virtual std::shared_ptr<Stage> clone() const = 0;

            void start();

            /**
             * Updates the current stage
             */
            ExecutionState execute();

            void reset();

            bool isRunning() const;

            bool isComplete() const;

            double getTimeToPerceive() const;

            void setTimeToPerceive(double timeToPerceive);

        protected:
            virtual void onStart() = 0;

            virtual ExecutionState onUpdate() = 0;

        private:
            bool complete;
            bool playing;
            milliseconds timeToPerceive;
    };

} /* namespace Divisaction */

#endif /* STAGE_H_ */
