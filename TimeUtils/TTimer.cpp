
/*
 * File DTimer.cpp in project ThreeMotion
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "TTimer.h"

namespace ThreeMotion {

    TTimer::TTimer(milliseconds duration) : counter(0), duration(duration),
                                            playing(false) { }

    TTimer::~TTimer() = default;

    bool TTimer::Update() {
        if (!playing) {
            return false;
        }
        counter += TTime::Delta();
        if (counter >= duration) {
            OnComplete();
            return true;
        } else {
            return OnUpdate(counter);
        }
    }

    void TTimer::OnComplete() { }

    bool TTimer::OnUpdate(milliseconds) { return false; }

    bool TTimer::IsPaused() const {
        return playing;
    }

    void TTimer::Play() {
        playing = true;
    }

    void TTimer::Pause() {
        playing = false;
    }

    milliseconds TTimer::GetDuration() const {
        return duration;
    }

    void TTimer::SetDuration(milliseconds duration) {
        if (duration >= 0) {
            TTimer::duration = duration;
        }
    }
} /* namespace ThreeMotion */