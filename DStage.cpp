/*
 * File Stage.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "DStage.h"

namespace ThreeMotion {

    DStage::DStage() : DStage::DStage("Default Stage Name", 1000) {}

    DStage::DStage(std::string name, milliseconds timeToPerceive)
            : DExecutable(std::move(name)), complete(false),
              playing(false), timeToPerceive(timeToPerceive) {}

    DStage::DStage(const DStage &other) = default;

    DStage::~DStage() = default;

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

    milliseconds DStage::getTimeToPerceive() const {
        return timeToPerceive;
    }

    void DStage::setTimeToPerceive(milliseconds timeToPerceive) {
        DStage::timeToPerceive = timeToPerceive;
    }
} /* namespace ThreeMotion */
