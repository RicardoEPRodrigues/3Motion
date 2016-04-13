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

    Emotion::~Emotion() {
        if (emotion) {
            delete this->emotion;
        }
    }

    bool Emotion::execute() {
        if (!running) {
            reset();
            running = true;
            if (started) {
                started(this);
            }
        }

        if (!emotion->isPlaying()) {
            emotion->start();
        } else if (emotion->isComplete()) {
            running = false;
            if (finished) {
                finished(this);
            }
            return true;
        }

        return false;
    }

    void Emotion::reset() {
        this->running = false;
        emotion->endStage();
    }

    Stage* Emotion::getEmotion() const {
        return emotion;
    }

    void Emotion::setEmotion(Stage* emotion) {
        this->emotion = emotion;
    }

    bool Emotion::isRunning() {
        return this->running;
    }

} /* namespace Divisaction */
