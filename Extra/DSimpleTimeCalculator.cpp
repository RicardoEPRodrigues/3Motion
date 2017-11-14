/*
 * File DSimpleTimeCalculator.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2017 - All Rights Reserved
 */
#include "DSimpleTimeCalculator.h"

namespace ThreeMotion {

    DSimpleTimeCalculator::DSimpleTimeCalculator() {}

    DSimpleTimeCalculator::~DSimpleTimeCalculator() {}

    void DSimpleTimeCalculator::Update() {
        // Purposely left empty
    }

    milliseconds DSimpleTimeCalculator::StartTime() {
        return _startTime;
    }

    milliseconds DSimpleTimeCalculator::Now() {
        return _nowTime;
    }

    milliseconds DSimpleTimeCalculator::Delta() {
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