/*
 * File SingleReplyAgent.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "SingleReplyAgent.h"

namespace Divisaction {

    SingleReplyAgent::SingleReplyAgent() {
    }

    SingleReplyAgent::~SingleReplyAgent() {
    }

    void SingleReplyAgent::react() {
        for (std::vector<Event>::iterator event = eventsPerceived.begin(); event != eventsPerceived.end(); event++) {
            if (event->type == Event::Type::ACTION && (event->action->getCurrentStageType() == StageType::ANTICIPATION
                                                       || event->action->getCurrentStageType() == StageType::FOLLOW_THROUGH
                                                          || event->action->hasFinished() )) {
                Emotion *emotion = availableEmotions[0];
                this->emotionalReplies.push_back({this, emotion, *event});
            }
        }
        eventsPerceived.clear();
    }

} /* namespace Divisaction */
