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
            virtual void Update() = 0;

            virtual milliseconds StartTime() = 0;

            virtual milliseconds Now() = 0;

            virtual milliseconds Delta() = 0;
    };
}


#endif //DIVISACTION_TIMECALCULATOR_H
