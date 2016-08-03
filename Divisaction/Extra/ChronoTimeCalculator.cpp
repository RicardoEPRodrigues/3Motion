/*
 * File ChronoTimeCalculator.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "ChronoTimeCalculator.h"

using namespace std;
using namespace std::chrono;

namespace Divisaction {
    ChronoTimeCalculator::ChronoTimeCalculator() {
        started = false;
        _startTime = 0;
        _now = 0;
        _delta = 0;
    }


    milliseconds ChronoTimeCalculator::startTime() {
        return _startTime;
    }

    milliseconds ChronoTimeCalculator::now() {
        return _now;
    }


    milliseconds ChronoTimeCalculator::delta() {
        return _delta;
    }

    void ChronoTimeCalculator::update() {
        milliseconds now = chrono::duration_cast<chrono::milliseconds>(
                system_clock::now().time_since_epoch()).count();
        if (!started) {
            _startTime = _now = realtimeNow = now;
            started = true;
        }
        _delta = now - realtimeNow;
        realtimeNow = now;
        if (!_pause) {
            _now += _delta;
        }
    }
}


