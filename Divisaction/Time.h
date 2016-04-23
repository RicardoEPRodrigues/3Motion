/*
 * File Time.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef TIME_H_
#define TIME_H_

#include "TimeCalculator.h"

namespace Divisaction {

    class Time {
        private:
            Time();

            virtual ~Time();

            static TimeCalculator* _timeCalculator;
        public:

            static void setTimeCalculator(TimeCalculator* timeCalculator);

            static void update();

            static double startTime();

            static double now();

            static double delta();
    };

} /* namespace Divisaction */

#endif /* TIME_H_ */
