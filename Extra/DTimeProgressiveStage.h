/*
 * File BaseStage.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef STAGES_TIMEPROGRESSIVESTAGE_H_
#define STAGES_TIMEPROGRESSIVESTAGE_H_

#include "../TStage.h"
#include "../DTime.h"

namespace ThreeMotion {

    class DTimeProgressiveStage : public TStage {
        public:
            DTimeProgressiveStage();

            DTimeProgressiveStage(std::string name, milliseconds timeToPerceive = 1000,
                                  milliseconds durationInMilliseconds = 0);

            DTimeProgressiveStage(const DTimeProgressiveStage& other);

            virtual ~DTimeProgressiveStage();

            void OnStart() override;

            ExecutionState onUpdate() override;

            float getProgress() const;

            virtual milliseconds getDuration() const;

            void setDuration(milliseconds durationInMilliseconds);

            virtual std::shared_ptr<TStage> clone() const override;

        private:
            milliseconds startTime;
            milliseconds elapsedTime;
            milliseconds duration;
    };

} /* namespace ThreeMotion */

#endif /* STAGES_TIMEPROGRESSIVESTAGE_H_ */
