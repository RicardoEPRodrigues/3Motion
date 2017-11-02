/*
 * File EmotionEvent.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_EMOTIONEVENT_H
#define DIVISACTION_EMOTIONEVENT_H

#include "../TEvent.h"
#include "../TEmotion.h"

namespace ThreeMotion {

    struct TEmotionEvent : public TEvent, std::enable_shared_from_this<TEmotionEvent> {

        std::shared_ptr<TEmotion> emotion;

        TEmotionEvent();

        TEmotionEvent(std::weak_ptr<class TIAgent> sender,
                      std::shared_ptr<TEmotion> const& emotion);

        milliseconds timeToPerceive() override;

        void update(class TSelfMentalState& self, class TOtherMentalState& state) override;
    };

} /* namespace ThreeMotion */

#endif //DIVISACTION_EMOTIONEVENT_H
