/*
 * File Agent.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef AGENT_H_
#define AGENT_H_

#include <vector>
#include <algorithm>    // std::find_if
#include <functional>

#include "Executable.h"
#include "Action.h"
#include "StageType.h"
#include "Event.h"

namespace Divisaction {

    class Agent {
    private:
        std::string name;

        Event* performedEvent;
        std::vector<Event*> eventResponses;

        static Event* generateEvent(Agent* agent, Action* action);

    protected:
        std::vector<Action*> possibleActions;

        Executable * executable;

        virtual void actionStarted(Action* action);
        virtual void actionChanged(Action* action, StageType stage);
        virtual void actionFinished(Action* action);
    public:
        Agent();
        virtual ~Agent();

        Executable* getCurrentExecutable() const;
        const std::string& getName() const;
        void setName(const std::string& name);
        void addPossibleAction(Action * action);
        void removePossibleAction(Action * action);

        void perceive(std::vector<Event> events);
        virtual void react();
        virtual void decide();
        std::vector<Event*> perform();
    };

} /* namespace Divisaction */

#endif /* AGENT_H_ */
