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

    std::shared_ptr<Action> SelfMentalRepresentation::getAction(const std::shared_ptr<Action> action) const {
        std::shared_pointer_values_equal<Action> eq = {action};
        auto storedAction = find_if(availableActions.begin(), availableActions.end(), eq);
        return storedAction == availableActions.end() ? nullptr : *storedAction;
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

    std::shared_ptr<Emotion> SelfMentalRepresentation::getEmotion(const std::shared_ptr<Emotion> emotion) const {
        std::shared_pointer_values_equal<Emotion> eq = {emotion};
        auto storedEmotion = find_if(availableEmotions.begin(), availableEmotions.end(), eq);
        return storedEmotion == availableEmotions.end() ? nullptr : *storedEmotion;
    }

    void SelfMentalRepresentation::addEmotionalReply(std::shared_ptr<ReplyEvent>& replyEvent) {
        emotionalReplies.push_back(replyEvent);
    }

    void SelfMentalRepresentation::addEvent(std::shared_ptr<Event> event) {
        eventsToSend.push_back(event);
    }
} /* namespace Divisaction */