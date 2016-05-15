/*
 * File Emotion.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Emotion.h"

namespace Divisaction {

    Emotion::Emotion() {
        this->emotion = nullptr;
        this->running = false;
    }

    bool Emotion::execute() {
        if (!running) {
            reset();
            running = true;
            if (started) {
                started();
            }
        }

        if (!emotion->isPlaying()) {
            emotion->start();
        }
        emotion->update();
        if (emotion->isComplete()) {
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
        emotion->endStage();
    }

    std::shared_ptr<Stage> Emotion::getEmotion() const {
        return emotion;
    }

    void Emotion::setEmotion(Stage* emotion) {
        this->emotion = std::shared_ptr<Stage>(emotion);
    }

    void Emotion::setEmotion(std::shared_ptr<Stage>& emotion) {
        this->emotion = emotion;
    }

    bool Emotion::isRunning() const {
        return this->running;
    }

} /* namespace Divisaction */
