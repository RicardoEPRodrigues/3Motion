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

    class TTime {
        private:
            TTime();

            static std::shared_ptr<TTimeCalculator> _timeCalculator;
        public:

            static void SetTimeCalculator(
                    std::shared_ptr<TTimeCalculator> const& timeCalculator);

            static void Update();

            static milliseconds StartTime();

            static milliseconds Now();

            static milliseconds Delta();
    };

} /* namespace ThreeMotion */

#endif /* TIME_H_ */
