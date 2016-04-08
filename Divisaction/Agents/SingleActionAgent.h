/*
 * File SingleActionAgent.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef EXAMPLES_SINGLEACTIONAGENT_H_
#define EXAMPLES_SINGLEACTIONAGENT_H_

#include "../Agent.h"

namespace Divisaction {

    class SingleActionAgent: public Agent {
    private:
        bool alreadyActed;
    public:
        SingleActionAgent();
        virtual ~SingleActionAgent();

        void perform();
    };

} /* namespace Divisaction */

#endif /* EXAMPLES_SINGLEACTIONAGENT_H_ */
