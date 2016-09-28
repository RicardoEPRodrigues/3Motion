/*
 * File CoopSceneHanna.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_NOANTICIPATION_COOPSCENEHANNA_H
#define DIVISACTION_NOANTICIPATION_COOPSCENEHANNA_H

#include "../../../Agent.h"
#include "../../../Modules/DelayPerceive.h"
#include "../../../Modules/Perform.h"
#include "../Modules/CoopSceneHannaReact.h"
#include "../../../Modules/CoopSceneHannaDecide.h"

namespace Divisaction {

    namespace NoAnticipation {
        class CoopSceneHanna : public Agent {
            public:
                CoopSceneHanna();
        };
    }

} /* namespace Divisaction */

#endif //DIVISACTION_NOANTICIPATION_COOPSCENEHANNA_H
