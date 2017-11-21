/*
 * File Stage.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "TStage.h"

namespace ThreeMotion {

    TStage::TStage() : TStage::TStage("Default Stage Name", 1000) {}

    TStage::TStage(std::string name, milliseconds timeToPerceive)
            : TExecutable(std::move(name)), complete(false),
              playing(false), timeToPerceive(timeToPerceive) {}

    TStage::TStage(const TStage &) = default;

    TStage::~TStage() = default;

    void TStage::Start() {
        complete = false;
        playing = true;
        this->OnStart();
    }

    TExecutable::ExecutionState TStage::Execute() {
        if (!playing || complete) {
            return ExecutionState::ENDED;
        }
        return OnUpdate();
    }

    void TStage::Reset() {
        playing = false;
        complete = true;
    }

    bool TStage::IsComplete() const {
        return complete;
    }

    bool TStage::IsRunning() const {
        return playing;
    }

    milliseconds TStage::GetTimeToPerceive() const {
        return timeToPerceive;
    }

    void TStage::SetTimeToPerceive(milliseconds timeToPerceive) {
        TStage::timeToPerceive = timeToPerceive;
    }
} /* namespace ThreeMotion */
