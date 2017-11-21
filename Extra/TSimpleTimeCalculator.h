/*
 * File DSimpleTimeCalculator.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2017 - All Rights Reserved
 */
#ifndef DIVISACTION_DSIMPLETIMECALCULATOR_H
#define DIVISACTION_DSIMPLETIMECALCULATOR_H

#include "../TITimeCalculator.h"

namespace ThreeMotion {

    class TSimpleTimeCalculator : public TITimeCalculator {
        private:
            milliseconds _deltaTime;
            milliseconds _nowTime;
            milliseconds _startTime;
        public:
            TSimpleTimeCalculator();

            virtual ~TSimpleTimeCalculator();

            void Update() override;

            milliseconds StartTime() override;

            milliseconds Now() override;

            milliseconds Delta() override;

            void setDeltaTime(milliseconds deltaTime);

            void setNow(milliseconds nowTime);

            void setStartTime(milliseconds startTime);
    };

} /* namespace ThreeMotion */

#endif //DIVISACTION_DSIMPLETIMECALCULATOR_H
