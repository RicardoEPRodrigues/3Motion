/*
 * File SingleReplyAgent.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef AGENTS_SINGLEREPLYAGENT_H_
#define AGENTS_SINGLEREPLYAGENT_H_

#include "../Agent.h"

namespace Divisaction {

    class SingleReplyAgent : public Agent {
        public:
            SingleReplyAgent();

            void react() override;
    };

} /* namespace Divisaction */

#endif /* AGENTS_SINGLEREPLYAGENT_H_ */
