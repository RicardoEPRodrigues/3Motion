/*
 * File ReplyReact.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "DReplyReact.h"

namespace Divisaction {

    void DReplyReact::_execute() {
        if (auto mentalState = mentalStateWeak.lock()) {
            for (auto replyIter = mentalState->self.replies.begin();
                 replyIter != mentalState->self.replies.end(); ++replyIter) {
                auto reply = (*replyIter);
                if (reply->emotion->getName().compare("Confidence") != 0) {
                    if (mentalState->self.action) {
                        mentalState->self.action->cancel();
                    }
                }
            }
        }
    }

} /* namespace Divisaction */