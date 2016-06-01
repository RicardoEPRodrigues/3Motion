/*
 * File Perform.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "Perform.h"

namespace Divisaction {

    void Perform::execute(std::vector<std::shared_ptr<Event>>& responseEvents) {
        if (auto mentalState = mentalStateWeak.lock()) {

            if (mentalState->self.action) {
                if (mentalState->self.action->execute()) {
                    mentalState->self.action = nullptr;
                }
            }
            if (mentalState->self.emotion) {
                if (mentalState->self.emotion->execute()) {
                    mentalState->self.emotion = nullptr;
                }
            }
            // Sends the event about the action of the current agent
            responseEvents.insert(std::end(responseEvents), std::begin(mentalState->self.eventsToSend),
                                  std::end(mentalState->self.eventsToSend));
            mentalState->self.eventsToSend.clear();
            // Sends eventsToSend as replies about other agents' actions
            for (auto reply = mentalState->self.emotionalReplies.begin();
                 reply != mentalState->self.emotionalReplies.end();) {
                if (!reply->second) {
                    responseEvents.push_back(reply->first);
                    reply->second = true;
                }
                if (reply->first->emotion->execute()) {
                    reply = mentalState->self.emotionalReplies.erase(reply);
                } else {
                    ++reply;
                }
            }
        }
    }

} /* namespace Divisaction */