/*
 * File ReplyEvent.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "ReplyEvent.h"

namespace Divisaction {

    ReplyEvent::ReplyEvent() : ReplyEvent::ReplyEvent(nullptr, nullptr, nullptr) { }

    ReplyEvent::ReplyEvent(std::shared_ptr<class IAgent> sender, std::shared_ptr<Emotion> emotion,
                           std::shared_ptr<Event> reply) : EmotionEvent::EmotionEvent(sender, emotion), reply(reply) { }

} /* namespace Divisaction */