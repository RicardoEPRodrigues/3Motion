/*
 * File ChronoTimeCalculator.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_CHRONOTIMECALCULATOR_H
#define DIVISACTION_CHRONOTIMECALCULATOR_H

#include <chrono>

#include "../TimeCalculator.h"

namespace Divisaction {
    class ChronoTimeCalculator : public TimeCalculator {
        private:
            bool started;
            milliseconds _now;
            milliseconds realtimeNow;
            milliseconds _startTime;
            milliseconds _delta;
            bool _pause;
        public:

            ChronoTimeCalculator();

            virtual void update() override;

            virtual milliseconds now() override;

            virtual milliseconds delta() override;

            milliseconds startTime() override;

            void play() {
                _pause = false;
            }

            void pause() {
                _pause = true;
            }

    };
}

#endif //DIVISACTION_CHRONOTIMECALCULATOR_H
