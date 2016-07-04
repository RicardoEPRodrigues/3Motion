/*
 * File Emotion.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Emotion.h"

namespace Divisaction {

    Emotion::Emotion() {
        this->stage = nullptr;
        this->running = false;
        this->throwEvents = true;
        this->replyText = "";
    }

    Executable::ExecutionState Emotion::execute() {
        ExecutionState state = ExecutionState::RUNNING;
        if (!running) {
            reset();
            running = true;
        }

        if (!stage->isPlaying()) {
            stage->start();
            state = ExecutionState::CHANGED;
        }
        stage->update();
        if (stage->isComplete()) {
            running = false;
            state = ExecutionState::ENDED;
        }

        return state;
    }

    void Emotion::reset() {
        this->running = false;
        stage->endStage();
    }

    std::shared_ptr<Stage> Emotion::getStage() const {
        return stage;
    }

    void Emotion::setStage(std::shared_ptr<Stage> emotion) {
        this->stage = emotion;
    }

    bool Emotion::isRunning() const {
        return this->running;
    }

} /* namespace Divisaction */
