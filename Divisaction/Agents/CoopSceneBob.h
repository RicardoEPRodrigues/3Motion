/*
 * File CoopSceneBob.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_COOPSCENEBOB_H
#define DIVISACTION_COOPSCENEBOB_H

#include "../Agent.h"
#include "../Modules/DelayPerceive.h"
#include "../Modules/Perform.h"
#include "../Modules/CoopSceneBobReact.h"
#include "../Modules/CoopSceneBobDecide.h"

namespace Divisaction {

    class CoopSceneBob : public Agent {
        public:
            CoopSceneBob();
    };

} /* namespace Divisaction */

#endif //DIVISACTION_COOPSCENEBOB_H
