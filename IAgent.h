/*
 * File IAgent.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_IAGENT_H
#define DIVISACTION_IAGENT_H

#include <vector>
#include <memory>

#include "Event.h"

namespace Divisaction {

    class IAgent : public std::enable_shared_from_this<IAgent> {
        public:

            virtual ~IAgent() {}

            virtual void perceive(const std::vector<std::shared_ptr<Event>>& events) = 0;

            virtual void interpret() = 0;

            virtual const std::vector<std::shared_ptr<Event>> perform() = 0;

            std::string name;
    };

}

#endif //DIVISACTION_IAGENT_H
