/*
 * File Time.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Time.h"

using namespace std;
using namespace std::chrono;

namespace Divisaction {
    bool Time::started = false;
    double Time::_now = 0;
    double Time::_startTime = 0;
    double Time::_delta = 0;

    Time::Time() {
    }

    Time::~Time() {
    }

    void Time::update() {
        double now = chrono::duration_cast<chrono::milliseconds>(
                system_clock::now().time_since_epoch()).count();
        if (!started) {
            _startTime = now;
            started = true;
        }
        _delta = now - _now;
        _now = now;
    }

    double Time::startTime() {
        return _startTime;
    }

    double Time::now() {
        return _now;
    }

    double Time::delta() {
        return _delta;
    }

} /* namespace Divisaction */
