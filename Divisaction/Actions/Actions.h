/*
 * File Actions.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_ACTIONS_H
#define DIVISACTION_ACTIONS_H

#include "../Action.h"
#include "../IAgent.h"

namespace Divisaction {
    class Follow : public Action {
        public:
            Follow(std::weak_ptr<IAgent> agent);
    };
    class LongWalk : public Action {
        public:
            LongWalk();
    };
    class ThrowBall : public Action {
        public:
            ThrowBall();

    };

} /* namespace Divisaction */

#endif //DIVISACTION_ACTIONS_H
