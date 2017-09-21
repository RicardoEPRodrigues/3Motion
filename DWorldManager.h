/*
 * File WorldManager.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef WORLDMANAGER_H_
#define WORLDMANAGER_H_

#include <vector>
#include <memory>

#include "DIAgent.h"
#include "DEvent.h"

namespace ThreeMotion {

    class DWorldManager {
        public:
            std::string description;
            std::vector<std::shared_ptr<DIAgent>> agents;
            std::vector<std::shared_ptr<DEvent>> events;

            DWorldManager();

            virtual ~DWorldManager();

            void update();

            void updateEvents(const std::vector<std::shared_ptr<DEvent>>& events);

            void updateInterpret();

            void updatePerform(std::vector<std::shared_ptr<DEvent>>& events);
    };

} /* namespace ThreeMotion */

#endif /* WORLDMANAGER_H_ */
