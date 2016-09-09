/*
 * File Emotion.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Emotion.h"
#include "Agent.h"

namespace Divisaction {

    Emotion::Emotion() : running(false), stage(nullptr), replyText(""),
                         replyTo(std::make_shared<Agent>()/* Gave reply to an empty agent until it's valid*/) {}

    Emotion::Emotion(std::string name, std::shared_ptr<Stage> stage, std::string replyText) : stage(stage),
                                                                                              replyText(replyText) {
        setName(name);
    }

    Emotion::Emotion(const Emotion& other) : Executable(other), running(other.running),
                                             stage(other.stage->clone()),
                                             replyText(other.replyText), replyTo(other.replyTo) {}

    Emotion::~Emotion() {}

    Executable::ExecutionState Emotion::execute() {
        ExecutionState state = ExecutionState::RUNNING;
        if (!running) {
            reset();
            running = true;
        }

        if (!stage->isRunning()) {
            stage->start();
            state = ExecutionState::CHANGED;
        }
        stage->execute();
        if (stage->isComplete()) {
            running = false;
            state = ExecutionState::ENDED;
            replyTo = std::make_shared<Agent>();
        }

        return state;
    }

    void Emotion::reset() {
        this->running = false;
        stage->reset();
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

    const std::weak_ptr<IAgent>& Emotion::getReplyAgent() const {
        return replyTo;
    }

    void Emotion::replyToAgent(const std::shared_ptr<IAgent>& replyTo) {
        Emotion::replyTo = replyTo;
    }

} /* namespace Divisaction */
