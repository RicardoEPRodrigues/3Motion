/*
 * File SingleReplyAgent.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef AGENTS_SINGLEREPLYAGENT_H_
#define AGENTS_SINGLEREPLYAGENT_H_

#include "../Agent.h"
#include "../Modules/DelayPerceive.h"
#include "../Modules/SingleReplyReact.h"
#include "../Modules/Perform.h"

namespace Divisaction {

    class SingleReplyAgent : public Agent {
        public:
            SingleReplyAgent();
    };

} /* namespace Divisaction */

#endif /* AGENTS_SINGLEREPLYAGENT_H_ */
