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
        private:
            std::vector<std::shared_ptr<IAgent>> agents;
            std::vector<std::shared_ptr<Event>> events;

            bool playing;

            std::string description;
        public:

            WorldManager();

            virtual ~WorldManager();

            /**
             * Sets the world manager to updateAction it's agents when Update() is called
             * @note Play is enabled by default
             * @see WorldManager::updateAction()
             */
            void play();

            /**
             * Sets the world manager not to updateAction it's agents when Update() is called
             * @note Play is enabled by default
             * @see WorldManager::updateAction()
             */
            void pause();

            const std::vector<std::shared_ptr<IAgent>>& getAgents() const;

            void addAgent(std::shared_ptr<IAgent> agent);

            void update();

            const std::vector<std::shared_ptr<Event>>& getCurrentEvents() const {
                return events;
            }

            const std::string& getDescription() const {
                return description;
            }

            void setDescription(const std::string& description) {
                WorldManager::description = description;
            }
    };

} /* namespace Divisaction */

#endif /* WORLDMANAGER_H_ */
