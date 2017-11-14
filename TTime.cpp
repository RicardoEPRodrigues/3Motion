/*
 * File Time.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "TTime.h"


namespace ThreeMotion {
    std::shared_ptr<TTimeCalculator> TTime::_timeCalculator = nullptr;

    TTime::TTime() = default;

    void TTime::SetTimeCalculator(
            std::shared_ptr<TTimeCalculator> const& timeCalculator) {
        _timeCalculator = timeCalculator;
    }

    void TTime::Update() {
        if (_timeCalculator) {
            _timeCalculator->Update();
        }
    }

    milliseconds TTime::StartTime() {
        return _timeCalculator ? _timeCalculator->StartTime() : -1;
    }

    milliseconds TTime::Now() {
        return _timeCalculator ? _timeCalculator->Now() : -1;
    }

    milliseconds TTime::Delta() {
        return _timeCalculator ? _timeCalculator->Delta() : -1;
    }

} /* namespace ThreeMotion */
