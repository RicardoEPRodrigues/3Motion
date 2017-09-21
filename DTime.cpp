/*
 * File Time.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "DTime.h"


namespace ThreeMotion {
    std::shared_ptr<DTimeCalculator> DTime::_timeCalculator = nullptr;

    DTime::DTime() {
    }

    DTime::~DTime() {
    }

    void DTime::update() {
        if (_timeCalculator) {
            _timeCalculator->update();
        }
    }

    milliseconds DTime::startTime() {
        return _timeCalculator ? _timeCalculator->startTime() : -1;
    }

    milliseconds DTime::now() {
        return _timeCalculator ? _timeCalculator->now() : -1;
    }

    milliseconds DTime::delta() {
        return _timeCalculator ? _timeCalculator->delta() : -1;
    }

    void DTime::setTimeCalculator(std::shared_ptr<DTimeCalculator>& timeCalculator) {
        _timeCalculator = timeCalculator;
    }

    void DTime::setTimeCalculator(std::shared_ptr<DTimeCalculator> timeCalculator) {
        _timeCalculator = timeCalculator;
    }

} /* namespace ThreeMotion */
