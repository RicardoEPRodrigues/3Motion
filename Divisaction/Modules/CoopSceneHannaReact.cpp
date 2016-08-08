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
            if (!alreadyFelt[0] && mentalState->self.action &&
                mentalState->self.action->getCurrentStageType() == StageType::ANTICIPATION_INTERRUPTIBLE) {
                if (mentalState->self.emotion) {
                    mentalState->self.emotion->reset();
                }
                mentalState->self.emotion = mentalState->self.availableEmotions[1];
                mentalState->self.emotion->setThrowEvents(true);
                alreadyFelt[0] = true;
            } else if (!alreadyFelt[1] && mentalState->self.action &&
                       mentalState->self.action->getCurrentStageType() == StageType::FOLLOW_THROUGH) {
                if (mentalState->self.emotion) {
                    mentalState->self.emotion->reset();
                }
                mentalState->self.emotion = mentalState->self.availableEmotions[2];
                mentalState->self.emotion->setThrowEvents(true);
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

                            mentalState->self.emotion = mentalState->self.availableEmotions[emotionIndex];
                            mentalState->self.emotion->setThrowEvents(false);
                            std::shared_ptr<ReplyEvent> event = std::make_shared<ReplyEvent>(self,
                                                                                             mentalState->self.emotion,
                                                                                             origin);
                            mentalState->self.addEmotionalReply(event);
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
