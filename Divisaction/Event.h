/*
 * File Event.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef EVENT_H_
#define EVENT_H_

#include <memory>

namespace Divisaction {

    struct Event {

        std::shared_ptr<class IAgent> sender;

        // Base
        Event();

        Event(std::shared_ptr<class IAgent> sender);

        virtual ~Event();

        virtual double timeToPerceive() = 0;
    };

} /* namespace Divisaction */

#endif /* EVENT_H_ */
