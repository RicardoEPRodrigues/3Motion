/*
 * File Perform.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "Perform.h"

namespace Divisaction {

    void Perform::_execute(std::vector<std::shared_ptr<Event>>& responseEvents) {
        if (auto mentalState = mentalStateWeak.lock()) {
            std::vector<std::shared_ptr<Event>> events = std::vector<std::shared_ptr<Event>>();

            if (mentalState->self.action) {
                auto state = mentalState->self.action->execute();
                if (state == Executable::ExecutionState::CHANGED) {
                    if (auto self = mentalState->self.agent.lock()) {
                        events.push_back(std::make_shared<ActionEvent>(self, mentalState->self.action));
                    }
                } else if (state == Executable::ExecutionState::ENDED) {
                    mentalState->self.action = nullptr;
                }
            }
            if (mentalState->self.emotion) {
                auto state = mentalState->self.emotion->execute();
                if (state == Executable::ExecutionState::CHANGED) {
                    auto emotion = mentalState->self.emotion;
                    if (auto self = mentalState->self.agent.lock()) {
                        events.push_back(std::make_shared<EmotionEvent>(self, emotion));
                    }
                }
                if (state == Executable::ExecutionState::ENDED) {
                    mentalState->self.emotion = nullptr;
                }
            }
            // Sends events about the action and emotion of the agent
            responseEvents.insert(std::end(responseEvents), std::begin(events),
                                  std::end(events));
        }
    }

} /* namespace Divisaction */