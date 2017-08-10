/*
 * File Time.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef TIME_H_
#define TIME_H_

#include <memory>
#include "DTimeCalculator.h"

namespace Divisaction {

    class DTime {
        private:
            DTime();

            virtual ~DTime();

            static std::shared_ptr<DTimeCalculator> _timeCalculator;
        public:

            static void setTimeCalculator(std::shared_ptr<DTimeCalculator>& timeCalculator);

            static void setTimeCalculator(std::shared_ptr<DTimeCalculator> timeCalculator);

            static void update();

            static milliseconds startTime();

            static milliseconds now();

            static milliseconds delta();
    };

} /* namespace Divisaction */

#endif /* TIME_H_ */
