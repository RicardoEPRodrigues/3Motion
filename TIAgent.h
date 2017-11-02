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

#include "TEvent.h"

namespace ThreeMotion {

    class TIAgent : public std::enable_shared_from_this<TIAgent> {
        public:

            virtual ~TIAgent() = default;

            virtual void perceive(std::vector<std::shared_ptr<TEvent>> const & events) = 0;

            virtual void interpret() = 0;

            virtual const std::vector<std::shared_ptr<TEvent>> perform() = 0;

            std::string name;
    };

}

#endif //DIVISACTION_IAGENT_H
