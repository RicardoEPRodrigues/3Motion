/*
 * File Event.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef EVENT_H_
#define EVENT_H_

#include <memory>

namespace ThreeMotion {

    struct DEvent {

        std::weak_ptr<class DIAgent> sender;

        // Base
        DEvent();

        DEvent(std::weak_ptr<class DIAgent> sender);

        virtual ~DEvent();

        virtual double timeToPerceive() = 0;

        virtual void update(class DSelfMentalState& self, class DOtherMentalState& state);
    };

} /* namespace ThreeMotion */

#endif /* EVENT_H_ */
