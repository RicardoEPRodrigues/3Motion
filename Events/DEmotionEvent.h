/*
 * File EmotionEvent.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_EMOTIONEVENT_H
#define DIVISACTION_EMOTIONEVENT_H

#include "../DEvent.h"
#include "../DEmotion.h"

namespace ThreeMotion {

    struct DEmotionEvent : public DEvent, std::enable_shared_from_this<DEmotionEvent> {

        std::shared_ptr<DEmotion> emotion;

        DEmotionEvent();

        DEmotionEvent(std::weak_ptr<class DIAgent> sender, std::shared_ptr<DEmotion> emotion);

        virtual double timeToPerceive();

        virtual void update(class DSelfMentalState& self, class DOtherMentalState& state) override;
    };

} /* namespace ThreeMotion */

#endif //DIVISACTION_EMOTIONEVENT_H
