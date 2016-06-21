/*
 * File BaseStage.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "TimeProgressiveStage.h"

namespace Divisaction {

    TimeProgressiveStage::TimeProgressiveStage() : Stage() {
        duration = 0;
        startTime = -1;
        elapsedTime = 0;
    }

    TimeProgressiveStage::TimeProgressiveStage(std::string name, double timeToPerceive, double durationInMilliseconds)
            : Stage(name, timeToPerceive) {
        startTime = -1;
        elapsedTime = 0;
        this->duration = durationInMilliseconds;
    }

    TimeProgressiveStage::~TimeProgressiveStage() {
    }

    void TimeProgressiveStage::onStart() {
        startTime = Time::now();
        elapsedTime = 0;
    }

    void TimeProgressiveStage::onUpdate() {
        elapsedTime += Time::delta();
        if (elapsedTime > duration) {
            endStage();
        }
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
        if (!isPlaying()) {
            this->duration = durationInMilliseconds;
        }
    }

} /* namespace Divisaction */
