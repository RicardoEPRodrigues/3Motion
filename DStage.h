/*
 * File Stage.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */
#ifndef STAGE_H_
#define STAGE_H_

#include <string>
#include <memory>
#include "DTime.h"
#include "DExecutable.h"

namespace Divisaction {

    class DStage : public DExecutable {
        public:

            DStage();

            DStage(std::string name, double timeToPerceive);

            DStage(const DStage& other);

            virtual ~DStage();

            virtual std::shared_ptr<DStage> clone() const = 0;

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
