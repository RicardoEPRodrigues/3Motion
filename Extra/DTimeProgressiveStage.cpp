/*
 * File BaseStage.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "DTimeProgressiveStage.h"

namespace ThreeMotion {

    DTimeProgressiveStage::DTimeProgressiveStage()
            : TStage(), startTime(-1), elapsedTime(0), duration(0) {
    }

    DTimeProgressiveStage::DTimeProgressiveStage(std::string name, milliseconds timeToPerceive,
                                               milliseconds durationInMilliseconds)
            : TStage(name, timeToPerceive), startTime(-1), elapsedTime(0),
              duration(durationInMilliseconds) {}

    DTimeProgressiveStage::DTimeProgressiveStage(const DTimeProgressiveStage& other) : TStage(other),
                                                                                    startTime(
                                                                                            other.startTime),
                                                                                    elapsedTime(
                                                                                            other.elapsedTime),
                                                                                    duration(
                                                                                            other.duration) {}

    DTimeProgressiveStage::~DTimeProgressiveStage() {
    }

    void DTimeProgressiveStage::OnStart() {
        elapsedTime = 0;
    }

    TExecutable::ExecutionState DTimeProgressiveStage::onUpdate() {
        elapsedTime += TTime::Delta();
        if (elapsedTime > duration) {
            Reset();
            return ExecutionState::ENDED;
        }
        return ExecutionState::RUNNING;
    }

    float DTimeProgressiveStage::getProgress() const {
        if (elapsedTime > duration) {
            return 1.0;
        }
        return elapsedTime / duration;
    }

    milliseconds DTimeProgressiveStage::getDuration() const {
        return duration;
    }

    void DTimeProgressiveStage::setDuration(milliseconds durationInMilliseconds) {
        if (!IsRunning()) {
            this->duration = durationInMilliseconds;
        }
    }

    std::shared_ptr<TStage> DTimeProgressiveStage::clone() const {
        return std::make_shared<DTimeProgressiveStage>(*this);
    }

} /* namespace ThreeMotion */
