/*
 * File Agent.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef AGENT_H_
#define AGENT_H_

#include <vector>
#include "Action.h"

namespace Divisaction {

    class Agent {
        class WorldManager* worldManager;

        std::vector<Action*> possibleActions;

        bool alreadyActed;

    public:
        /**
         * Action chosen to be executed by the agent
         */
        Action * action;

        Agent();
        virtual ~Agent();

        void setWorldManager(class WorldManager* worldManager);

        void addPossibleAction(Action * action);
        void removePossibleAction(Action * action);

        void perceive();
        void decide();
        void act();
    };

} /* namespace Divisaction */

#endif /* AGENT_H_ */
