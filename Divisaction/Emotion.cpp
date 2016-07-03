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

    bool Emotion::execute() {
        if (!running) {
            reset();
            running = true;
            if (throwEvents && started) {
                started();
            }
        }

        if (!stage->isPlaying()) {
            stage->start();
        }
        stage->update();
        if (throwEvents && stage->isComplete()) {
            running = false;
            if (finished) {
                finished();
            }
            return true;
        }

        return false;
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
