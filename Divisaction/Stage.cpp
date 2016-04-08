/*
 * File Stage.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Stage.h"

namespace Divisaction {

    Stage::Stage() {
        startTime = system_clock::now();
        name = string("Default Stage Name");
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

    inline bool Stage::operator ==(const Stage& other) {
        return this->getName() == other.getName();
    }

    inline bool Stage::operator !=(const Stage& other) {
        return !((*this) == other);
    }

    inline bool Stage::operator <(const Stage& other) {
        return this->name < other.getName();
    }

    inline bool Stage::operator >(const Stage& other) {
        return this->name > other.getName();
    }

    double Stage::getDurationInMilliseconds() const {
        return durationInMilliseconds;
    }

    void Stage::setDurationInMilliseconds(double durationInMilliseconds) {
        this->durationInMilliseconds = durationInMilliseconds;
    }

    bool Stage::isInteruptable() const {
        return interuptable;
    }

    void Stage::setInteruptable(bool interuptable) {
        this->interuptable = interuptable;
    }

    const std::string& Stage::getName() const {
        return name;
    }

    void Stage::setName(const std::string& name) {
        this->name = name;
    }
} /* namespace Divisaction */
