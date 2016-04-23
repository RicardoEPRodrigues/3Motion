/*
 * File Looper.cpp in project DivisactionCommandLine
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Looper.h"

namespace Divisaction {

    using namespace std;

    Looper::Looper() {
        continueLoop = false;
        interval = 250;
    }

    Looper::Looper(std::function<void()> callback, long int interval) :
            Looper::Looper() {
        this->callback = callback;
        this->interval = interval;
    }

    Looper::~Looper() {

    }

    void Looper::setCallback(std::function<void()> callback) {
        if (!callback) {
            throw nullPointerExc;
        }
        this->callback = callback;
    }

    void Looper::setInterval(long int interval) {
        if (interval < 0) {
            throw invalidArgumentExc;
        }
        this->interval = interval;
    }


    void Divisaction::Looper::start() {
        if (this->continueLoop) { // If it has already begun, then ignore call
            return;
        }
        if (!this->callback) {
            throw nullPointerExc;
        }

        this->continueLoop = true;

        chrono::milliseconds intervalMilliseconds(this->interval);

        while (this->continueLoop) {
            this->callback();
            this_thread::sleep_for(intervalMilliseconds);
        }
    }

    void Looper::start(std::function<void()> callback) {
        this->setCallback(callback);
        this->start();
    }

    bool Looper::isRunning() {
        return this->continueLoop;
    }

    void Looper::stop() {
        this->continueLoop = false;
    }
} /* namespace Divisaction */
