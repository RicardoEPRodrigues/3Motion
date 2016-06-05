/*
 * File SingleReplyReact.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "SingleReplyReact.h"

namespace Divisaction {

    void SingleReplyReact::execute() {
        if (auto mentalState = mentalStateWeak.lock()) {
            for (auto mentalRep = mentalState->others.begin(); mentalRep != mentalState->others.end(); ++mentalRep) {
                if (mentalRep->updateAction) {
                    if (mentalRep->action
                        && (mentalRep->state == StageType::ANTICIPATION
                            || mentalRep->state == StageType::FOLLOW_THROUGH
                            || mentalRep->state == StageType::FINISHED)) {
                        if (auto self = mentalState->self.agent.lock()) {
                            if (auto origin = mentalRep->agent.lock()) {
                                auto emotionIndex = rand() % mentalState->self.availableEmotions.size();
                                auto emotion = mentalState->self.availableEmotions[emotionIndex];
                                std::shared_ptr<ReplyEvent> event = std::make_shared<ReplyEvent>(self, emotion, origin);
                                mentalState->self.addEmotionalReply(event);
                            }
                        }
                        mentalRep->updateAction = false;
                    }
                }
            }
        }
    }
} /* namespace Divisaction */