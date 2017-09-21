/*
 * File DSimpleTimeCalculator.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2017 - All Rights Reserved
 */
#ifndef DIVISACTION_DSIMPLETIMECALCULATOR_H
#define DIVISACTION_DSIMPLETIMECALCULATOR_H

#include "../DTimeCalculator.h"

namespace ThreeMotion {

    class DSimpleTimeCalculator : public DTimeCalculator {
        private:
            milliseconds _deltaTime;
            milliseconds _nowTime;
            milliseconds _startTime;
        public:
            DSimpleTimeCalculator();

            virtual ~DSimpleTimeCalculator();

            void update() override;

            milliseconds startTime() override;

            milliseconds now() override;

            milliseconds delta() override;

            void setDeltaTime(milliseconds deltaTime);

            void setNow(milliseconds nowTime);

            void setStartTime(milliseconds startTime);
    };

} /* namespace ThreeMotion */

#endif //DIVISACTION_DSIMPLETIMECALCULATOR_H
