/*
 * File SingleReplyReact.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "SingleReplyReact.h"

namespace Divisaction {

    void SingleReplyReact::_execute() {
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

                                auto emotionIndex = rand() % mentalState->self.countEmotions();
                                mentalState->self.emotion = mentalState->self.getEmotion(emotionIndex);
                                mentalState->self.emotion->replyToAgent(origin);
                            }
                        }
                        mentalRep->updateAction = false;
                    }
                }
            }
        }
    }
} /* namespace Divisaction */