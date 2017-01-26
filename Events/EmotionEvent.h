/*
 * File EmotionEvent.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_EMOTIONEVENT_H
#define DIVISACTION_EMOTIONEVENT_H

#include "../Event.h"
#include "../Emotion.h"

namespace Divisaction {

    struct EmotionEvent : public Event {

        std::shared_ptr<Emotion> emotion;

        EmotionEvent();

        EmotionEvent(std::weak_ptr<class IAgent> sender, std::shared_ptr<Emotion> emotion);

        virtual double timeToPerceive();
    };

} /* namespace Divisaction */

#endif //DIVISACTION_EMOTIONEVENT_H
