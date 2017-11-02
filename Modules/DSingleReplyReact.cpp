/*
 * File SingleReplyReact.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "DSingleReplyReact.h"
#include <stdlib.h>

namespace ThreeMotion {

    void DSingleReplyReact::_execute() {
        if (auto mentalState = mentalStateWeak.lock()) {
            for (auto mentalRep = mentalState->others.begin();
                 mentalRep != mentalState->others.end(); ++mentalRep) {
                if (mentalRep->updateAction) {
                    if (mentalRep->action
                        && (mentalRep->stage == TStageType::ANTICIPATION_INTERRUPTIBLE
                            || mentalRep->stage == TStageType::ANTICIPATION_UNINTERRUPTIBLE
                            || mentalRep->stage == TStageType::FOLLOW_THROUGH)) {
                        if (auto self = mentalState->self.agent.lock()) {
                            if (auto origin = mentalRep->agent.lock()) {

                                if (mentalState->self.emotion) {
                                    mentalState->self.emotion->Reset();
                                }

                                auto emotionIndex = static_cast<unsigned int>(int(
                                        rand() % mentalState->self.countEmotions()));
                                mentalState->self.emotion = mentalState->self.getEmotion(
                                        emotionIndex);
                                mentalState->self.emotion->replyToAgent = origin;
                            }
                        }
                        mentalRep->updateAction = false;
                    }
                }
            }
        }
    }
} /* namespace ThreeMotion */