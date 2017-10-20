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

namespace ThreeMotion {

    class DStage : public DExecutable {
        public:

            DStage();

            DStage(std::string name, milliseconds timeToPerceive);

            DStage(const DStage& other);

            ~DStage() override;

            virtual std::shared_ptr<DStage> clone() const = 0;

            void start();

            /**
             * Updates the current stage
             */
            ExecutionState execute() override;

            void reset() override;

            bool isRunning() const override;

            bool isComplete() const;

            milliseconds getTimeToPerceive() const;

            void setTimeToPerceive(milliseconds timeToPerceive);

        protected:
            virtual void onStart() = 0;

            virtual ExecutionState onUpdate() = 0;

        private:
            bool complete;
            bool playing;
            milliseconds timeToPerceive;
    };

} /* namespace ThreeMotion */

#endif /* STAGE_H_ */
