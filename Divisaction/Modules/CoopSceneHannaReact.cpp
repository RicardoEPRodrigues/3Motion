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

    void CoopSceneHannaReact::execute() {
        if (auto mentalState = mentalStateWeak.lock()) {
            if (!alreadyFelt[0] && !mentalState->self.emotion && mentalState->self.availableEmotions.size() > 0 &&
                mentalState->self.action &&
                mentalState->self.action->getCurrentStageType() == StageType::ANTICIPATION_INTERRUPTIBLE) {
                mentalState->self.emotion = mentalState->self.availableEmotions[1];
                alreadyFelt[0] = true;
                return;
            }
            if (!alreadyFelt[1] && !mentalState->self.emotion && mentalState->self.availableEmotions.size() > 0 &&
                mentalState->self.action &&
                mentalState->self.action->getCurrentStageType() == StageType::FOLLOW_THROUGH) {
                mentalState->self.emotion = mentalState->self.availableEmotions[2];
                alreadyFelt[1] = true;
                return;
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
} /* namespace Divisaction */