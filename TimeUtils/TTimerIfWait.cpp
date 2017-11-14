
/*
 * File DTimerIfWait.cpp in project ThreeMotion
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "TTimerIfWait.h"

namespace ThreeMotion {

    TTimerIfWait::TTimerIfWait(std::function<void()> const& onCompleteCallback,
                               std::function<bool(
                                       milliseconds)> const& onUpdateCallback,
                               milliseconds duration)
            : TTimerWait(onCompleteCallback, duration),
              onUpdateCallback(onUpdateCallback) { }

    bool TTimerIfWait::OnUpdate(milliseconds counter) {
        if (onUpdateCallback) {
            return onUpdateCallback(counter);
        } else {
            return false;
        }
    }

} /* namespace ThreeMotion */