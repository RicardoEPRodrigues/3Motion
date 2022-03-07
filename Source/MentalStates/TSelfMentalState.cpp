/*
 * File SelfMentalRepresentation.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "TSelfMentalState.h"

namespace ThreeMotion {


    void TSelfMentalState::AddAction(std::shared_ptr<TAction> const& action) {
        this->availableActions.push_back(action);
    }

    void TSelfMentalState::RemoveAction(std::shared_ptr<TAction> const& action) {
        auto it = std::find(availableActions.begin(), availableActions.end(), action);
        if (it != availableActions.end()) {
            availableActions.erase(it);
        }
    }

    std::shared_ptr<TAction> TSelfMentalState::GetAction(unsigned int index) const {
        if (index >= availableActions.size()) {
            return nullptr;
        }
        return std::make_shared<TAction>(*availableActions[index].get());
    }

    std::shared_ptr<TAction> TSelfMentalState::GetAction(
            std::string const& name) const {
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
    TSelfMentalState::GetAction(const std::shared_ptr<TAction>& action) const {
        std::shared_pointer_values_equal<TAction> eq = {action};
        auto storedAction = find_if(availableActions.begin(), availableActions.end(), eq);
        return storedAction == availableActions.end() ? nullptr : std::make_shared<TAction>(
                *(*storedAction).get());
    }

    unsigned long TSelfMentalState::CountActions() const {
        return static_cast<unsigned long>(availableActions.size());
    }

    void TSelfMentalState::AddEmotion(std::shared_ptr<TEmotion> const& emotion) {
        availableEmotions.push_back(emotion);
    }

    void TSelfMentalState::RemoveEmotion(
            std::shared_ptr<TEmotion> const& emotion) {
        auto it = std::find(availableEmotions.begin(), availableEmotions.end(), emotion);
        if (it != availableEmotions.end()) {
            availableEmotions.erase(it);
        }
    }

    std::shared_ptr<TEmotion> TSelfMentalState::GetEmotion(unsigned int index) const {
        if (index >= availableEmotions.size()) {
            return nullptr;
        }
        return std::make_shared<TEmotion>(*availableEmotions[index].get());
    }

    std::shared_ptr<TEmotion> TSelfMentalState::GetEmotion(
            const std::string& name) const {
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
    TSelfMentalState::GetEmotion(const std::shared_ptr<TEmotion>& emotion) const {
        std::shared_pointer_values_equal<TEmotion> eq = {emotion};
        auto storedEmotion = find_if(availableEmotions.begin(), availableEmotions.end(), eq);
        return storedEmotion == availableEmotions.end() ? nullptr : std::make_shared<TEmotion>(
                *(*storedEmotion).get());
    }

    unsigned long TSelfMentalState::CountEmotions() const {
        return availableEmotions.size();
    }
} /* namespace ThreeMotion */
