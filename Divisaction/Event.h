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

    struct Event {
        enum Type {
            ACTION,
            EMOTION,
            REPLY,
            size
        };

        Type type;

        class Agent* sender;

        // Action
        class Action* action;

        Event(Type type, class Agent* sender, class Action* action);

        // Emotion
        class Emotion* emotion;

        Event(Type type, class Agent* sender, class Emotion* emotion);

        // Reply
        Event* reply;

        Event(Type type, class Agent* sender, class Emotion* emotion, Event reply);

        // Base
        Event();

        Event(Type type, class Agent* sender);

        Event(const Event &event);

        ~Event();

        Event &operator=(const Event &event);

        void CopyReply(Event &reply);
    };

} /* namespace Divisaction */

#endif /* EVENT_H_ */
