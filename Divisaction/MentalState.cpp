/*
 * File MentalState.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "MentalState.h"
#include <algorithm>

namespace Divisaction {
    MentalState::~MentalState() {

    }

    void MentalState::update(std::shared_ptr<class Event>& event) {
        MentalRepresentations::iterator lb = find_if(others.begin(), others.end(),
                                                     [&event](const MentalRepresentations::value_type& stored) {
                                                         if (auto storedEvent = stored.first.lock()) {
                                                             return storedEvent == event->sender;
                                                         } else {
                                                             return false;
                                                         }
                                                     });

        if (lb == others.end()) {
            lb = others.insert(lb, MentalRepresentations::value_type(event->sender, MentalRepresentation()));
        }

        ActionEvent* actionEvent = dynamic_cast<ActionEvent*>(event.get());
        if (actionEvent) {
            lb->second.action = actionEvent->action;
            lb->second.state = actionEvent->stage;
            lb->second.update = true;
        } else {
            EmotionEvent* emotionEvent = dynamic_cast<EmotionEvent*>(event.get());
            if (emotionEvent) {
                lb->second.emotion = emotionEvent->emotion;
                lb->second.update = true;
            } else {
//                ReplyEvent* replyEvent = dynamic_cast<ReplyEvent*>(event.get());
            }
        }
    }
} /* namespace Divisaction */