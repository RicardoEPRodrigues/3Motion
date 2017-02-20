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
        if (_timeCalculator) {
            _timeCalculator->update();
        }
    }

    milliseconds Time::startTime() {
        return _timeCalculator ? _timeCalculator->startTime() : -1;
    }

    milliseconds Time::now() {
        return _timeCalculator ? _timeCalculator->now() : -1;
    }

    milliseconds Time::delta() {
        return _timeCalculator ? _timeCalculator->delta() : -1;
    }

    void Time::setTimeCalculator(TimeCalculator* timeCalculator) {
        if (_timeCalculator) {
            delete _timeCalculator;
        }
        _timeCalculator = timeCalculator;
    }

    void Time::play() {
        if (_timeCalculator) {
            _timeCalculator->play();
        }
    }

    void Time::pause() {
        if (_timeCalculator) {
            _timeCalculator->pause();
        }
    }

} /* namespace Divisaction */
