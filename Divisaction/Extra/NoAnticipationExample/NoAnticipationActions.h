/*
 * File ReactiveActions.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_NOANTICIPATIONACTIONS_H
#define DIVISACTION_NOANTICIPATIONACTIONS_H

#include "../../Action.h"
#include "../../IAgent.h"

namespace Divisaction {

    class ReactiveFollow : public Action {
        public:
            ReactiveFollow(std::weak_ptr<IAgent> agent);
    };

    class ReactiveLongWalk : public Action {
        public:
            ReactiveLongWalk();
    };

    class ReactiveThrowBall : public Action {
        public:
            ReactiveThrowBall();

    };

} /* namespace Divisaction */

#endif //DIVISACTION_NOANTICIPATIONACTIONS_H3
