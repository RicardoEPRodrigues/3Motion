/*
 * File WorldManager.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef WORLDMANAGER_H_
#define WORLDMANAGER_H_

#include <vector>
#include "Agent.h"
#include "Event.h"

namespace Divisaction {

    class WorldManager {
    private:
        std::vector<Agent*> agents;
        std::vector<Event> events;

        bool playing;
    public:

        WorldManager();
        virtual ~WorldManager();

        /**
         * Sets the world manager to update it's agents when Update() is called
         * @note Play is enabled by default
         * @see WorldManager::update()
         */
        void play();
        /**
         * Sets the world manager not to update it's agents when Update() is called
         * @note Play is enabled by default
         * @see WorldManager::update()
         */
        void pause();
        const std::vector<Agent*>& getAgents() const;
        void addAgent(Agent * agent);

        void update();

        const std::vector<Event>& getCurrentEvents() const {
            return events;
        }
    };

} /* namespace Divisaction */

#endif /* WORLDMANAGER_H_ */
