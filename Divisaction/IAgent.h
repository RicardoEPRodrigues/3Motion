/*
 * File IAgent.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_IAGENT_H
#define DIVISACTION_IAGENT_H

#include <vector>
#include "Event.h"

namespace Divisaction {

    class IAgent {

        public:
            virtual void perceive(std::vector<Event> &events) = 0;

            virtual void react() = 0;

            virtual void decide() = 0;

            virtual const std::vector<Event> perform() = 0;

            virtual ~IAgent() { };
    };

}

#endif //DIVISACTION_IAGENT_H
