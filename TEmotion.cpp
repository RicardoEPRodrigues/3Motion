/*
 * File Emotion.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "TEmotion.h"

#include <utility>
#include "TAgent.h"

namespace ThreeMotion {

    TEmotion::TEmotion() : TEmotion("", nullptr, "") { }

    TEmotion::TEmotion(std::string name, std::shared_ptr<TStage> stage, std::string replyText)
            : TExecutable(std::move(name)), running(false), stage(std::move(stage)),
              replyText(std::move(replyText)),
              replyToAgent() { }

    TEmotion::TEmotion(const TEmotion& other) : TExecutable(other), running(other.running),
                                                stage(other.stage->Clone()),
                                                replyText(other.replyText),
                                                replyToAgent(other.replyToAgent) { }

    TEmotion::~TEmotion() = default;

    TExecutable::ExecutionState TEmotion::Execute() {
        ExecutionState state = ExecutionState::RUNNING;
        if (!running) {
            Reset();
            running = true;
        }

        if (!stage->IsRunning()) {
            stage->Start();
            state = ExecutionState::CHANGED;
        }
        stage->Execute();
        if (stage->IsComplete()) {
            running = false;
            state = ExecutionState::ENDED;
            replyToAgent.reset();
        }

        return state;
    }

    void TEmotion::Reset() {
        this->running = false;
        stage->Reset();
    }

    bool TEmotion::IsRunning() const {
        return this->running;
    }

} /* namespace ThreeMotion */
