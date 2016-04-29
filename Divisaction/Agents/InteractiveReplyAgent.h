/*
 * File SingleReplyAgent.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef AGENTS_INTERACTIVEREPLYAGENT_H_
#define AGENTS_INTERACTIVEREPLYAGENT_H_

#include "../Agent.h"
#include "../Emotions/Confidence.h"

namespace Divisaction {

    class InteractiveReplyAgent : public Agent {
        public:

            InteractiveReplyAgent();

            virtual ~InteractiveReplyAgent();

            void react() override;
    };

} /* namespace Divisaction */

#endif /* AGENTS_INTERACTIVEREPLYAGENT_H_ */
