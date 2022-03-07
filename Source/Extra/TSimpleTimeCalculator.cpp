/*
 * File DSimpleTimeCalculator.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2017 - All Rights Reserved
 */
#include "TSimpleTimeCalculator.h"

namespace ThreeMotion {

    TSimpleTimeCalculator::TSimpleTimeCalculator() = default;

    TSimpleTimeCalculator::~TSimpleTimeCalculator() = default;

    void TSimpleTimeCalculator::Update() {
        // Purposely left empty
    }

    milliseconds TSimpleTimeCalculator::StartTime() {
        return _startTime;
    }

    milliseconds TSimpleTimeCalculator::Now() {
        return _nowTime;
    }

    milliseconds TSimpleTimeCalculator::Delta() {
        return _deltaTime;
    }

    void TSimpleTimeCalculator::setDeltaTime(milliseconds deltaTime) {
        TSimpleTimeCalculator::_deltaTime = deltaTime;
    }

    void TSimpleTimeCalculator::setNow(milliseconds nowTime) {
        TSimpleTimeCalculator::_nowTime = nowTime;
    }

    void TSimpleTimeCalculator::setStartTime(milliseconds startTime) {
        TSimpleTimeCalculator::_startTime = startTime;
    }

} /* namespace ThreeMotion */