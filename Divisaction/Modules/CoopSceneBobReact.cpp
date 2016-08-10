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
            if (!alreadyFelt[0] && selfInActionStage(mentalState, StageType::ANTICIPATION_INTERRUPTIBLE)) {
                if (mentalState->self.emotion) {
                    mentalState->self.emotion->reset();
                }
                mentalState->self.emotion = mentalState->self.availableEmotions[0];
                mentalState->self.emotion->setThrowEvents(true);
                alreadyFelt[0] = true;
            }
            if (!alreadyFelt[1] && selfInActionStage(mentalState, StageType::FOLLOW_THROUGH)) {
                if (mentalState->self.emotion) {
                    mentalState->self.emotion->reset();
                }
                mentalState->self.emotion = mentalState->self.availableEmotions[2];
                mentalState->self.emotion->setThrowEvents(true);
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

                                mentalState->self.emotion = mentalState->self.availableEmotions[emotionIndex];
                                mentalState->self.emotion->setThrowEvents(false);
                                std::shared_ptr<ReplyEvent> event = std::make_shared<ReplyEvent>(self,
                                                                                                 mentalState->self.emotion,
                                                                                                 origin);
                                mentalState->self.addEmotionalReply(event);
                            }
                        }
                    }
                }
            }
        }
    }

} /* namespace Divisaction */