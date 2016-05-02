/*
 * File Agent.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Agent.h"

using namespace std;

namespace Divisaction {

    Agent::Agent() {
        executable = nullptr;
        performedEvent = nullptr;
    }

    Agent::~Agent() {
        for (Action *action : possibleActions) {
            delete action;
        }
        for (Emotion *emotion: availableEmotions) {
            delete emotion;
        }
    }

    Executable *Agent::getCurrentExecutable() const {
        return executable;
    }

    void Agent::addPossibleAction(Action *action) {
        this->possibleActions.push_back(action);
    }

    void Agent::removePossibleAction(Action *action) {
        std::vector<Action *>::iterator it = std::find(possibleActions.begin(),
                                                       possibleActions.end(), action);
        if (it != possibleActions.end()) {
            possibleActions.erase(it);
        }
    }

    void Agent::addAvailableEmotion(Emotion *emotion){
        availableEmotions.push_back(emotion);
    }

    void Agent::removeAvailableEmotion(Emotion *emotion){
        std::vector<Emotion *>::iterator it = std::find(availableEmotions.begin(),
                                                       availableEmotions.end(), emotion);
        if (it != availableEmotions.end()) {
            availableEmotions.erase(it);
        }
    }

    const std::string &Agent::getName() const {
        return name;
    }

    void Agent::setName(const std::string &name) {
        this->name = name;
    }

    void Agent::perceive(vector<Event> &events) {
        std::unordered_map<double, Event> newEventsBeingPerceived;
        for (std::pair<double, Event> event : eventsBeingPerceived) {
            double time = event.first - Time::delta();
            if (time <= 0) {
                eventsPerceived.push_back(event.second);
            } else {
                newEventsBeingPerceived.insert(std::pair<double, Event>(time, event.second));
            }
        }
        eventsBeingPerceived = newEventsBeingPerceived;
        for (vector<Event>::iterator event = events.begin(); event != events.end(); event++) {
            double timeToPerceive = 10;
            if (event->type == Event::Type::ACTION) {
                timeToPerceive = event->action->getCurrentStage()->getTimeToPerceive();
            } else {
                timeToPerceive = event->emotion->getEmotion()->getTimeToPerceive();
            }
            eventsBeingPerceived.insert(std::pair<double, Event>(timeToPerceive, *event));
        }
    }

    void Agent::react() {
    }

    void Agent::decide() {
    }

    const vector<Event> Agent::perform() {
        performedEvent = nullptr; // It may be modified if there are changes in the action that is being executed
        if (executable) {
            if (executable->execute()) {
                this->executable = nullptr;
            }
        }
        // Sends the event about the action of the current agent
        vector<Event> responseEvents;
        if (performedEvent) {
            responseEvents.push_back(*performedEvent);
            delete performedEvent;
        }
        // Sends events as replies about other agents' actions
        for (vector<EmotionalReply>::iterator reply = emotionalReplies.begin(); reply != emotionalReplies.end();) {
            if (!reply->hasGenerated) {
                responseEvents.push_back(reply->generateEvent());
            }
            if (reply->emotion->execute()) {
                reply = emotionalReplies.erase(reply);
            } else {
                ++reply;
            }
        }

        return responseEvents;
    }

    Event *Agent::generateEvent(Agent *agent, Action *action) {
        return new Event(Event::Type::ACTION, agent, action);
    }

    Event Agent::EmotionalReply::generateEvent() {
        hasGenerated = true;
        return Event(Event::Type::REPLY, sender, emotion, original);
    }

} /* namespace Divisaction */
