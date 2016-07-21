/*
 * File Time.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Time.h"


namespace Divisaction {
    TimeCalculator* Time::_timeCalculator = nullptr;

    Time::Time() {
    }

    Time::~Time() {
        if (_timeCalculator) {
            delete _timeCalculator;
        }
    }

    void Time::update() {
        _timeCalculator->update();
    }

    double Time::startTime() {
        return _timeCalculator->startTime();
    }

    double Time::now() {
        return _timeCalculator->now();
    }

    double Time::delta() {
        return _timeCalculator->delta();
    }

    void Time::setTimeCalculator(TimeCalculator* timeCalculator) {
        if (_timeCalculator) {
            delete _timeCalculator;
        }
        _timeCalculator = timeCalculator;
    }

    void Time::play() {
        _timeCalculator->play();
    }

    void Time::pause() {
        _timeCalculator->pause();
    }

} /* namespace Divisaction */
