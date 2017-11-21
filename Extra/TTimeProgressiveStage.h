/*
 * File BaseStage.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef STAGES_TIMEPROGRESSIVESTAGE_H_
#define STAGES_TIMEPROGRESSIVESTAGE_H_

#include "../TStage.h"
#include "../TTime.h"

namespace ThreeMotion {

    class TTimeProgressiveStage : public TStage {
        private:
            milliseconds startTime;
            milliseconds elapsedTime;
            milliseconds duration;
        protected:

            void OnStart() override;

            ExecutionState OnUpdate() override;

        public:
            TTimeProgressiveStage();

            explicit TTimeProgressiveStage(std::string const& name,
                                           milliseconds timeToPerceive = 1000,
                                           milliseconds durationInMilliseconds = 0);

            TTimeProgressiveStage(const TTimeProgressiveStage& other);

            ~TTimeProgressiveStage() override;

            float GetProgress() const;

            virtual milliseconds GetDuration() const;

            void SetDuration(milliseconds durationInMilliseconds);

            std::shared_ptr<TStage> Clone() const override;

    };

} /* namespace ThreeMotion */

#endif /* STAGES_TIMEPROGRESSIVESTAGE_H_ */
