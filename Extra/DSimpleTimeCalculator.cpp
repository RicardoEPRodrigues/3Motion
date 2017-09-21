/*
 * File DSimpleTimeCalculator.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2017 - All Rights Reserved
 */
#include "DSimpleTimeCalculator.h"

namespace ThreeMotion {

    DSimpleTimeCalculator::DSimpleTimeCalculator() {}

    DSimpleTimeCalculator::~DSimpleTimeCalculator() {}

    void DSimpleTimeCalculator::update() {
        // Purposely left empty
    }

    milliseconds DSimpleTimeCalculator::startTime() {
        return _startTime;
    }

    milliseconds DSimpleTimeCalculator::now() {
        return _nowTime;
    }

    milliseconds DSimpleTimeCalculator::delta() {
        return _deltaTime;
    }

    void DSimpleTimeCalculator::setDeltaTime(milliseconds deltaTime) {
        DSimpleTimeCalculator::_deltaTime = deltaTime;
    }

    void DSimpleTimeCalculator::setNow(milliseconds nowTime) {
        DSimpleTimeCalculator::_nowTime = nowTime;
    }

    void DSimpleTimeCalculator::setStartTime(milliseconds startTime) {
        DSimpleTimeCalculator::_startTime = startTime;
    }

} /* namespace ThreeMotion */