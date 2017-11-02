/*
 * File Time.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef TIME_H_
#define TIME_H_

#include <memory>
#include "TTimeCalculator.h"

namespace ThreeMotion {

    class DTime {
        private:
            DTime();

            virtual ~DTime();

            static std::shared_ptr<TTimeCalculator> _timeCalculator;
        public:

            static void setTimeCalculator(std::shared_ptr<TTimeCalculator>& timeCalculator);

            static void setTimeCalculator(std::shared_ptr<TTimeCalculator> timeCalculator);

            static void update();

            static milliseconds startTime();

            static milliseconds now();

            static milliseconds delta();
    };

} /* namespace ThreeMotion */

#endif /* TIME_H_ */
