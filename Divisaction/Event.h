/*
 * File Event.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef EVENT_H_
#define EVENT_H_

#include "StageType.h"

namespace Divisaction {

    struct Event {
        class Agent * sender;

        // Action events
        StageType stageType;
        class Stage * stage;

        Event();
        Event(class Agent* sender);
        Event(class Agent* sender, StageType stageType,
                class Stage* stage);
    };

} /* namespace Divisaction */

#endif /* EVENT_H_ */
