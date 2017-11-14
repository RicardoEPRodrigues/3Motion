
/*
 * File DTimerWait.cpp in project ThreeMotion
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "TTimerWait.h"

namespace ThreeMotion {

    TTimerWait::TTimerWait(std::function<void()> const& onCompleteCallback,
                           milliseconds duration) :
            TTimer(duration), onCompleteCallback(onCompleteCallback) { }

    void TTimerWait::OnComplete() {
        if (onCompleteCallback) {
            onCompleteCallback();
        }
    }
} /* namespace ThreeMotion */