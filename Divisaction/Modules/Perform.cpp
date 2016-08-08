/*
 * File Perform.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "Perform.h"

namespace Divisaction {

    void Perform::_execute(std::vector<std::shared_ptr<Event>>& responseEvents) {
        if (auto mentalState = mentalStateWeak.lock()) {

            if (mentalState->self.action) {
                auto state = mentalState->self.action->execute();
                if (state == Executable::ExecutionState::CHANGED) {
                    if (auto self = mentalState->self.agent.lock()) {
                        mentalState->self.addEvent(std::make_shared<ActionEvent>(self, mentalState->self.action));
                    }
                } else if (state == Executable::ExecutionState::ENDED) {
                    mentalState->self.action = nullptr;
                }
            }
            if (mentalState->self.emotion) {
                auto state = mentalState->self.emotion->execute();
                if (state == Executable::ExecutionState::CHANGED) {
                    auto emotion = mentalState->self.emotion;
                    auto storedEmotion = find_if(mentalState->self.emotionalReplies.begin(),
                                                 mentalState->self.emotionalReplies.end(),
                                                 [&emotion](
                                                         const std::vector<std::shared_ptr<ReplyEvent>>::value_type& stored) {
                                                     return emotion->getName().compare(stored->emotion->getName()) == 0;
                                                 });
                    // if there is not reply with the emotion then throw event
                    if (storedEmotion == mentalState->self.emotionalReplies.end()) {
                        if (auto self = mentalState->self.agent.lock()) {
                            mentalState->self.addEvent(std::make_shared<EmotionEvent>(self, emotion));
                        }
                    }
                }
                if (state == Executable::ExecutionState::ENDED) {
                    mentalState->self.emotion = nullptr;
                }
            }
            // Sends events about the action and emotion of the agent
            responseEvents.insert(std::end(responseEvents), std::begin(mentalState->self.eventsToSend),
                                  std::end(mentalState->self.eventsToSend));
            mentalState->self.eventsToSend.clear();
            // Sends events as replies about other agents' actions
            responseEvents.insert(std::end(responseEvents), std::begin(mentalState->self.emotionalReplies),
                                  std::end(mentalState->self.emotionalReplies));
            mentalState->self.emotionalReplies.clear();

        }
    }

} /* namespace Divisaction */