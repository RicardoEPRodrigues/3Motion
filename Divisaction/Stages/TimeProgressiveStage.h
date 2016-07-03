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

    class TimeProgressiveStage: public Stage {
    private:
        double startTime;
        double elapsedTime;
        double duration;
    public:
        TimeProgressiveStage();
        TimeProgressiveStage(std::string name, double timeToPerceive = 1000, double durationInMilliseconds = 0);
        virtual ~TimeProgressiveStage();

        void onStart() override;
        void onUpdate();

        double getProgress() const;

        virtual double getDuration() const;
        void setDuration(double durationInMilliseconds);
    };

} /* namespace Divisaction */

#endif /* STAGES_TIMEPROGRESSIVESTAGE_H_ */
