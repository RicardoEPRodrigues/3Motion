/*
 * File CoopSceneHannaReact.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "CoopSceneHannaReact.h"

namespace Divisaction {
    CoopSceneHannaReact::CoopSceneHannaReact() {
        alreadyFelt = std::vector<bool>(10);
    }

    void CoopSceneHannaReact::_execute() {
        if (auto mentalState = mentalStateWeak.lock()) {
            if (!alreadyFelt[0] && mentalState->self.actionInStage(StageType::ANTICIPATION_INTERRUPTIBLE)) {
                if (mentalState->self.emotion) {
                    mentalState->self.emotion->reset();
                }
                mentalState->self.emotion = mentalState->self.getEmotion(1);
                alreadyFelt[0] = true;
            } else if (!alreadyFelt[1] && mentalState->self.actionInStage(StageType::FOLLOW_THROUGH)) {
                if (mentalState->self.emotion) {
                    mentalState->self.emotion->reset();
                }
                mentalState->self.emotion = mentalState->self.getEmotion(2);
                alreadyFelt[1] = true;
            }

            for (auto mentalRep = mentalState->others.begin(); mentalRep != mentalState->others.end(); ++mentalRep) {
                if (mentalRep->updateAction && mentalRep->updateEmotion && mentalRep->action && mentalRep->emotion) {
                    mentalRep->updateAction = false;
                    mentalRep->updateEmotion = false;
                    if (auto self = mentalState->self.agent.lock()) {
                        if (auto origin = mentalRep->agent.lock()) {
                            auto emotionIndex = 0;
                            if (mentalRep->state == StageType::ANTICIPATION_INTERRUPTIBLE) {
                                emotionIndex = 1;
                            } else {
                                emotionIndex = 3;
                            }

                            if (mentalState->self.emotion) {
                                mentalState->self.emotion->reset();
                            }

                            mentalState->self.emotion = mentalState->self.getEmotion(emotionIndex);
                            mentalState->self.emotion->replyToAgent(origin);
                        }
                    }
                } else if (mentalRep->updateAction && mentalRep->action) {
                    // TODO deal with the case of having only an action
                } else if (mentalRep->updateEmotion && mentalRep->emotion) {
                    // TODO deal with the case of having only an emotion
                }
            }
        }
    }
} /* namespace Divisaction */
