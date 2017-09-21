
/*
 * File DTimerManager.cpp in project ThreeMotion
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "DTimerManager.h"
#include "DTimerWait.h"
#include "DTimerIfWait.h"

using namespace std;

namespace ThreeMotion {

    DTimerManager::DTimerManager() {}

    DTimerManager::~DTimerManager() {}

    void DTimerManager::timersUpdate() {
        for (auto timerIter = timers.begin(); timerIter != timers.end();) {
            if ((*timerIter)->update()) {
                timerIter = timers.erase(timerIter);
            } else {
                ++timerIter;
            }
        }
    }

    shared_ptr<DTimer>
    DTimerManager::wait(milliseconds duration, function<void()> onCompleteCallback) {
        if (duration <= 0 || !onCompleteCallback) {
            return nullptr;
        }
        shared_ptr<DTimer> timer = make_shared<DTimerWait>(duration, onCompleteCallback);
        timers.push_back(timer);
        return timer;
    }

    shared_ptr<DTimer>
    DTimerManager::ifWait(milliseconds duration, function<void()> onCompleteCallback,
                          function<bool(milliseconds)> onUpdateCallback) {
        if (duration <= 0 || !onCompleteCallback || !onUpdateCallback) {
            return nullptr;
        }
        shared_ptr<DTimer> timer = make_shared<DTimerIfWait>(duration, onCompleteCallback,
                                                             onUpdateCallback);
        timers.push_back(timer);
        return timer;
    }
} /* namespace ThreeMotion */