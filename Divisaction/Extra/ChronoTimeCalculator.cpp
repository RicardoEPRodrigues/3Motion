/*
 * File ChronoTimeCalculator.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "ChronoTimeCalculator.h"

using namespace std;
using namespace std::chrono;

ChronoTimeCalculator::ChronoTimeCalculator() {
    started = false;
    _startTime = 0;
    _now = 0;
    _delta = 0;
}


double ChronoTimeCalculator::startTime() {
    return _startTime;
}

double ChronoTimeCalculator::now() {
    return _now;
}


double ChronoTimeCalculator::delta() {
    return _delta;
}

void ChronoTimeCalculator::update() {
    double now = chrono::duration_cast<chrono::milliseconds>(
            system_clock::now().time_since_epoch()).count();
    if (!started) {
        _startTime = now;
        started = true;
    }
    _delta = now - _now;
    _now = now;
}



