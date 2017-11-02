/*
 * File Event.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef EVENT_H_
#define EVENT_H_

#include <memory>
#include "TDefine.h"

namespace ThreeMotion {

    struct TEvent {

        std::weak_ptr<class TIAgent> sender;

        // Base
        TEvent();

        explicit TEvent(std::weak_ptr<class TIAgent> const& sender);

        virtual ~TEvent();

        virtual milliseconds timeToPerceive() = 0;

        virtual void update(class TSelfMentalState&, class TOtherMentalState&) { }
    };

} /* namespace ThreeMotion */

#endif /* EVENT_H_ */
