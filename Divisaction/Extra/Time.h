/*
 * File Time.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef TIME_H_
#define TIME_H_

#include <chrono>

namespace Divisaction {

    class Time {
    private:
        Time();
        virtual ~Time();

        static bool started;
        static double _now;
        static double _startTime;
        static double _delta;
    public:
        static void update();
        static double startTime();
        static double now();
        static double delta();
    };

} /* namespace Divisaction */

#endif /* TIME_H_ */
