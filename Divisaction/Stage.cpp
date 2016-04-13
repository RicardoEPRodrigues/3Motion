/*
 * File Stage.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Stage.h"

namespace Divisaction {

    Stage::Stage() {
        name = std::string("Default Stage Name");
        interuptable = true;
        complete = false;
        playing = false;
    }

    Stage::Stage(std::string name, bool interuptable)
            : Stage::Stage() {
        this->name = name;
        this->interuptable = interuptable;
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

    bool Stage::isInteruptable() const {
        return interuptable;
    }

    void Stage::setInteruptable(bool interuptable) {
        if (!playing) {
            this->interuptable = interuptable;
        }
    }

    const std::string& Stage::getName() const {
        return name;
    }

    void Stage::setName(const std::string& name) {
        this->name = name;
    }
} /* namespace Divisaction */
