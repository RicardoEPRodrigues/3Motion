/*
 * File Agent.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef AGENT_H_
#define AGENT_H_

#include <vector>
#include "Action.h"
#include "Event.h"

namespace Divisaction {

    class Agent {
    private:
        std::string name;

    protected:
        class WorldManager* worldManager;

        std::vector<Action*> possibleActions;

        /**
         * Action chosen to be executed by the agent
         */
        Action * action;
    public:
        Agent();
        virtual ~Agent();

        void setWorldManager(class WorldManager* worldManager);

        Action* getCurrentAction() const;
        const std::string& getName() const;
        void setName(const std::string& name);
        void addPossibleAction(Action * action);
        void removePossibleAction(Action * action);

        virtual void perceive();
        virtual void react();
        virtual void decide();
        virtual Event* perform();
    };

} /* namespace Divisaction */

#endif /* AGENT_H_ */
