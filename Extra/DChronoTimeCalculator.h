/*
 * File ChronoTimeCalculator.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_CHRONOTIMECALCULATOR_H
#define DIVISACTION_CHRONOTIMECALCULATOR_H

#include <chrono>

#include "../TTimeCalculator.h"

namespace ThreeMotion {
    class DChronoTimeCalculator : public TTimeCalculator {
        private:
            bool started;
            milliseconds _startTime;
            milliseconds _now;
            milliseconds realtimeNow;
            milliseconds _delta;
        public:

            DChronoTimeCalculator();

            void Update() override;

            milliseconds Now() override;

            milliseconds Delta() override;

            milliseconds StartTime() override;

    };
}

#endif //DIVISACTION_CHRONOTIMECALCULATOR_H
