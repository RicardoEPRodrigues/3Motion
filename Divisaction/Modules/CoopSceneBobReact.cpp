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

    void CoopSceneBobReact::execute() {
        if (auto mentalState = mentalStateWeak.lock()) {
            if (!alreadyFelt[0] && !mentalState->self.emotion &&
                mentalState->self.action &&
                mentalState->self.action->getCurrentStageType() == StageType::ANTICIPATION_INTERRUPTIBLE) {
                mentalState->self.emotion = mentalState->self.availableEmotions[0];
                alreadyFelt[0] = true;
                return;
            }
            if (!alreadyFelt[1] && !mentalState->self.emotion &&
                mentalState->self.action &&
                mentalState->self.action->getCurrentStageType() == StageType::FOLLOW_THROUGH) {
                mentalState->self.emotion = mentalState->self.availableEmotions[2];
                alreadyFelt[1] = true;
                return;
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
                                auto emotion = mentalState->self.availableEmotions[emotionIndex];
                                std::shared_ptr<ReplyEvent> event = std::make_shared<ReplyEvent>(self, emotion,
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