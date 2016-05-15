/*
 * File EmotionEvent.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "EmotionEvent.h"

namespace Divisaction {

    EmotionEvent::EmotionEvent() : EmotionEvent::EmotionEvent(nullptr, nullptr) { }

    EmotionEvent::EmotionEvent(std::shared_ptr<class IAgent> sender, std::shared_ptr<Emotion> emotion)
            : Event::Event(sender), emotion(emotion) { }

    double EmotionEvent::timeToPerceive() {
        if (this->emotion) {
            return emotion->getEmotion()->getTimeToPerceive();
        }
        return 0;
    }

} /* namespace Divisaction */