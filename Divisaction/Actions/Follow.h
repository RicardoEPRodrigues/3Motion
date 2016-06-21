/*
 * File Follow.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_FOLLOW_H
#define DIVISACTION_FOLLOW_H

#include "../IAgent.h"
#include "../Action.h"
#include "../Stage.h"
#include "../Stages/TimeProgressiveStage.h"

namespace Divisaction {

    class Follow : public Action {
        public:
            Follow(std::weak_ptr<IAgent> agent);
    };

} /* namespace Divisaction */

#endif //DIVISACTION_FOLLOW_H
