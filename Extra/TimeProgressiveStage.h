/*
 * File BaseStage.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef STAGES_TIMEPROGRESSIVESTAGE_H_
#define STAGES_TIMEPROGRESSIVESTAGE_H_

#include "../Stage.h"
#include "../Time.h"

namespace Divisaction {

    class TimeProgressiveStage : public Stage {
        public:
            TimeProgressiveStage();

            TimeProgressiveStage(std::string name, double timeToPerceive = 1000,
                                 double durationInMilliseconds = 0);

            TimeProgressiveStage(const TimeProgressiveStage& other);

            virtual ~TimeProgressiveStage();

            void onStart() override;

            ExecutionState onUpdate();

            double getProgress() const;

            virtual double getDuration() const;

            void setDuration(double durationInMilliseconds);

            virtual std::shared_ptr<Stage> clone() const override;

        private:
            double startTime;
            double elapsedTime;
            double duration;
    };

} /* namespace Divisaction */

#endif /* STAGES_TIMEPROGRESSIVESTAGE_H_ */
