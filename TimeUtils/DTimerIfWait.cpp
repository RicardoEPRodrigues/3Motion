
/*
 * File DTimerIfWait.cpp in project ThreeMotion
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "DTimerIfWait.h"

namespace ThreeMotion {

    DTimerIfWait::DTimerIfWait(milliseconds duration, std::function<void()> onCompleteCallback,
                               std::function<bool(milliseconds)> onUpdateCallback) : DTimerWait(
            duration,
            onCompleteCallback),
                                                                                     onUpdateCallback(
                                                                                             onUpdateCallback) {}

    bool DTimerIfWait::onUpdate(milliseconds counter) {
        if (onUpdateCallback) {
            return onUpdateCallback(counter);
        } else {
            return false;
        }
    }

    const std::function<bool(milliseconds)>& DTimerIfWait::getOnUpdateCallback() const {
        return onUpdateCallback;
    }

    void
    DTimerIfWait::setOnUpdateCallback(const std::function<bool(milliseconds)>& onUpdateCallback) {
        DTimerIfWait::onUpdateCallback = onUpdateCallback;
    }

} /* namespace ThreeMotion */