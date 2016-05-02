/*
 * File SingleReplyAgent.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "InteractiveReplyAgent.h"

namespace Divisaction {

    InteractiveReplyAgent::InteractiveReplyAgent() {
    }

    InteractiveReplyAgent::~InteractiveReplyAgent() {
    }

    void InteractiveReplyAgent::react() {
        for (Event event : eventsPerceived) {
            if (event.type == Event::Type::ACTION && event.action->getCurrentStageType() == StageType::ANTICIPATION) {
                Emotion *emotion = new Confidence();
                this->emotionalReplies.push_back({this, emotion, event});
            }
        }
        eventsPerceived.clear();
    }

} /* namespace Divisaction */
