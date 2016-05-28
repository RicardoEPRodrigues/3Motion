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
        for (auto mentalRep = mentalState->others.begin(); mentalRep != mentalState->others.end(); ++mentalRep) {
            if (mentalRep->updateAction) {
                if (mentalRep->action
                    && (mentalRep->state == StageType::ANTICIPATION
                        || mentalRep->state == StageType::FOLLOW_THROUGH
                        || mentalRep->state == StageType::FINISHED)) {
                    if (auto origin = mentalRep->agent.lock()) {
                        auto emotion = mentalState->self.availableEmotions[0];
                        std::shared_ptr<ReplyEvent> event = std::make_shared<ReplyEvent>(shared_from_this(), emotion,
                                                                                         origin);
                        mentalState->self.addEmotionalReply(event);
                    }
                    mentalRep->updateAction = false;
                }
            }
        }
    }

} /* namespace Divisaction */
