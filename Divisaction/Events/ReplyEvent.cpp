/*
 * File ReplyEvent.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "ReplyEvent.h"

namespace Divisaction {

    ReplyEvent::ReplyEvent() : ReplyEvent::ReplyEvent(std::weak_ptr<IAgent>(), nullptr, std::weak_ptr<IAgent>()) { }

    ReplyEvent::ReplyEvent(std::weak_ptr<class IAgent> sender, std::shared_ptr<Emotion> emotion,
                           std::weak_ptr<class IAgent> origin) : EmotionEvent::EmotionEvent(sender, emotion),
                                                                   origin(origin) { }

} /* namespace Divisaction */