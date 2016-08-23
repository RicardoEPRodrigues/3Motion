/*
 * File BaseStage.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "TimeProgressiveStage.h"

namespace Divisaction {

    TimeProgressiveStage::TimeProgressiveStage()
            : Stage(), startTime(-1), elapsedTime(0), duration(0) {
    }

    TimeProgressiveStage::TimeProgressiveStage(std::string name, double timeToPerceive, double durationInMilliseconds)
            : Stage(name, timeToPerceive), startTime(-1), elapsedTime(0), duration(durationInMilliseconds) {}

    TimeProgressiveStage::TimeProgressiveStage(const TimeProgressiveStage& other) : Stage(other),
                                                                                    startTime(other.startTime),
                                                                                    elapsedTime(other.elapsedTime),
                                                                                    duration(other.duration) {}

    TimeProgressiveStage::~TimeProgressiveStage() {
    }

    void TimeProgressiveStage::onStart() {
        startTime = Time::now();
        elapsedTime = 0;
    }

    Executable::ExecutionState TimeProgressiveStage::onUpdate() {
        elapsedTime += Time::delta();
        if (elapsedTime > duration) {
            reset();
            return ExecutionState::ENDED;
        }
        return ExecutionState::RUNNING;
    }

    double TimeProgressiveStage::getProgress() const {
        if (elapsedTime > duration) {
            return 1.0;
        }
        return elapsedTime / duration;
    }

    double TimeProgressiveStage::getDuration() const {
        return duration;
    }

    void TimeProgressiveStage::setDuration(double durationInMilliseconds) {
        if (!isRunning()) {
            this->duration = durationInMilliseconds;
        }
    }

    std::shared_ptr<Stage> TimeProgressiveStage::clone() const {
        return std::make_shared<TimeProgressiveStage>(*this);
    }

} /* namespace Divisaction */
