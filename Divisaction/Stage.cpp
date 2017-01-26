/*
 * File Stage.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Stage.h"

namespace Divisaction {

    Stage::Stage() : Stage::Stage(std::string("Default Stage Name"), 1000) {}

    Stage::Stage(std::string name, double timeToPerceive)
            : Executable(name) {
        complete = false;
        playing = false;
        this->timeToPerceive = timeToPerceive;
    }

    Stage::Stage(const Stage& other) : Executable(other), complete(other.complete),
                                       playing(other.playing),
                                       timeToPerceive(other.timeToPerceive) {}

    Stage::~Stage() {}

    void Stage::start() {
        complete = false;
        playing = true;
        this->onStart();
    }

    Executable::ExecutionState Stage::execute() {
        if (!playing || complete) {
            return ExecutionState::ENDED;
        }
        return onUpdate();
    }

    void Stage::reset() {
        playing = false;
        complete = true;
    }

    bool Stage::isComplete() const {
        return complete;
    }

    bool Stage::isRunning() const {
        return playing;
    }

    double Stage::getTimeToPerceive() const {
        return timeToPerceive;
    }

    void Stage::setTimeToPerceive(double timeToPerceive) {
        Stage::timeToPerceive = timeToPerceive;
    }
} /* namespace Divisaction */
