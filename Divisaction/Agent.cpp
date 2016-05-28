/*
 * File Agent.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Agent.h"

using namespace std;

namespace Divisaction {

    Agent::Agent() : mentalState(make_shared<MentalState>()) { }


    void Agent::initialize() {
        mentalState->initialize(shared_from_this());
    }


    const std::shared_ptr<Executable> Agent::getCurrentExecutable() const {
        return mentalState->self.action;
    }

    void Agent::addAvailableAction(std::shared_ptr<Action> action) {
        mentalState->self.addAvailableAction(action);
    }

    void Agent::removeAvailableAction(std::shared_ptr<Action>& action) {
        mentalState->self.removeAvailableAction(action);
    }

    void Agent::addAvailableEmotion(std::shared_ptr<Emotion> emotion) {
        mentalState->self.addAvailableEmotion(emotion);
    }

    void Agent::removeAvailableEmotion(std::shared_ptr<Emotion>& emotion) {
        mentalState->self.removeAvailableEmotion(emotion);
    }

    void Agent::perceive(const vector<std::shared_ptr<Event>>& events) {
        for (auto event = eventsBeingPerceived.begin(); event != eventsBeingPerceived.end();) {
            double time = event->first - Time::delta();
            if (time <= 0) {
                this->mentalState->update(event->second);
                event = eventsBeingPerceived.erase(event);
            } else {
                event->first = time;
                ++event;
            }
        }
        for (auto event = events.begin(); event != events.end(); event++) {
            double timeToPerceive = (*event)->timeToPerceive();
            eventsBeingPerceived.push_back(std::pair<double, std::shared_ptr<Event>>(timeToPerceive, *event));
        }
    }

    void Agent::react() {
    }

    void Agent::decide() {
    }

    const vector<std::shared_ptr<Event>> Agent::perform() {
        if (mentalState->self.action) {
            if (mentalState->self.action->execute()) {
                mentalState->self.action = nullptr;
            }
        }
        if (mentalState->self.emotion) {
            if (mentalState->self.emotion->execute()) {
                mentalState->self.emotion = nullptr;
            }
        }
        // Sends the event about the action of the current agent
        vector<std::shared_ptr<Event>> responseEvents;
        responseEvents.insert(std::end(responseEvents), std::begin(mentalState->self.eventsToSend),
                              std::end(mentalState->self.eventsToSend));
        mentalState->self.eventsToSend.clear();
        // Sends eventsToSend as replies about other agents' actions
        for (auto reply = mentalState->self.emotionalReplies.begin();
             reply != mentalState->self.emotionalReplies.end();) {
            if (!reply->second) {
                responseEvents.push_back(reply->first);
                reply->second = true;
            }
            if (reply->first->emotion->execute()) {
                reply = mentalState->self.emotionalReplies.erase(reply);
            } else {
                ++reply;
            }
        }

        return responseEvents;
    }

} /* namespace Divisaction */
