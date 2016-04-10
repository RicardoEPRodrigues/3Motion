/*
 * File Event.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef EVENT_H_
#define EVENT_H_

namespace Divisaction {

    struct Event {
        class Agent * sender;
        class Stage * stage;

        Event();
        Event(Agent* sender);
        Event(Agent* sender, Stage* stage);
    };

} /* namespace Divisaction */

#endif /* EVENT_H_ */
