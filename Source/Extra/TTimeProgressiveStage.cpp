/*
 * File BaseStage.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "TTimeProgressiveStage.h"

namespace ThreeMotion {

    TTimeProgressiveStage::TTimeProgressiveStage()
            : TStage(), startTime(-1), elapsedTime(0), duration(0) {
    }

    TTimeProgressiveStage::TTimeProgressiveStage(std::string const& name,
                                                 milliseconds timeToPerceive,
                                                 milliseconds durationInMilliseconds)
            : TStage(name, timeToPerceive), startTime(-1), elapsedTime(0),
              duration(durationInMilliseconds) { }

    TTimeProgressiveStage::TTimeProgressiveStage(
            const TTimeProgressiveStage&) = default;

    TTimeProgressiveStage::~TTimeProgressiveStage() = default;

    void TTimeProgressiveStage::OnStart() {
        elapsedTime = 0;
    }

    TExecutable::ExecutionState TTimeProgressiveStage::OnUpdate() {
        elapsedTime += TTime::Delta();
        if (elapsedTime > duration) {
            Reset();
            return ExecutionState::ENDED;
        }
        return ExecutionState::RUNNING;
    }

    float TTimeProgressiveStage::GetProgress() const {
        if (elapsedTime > duration) {
            return 1.0f;
        }
        return elapsedTime / duration;
    }

    milliseconds TTimeProgressiveStage::GetDuration() const {
        return duration;
    }

    void
    TTimeProgressiveStage::SetDuration(milliseconds durationInMilliseconds) {
        if (!IsRunning()) {
            this->duration = durationInMilliseconds;
        }
    }

    std::shared_ptr<TStage> TTimeProgressiveStage::Clone() const {
        return std::make_shared<TTimeProgressiveStage>(*this);
    }

} /* namespace ThreeMotion */
