/*
 * File Example1.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef EXTRA_EXAMPLES_H_
#define EXTRA_EXAMPLES_H_

#include "../WorldManager.h"
#include "../Agents/SingleActionAgent.h"
#include "../Actions/LongWalk.h"

namespace Divisaction {

    class Examples {
    private:
        Examples();
        virtual ~Examples();
    public:
        static WorldManager* example1();

    };

} /* namespace Divisaction */

#endif /* EXTRA_EXAMPLES_H_ */
