/*
 * File Event.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef EVENT_H_
#define EVENT_H_

#include <cstdlib>
#include <cstring>

#include "StageType.h"

namespace Divisaction {

    enum EventType {
        ACTION,
        REPLY,
        EventSize
    };

    struct Event {
        EventType type;

        class Agent *sender;

        // Action events
        StageType stageType;

        class Stage *stage;

        Event* reply;

        Event();

        Event(EventType type, class Agent *sender);

        Event(EventType type, class Agent *sender, StageType stageType,
              class Stage *stage);

        Event(EventType type, class Agent *sender, StageType stageType,
              class Stage *stage, Event reply);
    };

} /* namespace Divisaction */

#endif /* EVENT_H_ */
