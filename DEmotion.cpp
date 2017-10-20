/*
 * File Emotion.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "DEmotion.h"

#include <utility>
#include "DAgent.h"

namespace ThreeMotion {

    DEmotion::DEmotion() : DEmotion("", nullptr, "") {}

    DEmotion::DEmotion(std::string name, std::shared_ptr<DStage> stage, std::string replyText)
            : DExecutable(name), running(false), stage(std::move(stage)), replyText(std::move(replyText)),
              replyTo(std::make_shared<DAgent>()/* Gave reply to an empty agent until it's valid*/) {
        setName(name);
    }

    DEmotion::DEmotion(const DEmotion& other) : DExecutable(other), running(other.running),
                                             stage(other.stage->clone()),
                                             replyText(other.replyText), replyTo(other.replyTo) {}

    DEmotion::~DEmotion() = default;

    DExecutable::ExecutionState DEmotion::execute() {
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
            replyTo = std::make_shared<DAgent>();
        }

        return state;
    }

    void DEmotion::reset() {
        this->running = false;
        stage->reset();
    }

    std::shared_ptr<DStage> DEmotion::getStage() const {
        return stage;
    }

    void DEmotion::setStage(std::shared_ptr<DStage> emotion) {
        this->stage = emotion;
    }

    bool DEmotion::isRunning() const {
        return this->running;
    }

    const std::weak_ptr<DIAgent>& DEmotion::getReplyAgent() const {
        return replyTo;
    }

    void DEmotion::replyToAgent(const std::shared_ptr<DIAgent>& replyTo) {
        DEmotion::replyTo = replyTo;
    }

} /* namespace ThreeMotion */
