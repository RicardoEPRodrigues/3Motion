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
        protected:
            std::string name;

        public:
            virtual ~IAgent() { }

            virtual void perceive(const std::vector<std::shared_ptr<Event>>& events) = 0;

            virtual void react() = 0;

            virtual void decide() = 0;

            virtual const std::vector<std::shared_ptr<Event>> perform() = 0;

            virtual void initialize() { }

            const std::string& getName() const {
                return name;
            }

            void setName(const std::string& name) {
                this->name = name;
            }
    };

}

#endif //DIVISACTION_IAGENT_H
