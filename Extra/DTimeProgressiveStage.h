/*
 * File BaseStage.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef STAGES_TIMEPROGRESSIVESTAGE_H_
#define STAGES_TIMEPROGRESSIVESTAGE_H_

#include "../DStage.h"
#include "../DTime.h"

namespace ThreeMotion {

    class DTimeProgressiveStage : public DStage {
        public:
            DTimeProgressiveStage();

            DTimeProgressiveStage(std::string name, double timeToPerceive = 1000,
                                  double durationInMilliseconds = 0);

            DTimeProgressiveStage(const DTimeProgressiveStage& other);

            virtual ~DTimeProgressiveStage();

            void onStart() override;

            ExecutionState onUpdate() override;

            double getProgress() const;

            virtual double getDuration() const;

            void setDuration(double durationInMilliseconds);

            virtual std::shared_ptr<DStage> clone() const override;

        private:
            double startTime;
            double elapsedTime;
            double duration;
    };

} /* namespace ThreeMotion */

#endif /* STAGES_TIMEPROGRESSIVESTAGE_H_ */
