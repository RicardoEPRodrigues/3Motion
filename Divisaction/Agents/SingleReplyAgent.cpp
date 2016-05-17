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
        for (auto mentalRep = mentalState.others.begin(); mentalRep != mentalState.others.end(); ++mentalRep) {
            if (mentalRep->second.update) {
                if (mentalRep->second.action
                    && (mentalRep->second.action->getCurrentStageType() == StageType::ANTICIPATION
                        || mentalRep->second.action->getCurrentStageType() == StageType::FOLLOW_THROUGH
                        || mentalRep->second.action->hasFinished())) {
                    if (auto origin = mentalRep->first.lock()) {
                        auto emotion = availableEmotions[0];
                        std::shared_ptr<ReplyEvent> event = std::make_shared<ReplyEvent>(shared_from_this(), emotion,
                                                                                         origin);
                        addEmotionalReply(event);
                    }
                    mentalRep->second.update = false;
                }
            }
        }
    }

} /* namespace Divisaction */
