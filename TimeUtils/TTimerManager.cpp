
/*
 * File DTimerManager.cpp in project ThreeMotion
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "TTimerManager.h"
#include "TTimerWait.h"
#include "TTimerIfWait.h"

using namespace std;

namespace ThreeMotion {

    TTimerManager::TTimerManager() = default;

    TTimerManager::~TTimerManager() = default;

    void TTimerManager::UpdateTimers() {
        for (auto timerIter = timers.begin(); timerIter != timers.end();) {
            if ((*timerIter)->Update()) {
                timerIter = timers.erase(timerIter);
            } else {
                ++timerIter;
            }
        }
    }

    shared_ptr<TTimer>
    TTimerManager::Wait(milliseconds duration,
                        function<void()> onCompleteCallback) {
        if (duration <= 0 || !onCompleteCallback) {
            return nullptr;
        }
        shared_ptr<TTimer> timer = make_shared<TTimerWait>(onCompleteCallback,
                                                           duration);
        timers.push_back(timer);
        return timer;
    }

    shared_ptr<TTimer>
    TTimerManager::IfWait(milliseconds duration,
                          function<void()> onCompleteCallback,
                          function<bool(milliseconds)> onUpdateCallback) {
        if (duration <= 0 || !onCompleteCallback || !onUpdateCallback) {
            return nullptr;
        }
        shared_ptr<TTimer> timer = make_shared<TTimerIfWait>(onCompleteCallback,
                                                             onUpdateCallback,
                                                             duration);
        timers.push_back(timer);
        return timer;
    }
} /* namespace ThreeMotion */