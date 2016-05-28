/*
 * File SelfMentalRepresentation.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "SelfMentalRepresentation.h"

namespace Divisaction {


    void SelfMentalRepresentation::addAvailableAction(std::shared_ptr<Action> action) {
        this->availableActions.push_back(action);
    }

    void SelfMentalRepresentation::removeAvailableAction(std::shared_ptr<Action>& action) {
        auto it = std::find(availableActions.begin(), availableActions.end(), action);
        if (it != availableActions.end()) {
            availableActions.erase(it);
        }
    }

    void SelfMentalRepresentation::addAvailableEmotion(std::shared_ptr<Emotion> emotion) {
        availableEmotions.push_back(emotion);
    }

    void SelfMentalRepresentation::removeAvailableEmotion(std::shared_ptr<Emotion>& emotion) {
        auto it = std::find(availableEmotions.begin(), availableEmotions.end(), emotion);
        if (it != availableEmotions.end()) {
            availableEmotions.erase(it);
        }
    }

    void SelfMentalRepresentation::addEmotionalReply(std::shared_ptr<ReplyEvent>& replyEvent) {
        emotionalReplies.push_back(std::pair<std::shared_ptr<ReplyEvent>, bool>(replyEvent, false));
    }

    void SelfMentalRepresentation::addEvent(std::shared_ptr<Event> event) {
        eventsToSend.push_back(event);
    }
} /* namespace Divisaction */