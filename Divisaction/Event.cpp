/*
 * File Event.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Event.h"

namespace Divisaction {

    Event::Event() {
        sender = nullptr;
        stageType = StageType::size;
        stage = nullptr;
    }

    Event::Event(class Agent* sender) :
            Event::Event() {
        this->sender = sender;
    }

    Event::Event(class Agent* sender, StageType stageType,
            class Stage* stage) :
            Event::Event(sender) {
        this->stageType = stageType;
        this->stage = stage;
    }

} /* namespace Divisaction */
