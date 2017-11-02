/*
 * File SelfMentalRepresentation.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "TSelfMentalState.h"

namespace ThreeMotion {


    void TSelfMentalState::addAction(std::shared_ptr<TAction> const & action) {
        this->availableActions.push_back(action);
    }

    void TSelfMentalState::removeAction(std::shared_ptr<TAction> const & action) {
        auto it = std::find(availableActions.begin(), availableActions.end(), action);
        if (it != availableActions.end()) {
            availableActions.erase(it);
        }
    }

    std::shared_ptr<TAction> TSelfMentalState::getAction(unsigned int index) const {
        if (index >= availableActions.size()) {
            return nullptr;
        }
        return std::make_shared<TAction>(*availableActions[index].get());
    }

    std::shared_ptr<TAction> TSelfMentalState::getAction(std::string const& name) const {
        if (name.empty()) {
            return nullptr;
        }
        auto actionIter = std::find_if(availableActions.begin(), availableActions.end(),
                                       [name](const std::shared_ptr<TAction> other) {
                                           return other->getName() == name;
                                       });
        if (actionIter == availableActions.end()) {
            return nullptr;
        }

        return std::make_shared<TAction>(*(*actionIter).get());
    }

    std::shared_ptr<TAction>
    TSelfMentalState::getAction(const std::shared_ptr<TAction>& action) const {
        std::shared_pointer_values_equal<TAction> eq = {action};
        auto storedAction = find_if(availableActions.begin(), availableActions.end(), eq);
        return storedAction == availableActions.end() ? nullptr : std::make_shared<TAction>(
                *(*storedAction).get());
    }

    unsigned long TSelfMentalState::countActions() const {
        return availableActions.size();
    }

    void TSelfMentalState::addEmotion(std::shared_ptr<TEmotion> const & emotion) {
        availableEmotions.push_back(emotion);
    }

    void TSelfMentalState::removeEmotion(std::shared_ptr<TEmotion> const & emotion) {
        auto it = std::find(availableEmotions.begin(), availableEmotions.end(), emotion);
        if (it != availableEmotions.end()) {
            availableEmotions.erase(it);
        }
    }

    std::shared_ptr<TEmotion> TSelfMentalState::getEmotion(unsigned int index) const {
        if (index >= availableEmotions.size()) {
            return nullptr;
        }
        return std::make_shared<TEmotion>(*availableEmotions[index].get());
    }

    std::shared_ptr<TEmotion> TSelfMentalState::getEmotion(const std::string& name) const {
        if (name.empty()) {
            return nullptr;
        }
        auto emotionIter = std::find_if(availableEmotions.begin(), availableEmotions.end(),
                                        [name](const std::shared_ptr<TEmotion> other) -> bool {
                                            return other->getName().compare(name) == 0;
                                        });
        if (emotionIter == availableEmotions.end()) {
            return nullptr;
        }

        return std::make_shared<TEmotion>(*(*emotionIter).get());
    }

    std::shared_ptr<TEmotion>
    TSelfMentalState::getEmotion(const std::shared_ptr<TEmotion>& emotion) const {
        std::shared_pointer_values_equal<TEmotion> eq = {emotion};
        auto storedEmotion = find_if(availableEmotions.begin(), availableEmotions.end(), eq);
        return storedEmotion == availableEmotions.end() ? nullptr : std::make_shared<TEmotion>(
                *(*storedEmotion).get());
    }

    unsigned long TSelfMentalState::countEmotions() const {
        return availableEmotions.size();
    }
} /* namespace ThreeMotion */
