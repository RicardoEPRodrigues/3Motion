/*
 * File SingleReplyAgent.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "SingleReplyAgent.h"

namespace Divisaction {

    SingleReplyAgent::SingleReplyAgent() {
        addAvailableEmotion(new Confidence());
    }

    SingleReplyAgent::~SingleReplyAgent() {
    }

    void SingleReplyAgent::react() {
        for (Event event : eventsPerceived) {
            if (event.type == EventType::ACTION && event.stageType == StageType::ANTICIPATION) {
                Emotion *emotion = availableEmotions[0];
                this->emotionalReplies.push_back({this, emotion, event});
            }
        }
        eventsPerceived.clear();
    }

} /* namespace Divisaction */