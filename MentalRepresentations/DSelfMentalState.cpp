/*
 * File SelfMentalRepresentation.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "DSelfMentalState.h"

namespace ThreeMotion {


    void DSelfMentalState::addAction(std::shared_ptr<DAction> action) {
        this->availableActions.push_back(action);
    }

    void DSelfMentalState::removeAction(std::shared_ptr<DAction>& action) {
        auto it = std::find(availableActions.begin(), availableActions.end(), action);
        if (it != availableActions.end()) {
            availableActions.erase(it);
        }
    }

    std::shared_ptr<DAction> DSelfMentalState::getAction(unsigned int index) const {
        if (index >= availableActions.size()) {
            return nullptr;
        }
        return std::make_shared<DAction>(*availableActions[index].get());
    }

    std::shared_ptr<DAction> DSelfMentalState::getAction(const std::string name) const {
        if (name.empty()) {
            return nullptr;
        }
        auto actionIter = std::find_if(availableActions.begin(), availableActions.end(),
                                       [name](const std::shared_ptr<DAction> other) {
                                           return other->getName().compare(name) == 0;
                                       });
        if (actionIter == availableActions.end()) {
            return nullptr;
        }

        return std::make_shared<DAction>(*(*actionIter).get());
    }

    std::shared_ptr<DAction>
    DSelfMentalState::getAction(const std::shared_ptr<DAction> action) const {
        std::shared_pointer_values_equal<DAction> eq = {action};
        auto storedAction = find_if(availableActions.begin(), availableActions.end(), eq);
        return storedAction == availableActions.end() ? nullptr : std::make_shared<DAction>(
                *(*storedAction).get());
    }

    unsigned long DSelfMentalState::countActions() const {
        return availableActions.size();
    }

    void DSelfMentalState::addEmotion(std::shared_ptr<DEmotion> emotion) {
        availableEmotions.push_back(emotion);
    }

    void DSelfMentalState::removeEmotion(std::shared_ptr<DEmotion>& emotion) {
        auto it = std::find(availableEmotions.begin(), availableEmotions.end(), emotion);
        if (it != availableEmotions.end()) {
            availableEmotions.erase(it);
        }
    }

    std::shared_ptr<DEmotion> DSelfMentalState::getEmotion(unsigned int index) const {
        if (index >= availableEmotions.size()) {
            return nullptr;
        }
        return std::make_shared<DEmotion>(*availableEmotions[index].get());
    }

    std::shared_ptr<DEmotion> DSelfMentalState::getEmotion(const std::string name) const {
        if (name.empty()) {
            return nullptr;
        }
        auto emotionIter = std::find_if(availableEmotions.begin(), availableEmotions.end(),
                                        [name](const std::shared_ptr<DEmotion> other) -> bool {
                                            return other->getName().compare(name) == 0;
                                        });
        if (emotionIter == availableEmotions.end()) {
            return nullptr;
        }

        return std::make_shared<DEmotion>(*(*emotionIter).get());
    }

    std::shared_ptr<DEmotion>
    DSelfMentalState::getEmotion(const std::shared_ptr<DEmotion> emotion) const {
        std::shared_pointer_values_equal<DEmotion> eq = {emotion};
        auto storedEmotion = find_if(availableEmotions.begin(), availableEmotions.end(), eq);
        return storedEmotion == availableEmotions.end() ? nullptr : std::make_shared<DEmotion>(
                *(*storedEmotion).get());
    }

    unsigned long DSelfMentalState::countEmotions() const {
        return availableEmotions.size();
    }
} /* namespace ThreeMotion */
