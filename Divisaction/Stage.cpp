/*
 * File Stage.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Stage.h"

namespace Divisaction {

    Stage::Stage() {
        startTime = system_clock::now();
        name = string();
        durationInMilliseconds = 0;
        interuptable = true;
        complete = false;
        started = false;
    }

    Stage::Stage(std::string name, double durationInMilliseconds,
            bool interuptable) :
            Stage::Stage() {
        this->name = name;
        this->durationInMilliseconds = durationInMilliseconds;
        this->interuptable = interuptable;
    }

    Stage::~Stage() {
    }

    void Stage::reset() {
        complete = false;
        started = false;
    }

    void Stage::start() {
        complete = false;
        started = true;
        this->startTime = system_clock::now();
    }

    double Stage::getProgress() {
        if (complete) {
            return 1;
        }
        double percentage = getProgress(startTime, system_clock::now(),
                durationInMilliseconds);
        if (percentage == 1) {
            complete = true;
        }
        return percentage;
    }

    void Stage::endStage() {
        this->complete = true;
    }

    bool Stage::isComplete() {
        if (!complete) {
            getProgress();
        }
        return complete;
    }

    bool Stage::hasStarted() const {
        return started;
    }

    double Stage::getProgress(system_clock::time_point start,
            system_clock::time_point now, double durationInMilliseconds) {
        if (durationInMilliseconds <= 0) {
            return 0;
        }
        double difference = chrono::duration_cast<chrono::milliseconds>(
                now - start).count();

        if (difference > durationInMilliseconds) {
            return 1;
        } else {
            return (difference / (double) durationInMilliseconds);
        }
    }
} /* namespace Divisaction */
