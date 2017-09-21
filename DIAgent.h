/*
 * File IAgent.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_IAGENT_H
#define DIVISACTION_IAGENT_H

#include <vector>
#include <memory>
#include <string>

#include "DEvent.h"

namespace ThreeMotion {

    class DIAgent : public std::enable_shared_from_this<DIAgent> {
        public:

            virtual ~DIAgent() {}

            virtual void perceive(const std::vector<std::shared_ptr<DEvent>>& events) = 0;

            virtual void interpret() = 0;

            virtual const std::vector<std::shared_ptr<DEvent>> perform() = 0;

            std::string name;
    };

}

#endif //DIVISACTION_IAGENT_H
