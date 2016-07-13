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
                        && (mentalRep->state == StageType::ANTICIPATION_INTERRUPTIBLE
                            || mentalRep->state == StageType::ANTICIPATION_UNINTERRUPTIBLE
                            || mentalRep->state == StageType::FOLLOW_THROUGH)) {
                        if (auto self = mentalState->self.agent.lock()) {
                            if (auto origin = mentalRep->agent.lock()) {

                                if (mentalState->self.emotion) {
                                    mentalState->self.emotion->reset();
                                }

                                auto emotionIndex = rand() % mentalState->self.availableEmotions.size();
                                mentalState->self.emotion = mentalState->self.availableEmotions[emotionIndex];
                                mentalState->self.emotion->setThrowEvents(false);
                                std::shared_ptr<ReplyEvent> event = std::make_shared<ReplyEvent>(self, mentalState->self.emotion, origin);
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