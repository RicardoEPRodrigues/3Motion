/*
 * File WorldManager.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef WORLDMANAGER_H_
#define WORLDMANAGER_H_

#include <vector>
#include "Agent.h"

using namespace std;

namespace Divisaction {

    class WorldManager {
    private:
        vector<Agent*> agents;

        bool playing;
    public:

        WorldManager();
        virtual ~WorldManager();

        void play();
        void pause();
        const vector<Agent*>& getAgents() const;
        void addAgent(Agent * agent);

        void update();
    };

} /* namespace Divisaction */

#endif /* WORLDMANAGER_H_ */
