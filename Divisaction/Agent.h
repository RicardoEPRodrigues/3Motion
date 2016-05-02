/*
 * File Agent.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef AGENT_H_
#define AGENT_H_

#include "IAgent.h"

#include <vector>
#include <algorithm>    // std::find_if
#include <functional>
#include <unordered_map>

#include "Executable.h"
#include "Action.h"
#include "StageType.h"
#include "Event.h"
#include "Time.h"
#include "Emotion.h"

namespace Divisaction {

    class Agent : public IAgent {
        private:
            std::string name;

            std::unordered_map<double, Event> eventsBeingPerceived;
        protected:

            struct EmotionalReply {
                Agent *sender;
                Emotion *emotion;
                Event original;

                bool hasGenerated = false;

                Event generateEvent();
            };

            std::vector<Action *> possibleActions;
            std::vector<Emotion *> availableEmotions;

            std::vector<Event> eventsPerceived;

            std::vector<EmotionalReply> emotionalReplies;

            Executable *executable;
            Event *performedEvent;

            static Event *generateEvent(Agent *agent, Action *action);

        public:
            Agent();

            virtual ~Agent();

            Executable *getCurrentExecutable() const;

            const std::string &getName() const;

            void setName(const std::string &name);

            virtual void addPossibleAction(Action *action);

            virtual void removePossibleAction(Action *action);

            virtual void addAvailableEmotion(Emotion *emotion);

            virtual void removeAvailableEmotion(Emotion *emotion);

            void perceive(std::vector<Event> &events);

            virtual void react();

            virtual void decide();

            const std::vector<Event> perform();
    };

} /* namespace Divisaction */

#endif /* AGENT_H_ */
