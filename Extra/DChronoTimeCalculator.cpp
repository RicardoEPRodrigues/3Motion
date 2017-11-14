/*
 * File ChronoTimeCalculator.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "DChronoTimeCalculator.h"

using namespace std;
using namespace std::chrono;

namespace ThreeMotion {
    DChronoTimeCalculator::DChronoTimeCalculator() : started(false), _startTime(0),
                                                     _now(0), realtimeNow(0), _delta(0) {}


    milliseconds DChronoTimeCalculator::StartTime() {
        return _startTime;
    }

    milliseconds DChronoTimeCalculator::Now() {
        return _now;
    }


    milliseconds DChronoTimeCalculator::Delta() {
        return _delta;
    }

    void DChronoTimeCalculator::Update() {
        milliseconds now = chrono::duration_cast<chrono::milliseconds>(
                system_clock::now().time_since_epoch()).count();
        if (!started) {
            _startTime = _now = realtimeNow = now;
            started = true;
        }
        _delta = now - realtimeNow;
        realtimeNow = now;
        _now += _delta;
    }
}


