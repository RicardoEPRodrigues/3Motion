/*
 * File Event.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Event.h"

namespace Divisaction {

    Event::Event() {
        sender = nullptr;
        stage = nullptr;
    }

    Event::Event(Agent* sender) :
            Event::Event() {
        this->sender = sender;
    }

    Event::Event(Agent* sender, Stage* stage) :
            Event::Event(sender) {
        this->stage = stage;
    }

} /* namespace Divisaction */
