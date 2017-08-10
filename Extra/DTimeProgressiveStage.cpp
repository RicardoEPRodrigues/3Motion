/*
 * File BaseStage.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "DTimeProgressiveStage.h"

namespace Divisaction {

    DTimeProgressiveStage::DTimeProgressiveStage()
            : DStage(), startTime(-1), elapsedTime(0), duration(0) {
    }

    DTimeProgressiveStage::DTimeProgressiveStage(std::string name, double timeToPerceive,
                                               double durationInMilliseconds)
            : DStage(name, timeToPerceive), startTime(-1), elapsedTime(0),
              duration(durationInMilliseconds) {}

    DTimeProgressiveStage::DTimeProgressiveStage(const DTimeProgressiveStage& other) : DStage(other),
                                                                                    startTime(
                                                                                            other.startTime),
                                                                                    elapsedTime(
                                                                                            other.elapsedTime),
                                                                                    duration(
                                                                                            other.duration) {}

    DTimeProgressiveStage::~DTimeProgressiveStage() {
    }

    void DTimeProgressiveStage::onStart() {
        elapsedTime = 0;
    }

    DExecutable::ExecutionState DTimeProgressiveStage::onUpdate() {
        elapsedTime += DTime::delta();
        if (elapsedTime > duration) {
            reset();
            return ExecutionState::ENDED;
        }
        return ExecutionState::RUNNING;
    }

    double DTimeProgressiveStage::getProgress() const {
        if (elapsedTime > duration) {
            return 1.0;
        }
        return elapsedTime / duration;
    }

    double DTimeProgressiveStage::getDuration() const {
        return duration;
    }

    void DTimeProgressiveStage::setDuration(double durationInMilliseconds) {
        if (!isRunning()) {
            this->duration = durationInMilliseconds;
        }
    }

    std::shared_ptr<DStage> DTimeProgressiveStage::clone() const {
        return std::make_shared<DTimeProgressiveStage>(*this);
    }

} /* namespace Divisaction */
