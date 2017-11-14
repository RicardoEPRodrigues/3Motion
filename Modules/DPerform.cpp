/*
 * File Perform.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "DPerform.h"

namespace ThreeMotion {

    void DPerform::_execute(std::vector<std::shared_ptr<TEvent>>& responseEvents) {
        if (auto mentalState = theoryOfMindWeak.lock()) {
            std::vector<std::shared_ptr<TEvent>> events = std::vector<std::shared_ptr<TEvent>>();

            if (mentalState->self.action) {
                auto state = mentalState->self.action->Execute();
                if (state == TExecutable::ExecutionState::CHANGED) {
                    if (auto self = mentalState->self.agent.lock()) {
                        events.push_back(
                                std::make_shared<TActionEvent>(self, mentalState->self.action));
                    }
                } else if (state == TExecutable::ExecutionState::ENDED) {
                    mentalState->self.action = nullptr;
                }
            }
            if (mentalState->self.emotion) {
                auto state = mentalState->self.emotion->Execute();
                if (state == TExecutable::ExecutionState::CHANGED) {
                    auto emotion = mentalState->self.emotion;
                    if (auto self = mentalState->self.agent.lock()) {
                        events.push_back(std::make_shared<TEmotionEvent>(self, emotion));
                    }
                }
                if (state == TExecutable::ExecutionState::ENDED) {
                    mentalState->self.emotion = nullptr;
                }
            }
            // Sends events about the action and emotion of the agent
            responseEvents.insert(std::end(responseEvents), std::begin(events),
                                  std::end(events));

            // Clean up
            // FIXME this clean up shouldn't be in the perform module.
            mentalState->self.replies.clear();
        }
    }

} /* namespace ThreeMotion */