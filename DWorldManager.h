/*
 * File WorldManager.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef WORLDMANAGER_H_
#define WORLDMANAGER_H_

#include <vector>
#include <memory>

#include "TIAgent.h"
#include "TEvent.h"

namespace ThreeMotion {

    class DWorldManager {
        public:
            std::string description;
            std::vector<std::shared_ptr<TIAgent>> agents;
            std::vector<std::shared_ptr<TEvent>> events;

            DWorldManager();

            virtual ~DWorldManager();

            void update();

            void updateEvents(const std::vector<std::shared_ptr<TEvent>>& events);

            void updateInterpret();

            void updatePerform(std::vector<std::shared_ptr<TEvent>>& events);
    };

} /* namespace ThreeMotion */

#endif /* WORLDMANAGER_H_ */
