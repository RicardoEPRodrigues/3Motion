/*
 * File Stage.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Stage.h"

namespace Divisaction {

    Stage::Stage() : Stage::Stage(std::string("Default Stage Name"), true) {
    }

    Stage::Stage(std::string name, bool interuptable)
            : name(name), interuptable(interuptable) {
        complete = false;
        playing = false;
        timeToPerceive = 100;
    }

    Stage::~Stage() {
    }

    void Stage::start() {
        complete = false;
        playing = true;
        this->onStart();
    }

    void Stage::update() {
        if (!playing || complete) {
            return;
        }
        onUpdate();
    }

    void Stage::endStage() {
        playing = false;
        complete = true;
    }

    bool Stage::isComplete() const {
        return complete;
    }

    bool Stage::isPlaying() const {
        return playing;
    }

    inline bool Stage::operator==(const Stage &other) {
        return this->getName() == other.getName();
    }

    inline bool Stage::operator!=(const Stage &other) {
        return !((*this) == other);
    }

    inline bool Stage::operator<(const Stage &other) {
        return this->name < other.getName();
    }

    inline bool Stage::operator>(const Stage &other) {
        return this->name > other.getName();
    }

    bool Stage::isInteruptable() const {
        return interuptable;
    }

    void Stage::setInteruptable(bool interuptable) {
        if (!playing) {
            this->interuptable = interuptable;
        }
    }

    const std::string &Stage::getName() const {
        return name;
    }

    void Stage::setName(const std::string &name) {
        this->name = name;
    }
    double Stage::getTimeToPerceive() const {
        return timeToPerceive;
    }

    void Stage::setTimeToPerceive(double timeToPerceive) {
        Stage::timeToPerceive = timeToPerceive;
    }
} /* namespace Divisaction */
