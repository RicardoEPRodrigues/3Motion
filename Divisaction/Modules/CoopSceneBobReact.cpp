/*
 * File CoopSceneBobReact.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "CoopSceneBobReact.h"

namespace Divisaction {

    CoopSceneBobReact::CoopSceneBobReact() {
        alreadyFelt = std::vector<bool>(10);
    }

    void CoopSceneBobReact::_execute() {
        if (auto mentalState = mentalStateWeak.lock()) {
            if (!alreadyFelt[0]) {
                if (mentalState->self.emotion) {
                    mentalState->self.emotion->reset();
                }
                mentalState->self.emotion = mentalState->self.getEmotion(0);
                alreadyFelt[0] = true;
            }
            if (!alreadyFelt[1] && mentalState->self.actionHasName("Long Walk") && mentalState->self.actionInStage(StageType::FOLLOW_THROUGH)) {
                if (mentalState->self.emotion) {
                    mentalState->self.emotion->reset();
                }
                mentalState->self.emotion = mentalState->self.getEmotion(2);
                alreadyFelt[1] = true;
            }

            for (auto mentalRep = mentalState->others.begin(); mentalRep != mentalState->others.end(); ++mentalRep) {
                if (mentalRep->updateAction && mentalRep->updateEmotion) {
                    if (mentalRep->action && mentalRep->emotion) {
                        mentalRep->updateAction = false;
                        mentalRep->updateEmotion = false;
                        if (auto self = mentalState->self.agent.lock()) {
                            if (auto origin = mentalRep->agent.lock()) {
                                auto emotionIndex = 0;
                                if (mentalRep->state == StageType::ANTICIPATION_INTERRUPTIBLE) {
                                    emotionIndex = 0;
                                } else {
                                    emotionIndex = 2;
                                }
                                if (mentalState->self.emotion) {
                                    mentalState->self.emotion->reset();
                                }

                                mentalState->self.emotion = mentalState->self.getEmotion(emotionIndex);
                                mentalState->self.emotion->replyToAgent(origin);
                            }
                        }
                    }
                }
            }
        }
    }

} /* namespace Divisaction */