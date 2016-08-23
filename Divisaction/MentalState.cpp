/*
 * File MentalState.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "MentalState.h"

using namespace std;

namespace Divisaction {
    MentalState::MentalState() {}

    MentalState::MentalState(weak_ptr<IAgent> selfAgent) {
        initialize(selfAgent);
    }

    MentalState::~MentalState() {

    }

    void MentalState::initialize(std::weak_ptr<IAgent> selfAgent) {
        this->self.agent = selfAgent;
    }

    void MentalState::update(std::shared_ptr<class Event>& event) {
        if (auto selfAgent = self.agent.lock()) {
            if (auto eventAgent = event->sender.lock()) {
                if (selfAgent == eventAgent) { // if the event is from this agent then ignore
                    return;
                }

                MentalRepresentations::iterator otherIter = find_if(others.begin(), others.end(),
                                                                    [&eventAgent](
                                                                            const MentalRepresentations::value_type& stored) {
                                                                        if (auto storedEventAgent = stored.agent.lock()) {
                                                                            return storedEventAgent == eventAgent;
                                                                        } else {
                                                                            return false;
                                                                        }
                                                                    });

                if (otherIter == others.end()) { // if there is no record of this event agent, create a record
                    OthersMentalRepresentation other = OthersMentalRepresentation();
                    other.agent = event->sender;
                    otherIter = others.insert(otherIter, other);
                }

                shared_ptr<ActionEvent> actionEvent = dynamic_pointer_cast<ActionEvent>(event);
                if (actionEvent) {
                    otherIter->action = actionEvent->action;
                    otherIter->state = actionEvent->stage;
                    otherIter->updateAction = true;
                } else {
                    shared_ptr<EmotionEvent> emotionEvent = dynamic_pointer_cast<EmotionEvent>(event);
                    if (emotionEvent) {
                        if (shared_ptr<IAgent> replyAgent = emotionEvent->emotion->getReplyAgent().lock()) {
                            if (replyAgent == selfAgent) {
                                self.replies.push_back(emotionEvent);
                                self.updateReplies = true;
                            }
                        } else {
                            otherIter->emotion = emotionEvent->emotion;
                            otherIter->updateEmotion = true;
                        }
                    }
                }
            }
        }
    }
} /* namespace Divisaction */
