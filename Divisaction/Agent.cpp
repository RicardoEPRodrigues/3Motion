/*
 * File Agent.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Agent.h"

using namespace std;

namespace Divisaction {

    Agent::Agent() { }

    const std::shared_ptr<Executable> Agent::getCurrentExecutable() const {
        return mentalState.self.action;
    }

    void Agent::addAvailableAction(std::shared_ptr<Action> action) {
        this->availableActions.push_back(action);
    }

    void Agent::removeAvailableAction(std::shared_ptr<Action>& action) {
        auto it = std::find(availableActions.begin(), availableActions.end(), action);
        if (it != availableActions.end()) {
            availableActions.erase(it);
        }
    }

    void Agent::addAvailableEmotion(std::shared_ptr<Emotion> emotion) {
        availableEmotions.push_back(emotion);
    }

    void Agent::removeAvailableEmotion(std::shared_ptr<Emotion>& emotion) {
        auto it = std::find(availableEmotions.begin(), availableEmotions.end(), emotion);
        if (it != availableEmotions.end()) {
            availableEmotions.erase(it);
        }
    }

    void Agent::perceive(const vector<std::shared_ptr<Event>>& events) {
        for (auto event = eventsBeingPerceived.begin(); event != eventsBeingPerceived.end();) {
            double time = event->first - Time::delta();
            if (time <= 0) {
                if (event->second->sender != shared_from_this()) {
                    this->mentalState.update(event->second);
                }
                event = eventsBeingPerceived.erase(event);
            } else {
                event->first = time;
                ++event;
            }
        }
        for (auto event = events.begin(); event != events.end(); event++) {
            double timeToPerceive = (*event)->timeToPerceive();
            if (timeToPerceive == 0) {
                timeToPerceive = 100;
            }
            eventsBeingPerceived.push_back(std::pair<double, std::shared_ptr<Event>>(timeToPerceive, *event));
        }
    }

    void Agent::react() {
    }

    void Agent::decide() {
    }

    const vector<std::shared_ptr<Event>> Agent::perform() {
        if (mentalState.self.action) {
            mentalState.self.state = mentalState.self.action->getCurrentStageType();
            if (mentalState.self.action->execute()) {
                mentalState.self.action = nullptr;
            }
        }
        if (mentalState.self.emotion) {
            if (mentalState.self.emotion->execute()) {
                mentalState.self.emotion = nullptr;
            }
        }
        // Sends the event about the action of the current agent
        vector<std::shared_ptr<Event>> responseEvents;
        responseEvents.insert(std::end(responseEvents), std::begin(events), std::end(events));
        events.clear();
        // Sends events as replies about other agents' actions
        for (auto reply = emotionalReplies.begin(); reply != emotionalReplies.end();) {
            if (!reply->second) {
                responseEvents.push_back(reply->first);
            }
            if (reply->first->emotion->execute()) {
                reply = emotionalReplies.erase(reply);
            } else {
                ++reply;
            }
        }

        return responseEvents;
    }

    void Agent::addEmotionalReply(std::shared_ptr<ReplyEvent>& replyEvent) {
        emotionalReplies.push_back(pair<shared_ptr<ReplyEvent>, bool>(replyEvent, false));
    }

    void Agent::addEvent(std::shared_ptr<Event> event) {
        events.push_back(event);
    }

    void Agent::addEvent(std::shared_ptr<Event>& event) {
        events.push_back(event);
    }

} /* namespace Divisaction */
