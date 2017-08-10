/*
 * File Perform.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "DPerform.h"

namespace Divisaction {

    void DPerform::_execute(std::vector<std::shared_ptr<DEvent>>& responseEvents) {
        if (auto mentalState = mentalStateWeak.lock()) {
            std::vector<std::shared_ptr<DEvent>> events = std::vector<std::shared_ptr<DEvent>>();

            if (mentalState->self.action) {
                auto state = mentalState->self.action->execute();
                if (state == DExecutable::ExecutionState::CHANGED) {
                    if (auto self = mentalState->self.agent.lock()) {
                        events.push_back(
                                std::make_shared<DActionEvent>(self, mentalState->self.action));
                    }
                } else if (state == DExecutable::ExecutionState::ENDED) {
                    mentalState->self.action = nullptr;
                }
            }
            if (mentalState->self.emotion) {
                auto state = mentalState->self.emotion->execute();
                if (state == DExecutable::ExecutionState::CHANGED) {
                    auto emotion = mentalState->self.emotion;
                    if (auto self = mentalState->self.agent.lock()) {
                        events.push_back(std::make_shared<DEmotionEvent>(self, emotion));
                    }
                }
                if (state == DExecutable::ExecutionState::ENDED) {
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

} /* namespace Divisaction */