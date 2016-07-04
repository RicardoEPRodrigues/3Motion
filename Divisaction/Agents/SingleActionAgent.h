/*
 * File SingleActionAgent.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef EXAMPLES_SINGLEACTIONAGENT_H_
#define EXAMPLES_SINGLEACTIONAGENT_H_

#include "../Agent.h"
#include "../Modules/DelayPerceive.h"
#include "../Modules/SingleEmotionReact.h"
#include "../Modules/ReplyReact.h"
#include "../Modules/SingleActionDecide.h"
#include "../Modules/Perform.h"

namespace Divisaction {

    class SingleActionAgent : public Agent {
        public:
            SingleActionAgent();
    };

} /* namespace Divisaction */

#endif /* EXAMPLES_SINGLEACTIONAGENT_H_ */
