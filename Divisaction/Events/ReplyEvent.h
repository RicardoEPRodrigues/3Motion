/*
 * File ReplyEvent.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_REPLYEVENT_H
#define DIVISACTION_REPLYEVENT_H

#include <cstdlib>
#include <cstring>
#include <memory>

#include "../Event.h"
#include "EmotionEvent.h"

namespace Divisaction {

    struct ReplyEvent : public EmotionEvent {
        std::shared_ptr<Event> reply;

        ReplyEvent();

        ReplyEvent(std::shared_ptr<class IAgent> sender, std::shared_ptr<Emotion> emotion,
                   std::shared_ptr<Event> reply);
    };

} /* namespace Divisaction */

#endif //DIVISACTION_REPLYEVENT_H
