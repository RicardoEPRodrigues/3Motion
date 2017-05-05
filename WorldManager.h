/*
 * File WorldManager.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef WORLDMANAGER_H_
#define WORLDMANAGER_H_

#include <vector>
#include <memory>

#include "IAgent.h"
#include "Event.h"

namespace Divisaction {

    class WorldManager {
        public:
            std::string description;
            std::vector<std::shared_ptr<IAgent>> agents;
            std::vector<std::shared_ptr<Event>> events;

            WorldManager();

            virtual ~WorldManager();

            void update();

            void updateEvents(const std::vector<std::shared_ptr<Event>>& events);

            void updateInterpret();

            void updatePerform(std::vector<std::shared_ptr<Event>>& events);
    };

} /* namespace Divisaction */

#endif /* WORLDMANAGER_H_ */
