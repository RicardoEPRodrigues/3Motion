/*
 * File SingleReplyAgent.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "SingleReplyAgent.h"

namespace Divisaction {

    SingleReplyAgent::SingleReplyAgent() {
    }

    void SingleReplyAgent::react() {
        for (auto event = eventsPerceived.begin(); event != eventsPerceived.end(); ++event) {
            Event* eventptr = (*event).get();
            ActionEvent* actionEvent = dynamic_cast<ActionEvent*>(eventptr);
//            EmotionEvent* emotionEvent = dynamic_cast<EmotionEvent*>(eventptr);
//            ReplyEvent* replyEvent = dynamic_cast<ReplyEvent*>(eventptr);
            if (actionEvent && (actionEvent->action->getCurrentStageType() == StageType::ANTICIPATION
                                || actionEvent->action->getCurrentStageType() == StageType::FOLLOW_THROUGH
                                || actionEvent->action->hasFinished())) {
                auto emotion = availableEmotions[0];
                this->emotionalReplies.push_back({shared_from_this(), emotion, *event});
            }
        }
        eventsPerceived.clear();
    }

} /* namespace Divisaction */
