/*
 * File TimeCalculator.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_TIMECALCULATOR_H
#define DIVISACTION_TIMECALCULATOR_H

#include "TDefine.h"

namespace ThreeMotion {

    class TTimeCalculator {
        public:
            TTimeCalculator() = default;

            virtual ~TTimeCalculator() = default;

            virtual void update() = 0;

            virtual milliseconds startTime() = 0;

            virtual milliseconds now() = 0;

            virtual milliseconds delta() = 0;
    };
}


#endif //DIVISACTION_TIMECALCULATOR_H
