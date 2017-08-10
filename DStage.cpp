/*
 * File Stage.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "DStage.h"

namespace Divisaction {

    DStage::DStage() : DStage::DStage(std::string("Default Stage Name"), 1000) {}

    DStage::DStage(std::string name, double timeToPerceive)
            : DExecutable(name) {
        complete = false;
        playing = false;
        this->timeToPerceive = timeToPerceive;
    }

    DStage::DStage(const DStage& other) : DExecutable(other), complete(other.complete),
                                       playing(other.playing),
                                       timeToPerceive(other.timeToPerceive) {}

    DStage::~DStage() {}

    void DStage::start() {
        complete = false;
        playing = true;
        this->onStart();
    }

    DExecutable::ExecutionState DStage::execute() {
        if (!playing || complete) {
            return ExecutionState::ENDED;
        }
        return onUpdate();
    }

    void DStage::reset() {
        playing = false;
        complete = true;
    }

    bool DStage::isComplete() const {
        return complete;
    }

    bool DStage::isRunning() const {
        return playing;
    }

    double DStage::getTimeToPerceive() const {
        return timeToPerceive;
    }

    void DStage::setTimeToPerceive(double timeToPerceive) {
        DStage::timeToPerceive = timeToPerceive;
    }
} /* namespace Divisaction */
