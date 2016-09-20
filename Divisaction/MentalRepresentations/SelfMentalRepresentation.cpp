/*
 * File SelfMentalRepresentation.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "SelfMentalRepresentation.h"

namespace Divisaction {


    void SelfMentalRepresentation::addAction(std::shared_ptr<Action> action) {
        this->availableActions.push_back(action);
    }

    void SelfMentalRepresentation::removeAction(std::shared_ptr<Action>& action) {
        auto it = std::find(availableActions.begin(), availableActions.end(), action);
        if (it != availableActions.end()) {
            availableActions.erase(it);
        }
    }

    std::shared_ptr<Action> SelfMentalRepresentation::getAction(unsigned int index) const {
        if (index >= availableActions.size()) {
            return nullptr;
        }
        return std::make_shared<Action>(*availableActions[index].get());
    }

    std::shared_ptr<Action> SelfMentalRepresentation::getAction(const std::string name) const {
        if (name.empty()) {
            return nullptr;
        }
        auto actionIter = std::find_if(availableActions.begin(), availableActions.end(),
                                        [name](const std::shared_ptr<Action> other) {
                                            return other->getName().compare(name) == 0;
                                        });
        if (actionIter == availableActions.end()) {
            return nullptr;
        }

        return std::make_shared<Action>(*(*actionIter).get());
    }

    std::shared_ptr<Action> SelfMentalRepresentation::getAction(const std::shared_ptr<Action> action) const {
        std::shared_pointer_values_equal<Action> eq = {action};
        auto storedAction = find_if(availableActions.begin(), availableActions.end(), eq);
        return storedAction == availableActions.end() ? nullptr : std::make_shared<Action>(*(*storedAction).get());
    }

    unsigned long SelfMentalRepresentation::countActions() const {
        return availableActions.size();
    }

    void SelfMentalRepresentation::addEmotion(std::shared_ptr<Emotion> emotion) {
        availableEmotions.push_back(emotion);
    }

    void SelfMentalRepresentation::removeEmotion(std::shared_ptr<Emotion>& emotion) {
        auto it = std::find(availableEmotions.begin(), availableEmotions.end(), emotion);
        if (it != availableEmotions.end()) {
            availableEmotions.erase(it);
        }
    }

    std::shared_ptr<Emotion> SelfMentalRepresentation::getEmotion(unsigned int index) const {
        if (index >= availableEmotions.size()) {
            return nullptr;
        }
        return std::make_shared<Emotion>(*availableEmotions[index].get());
    }

    std::shared_ptr<Emotion> SelfMentalRepresentation::getEmotion(const std::string name) const {
        if (name.empty()) {
            return nullptr;
        }
        auto emotionIter = std::find_if(availableEmotions.begin(), availableEmotions.end(),
                                    [name](const std::shared_ptr<Emotion> other) {
                                        return other->getName().compare(name) == 0;
                                    });
        if (emotionIter == availableEmotions.end()) {
            return nullptr;
        }

        return std::make_shared<Emotion>(*(*emotionIter).get());
    }

    std::shared_ptr<Emotion> SelfMentalRepresentation::getEmotion(const std::shared_ptr<Emotion> emotion) const {
        std::shared_pointer_values_equal<Emotion> eq = {emotion};
        auto storedEmotion = find_if(availableEmotions.begin(), availableEmotions.end(), eq);
        return storedEmotion == availableEmotions.end() ? nullptr : std::make_shared<Emotion>(*(*storedEmotion).get());
    }

    unsigned long SelfMentalRepresentation::countEmotions() const {
        return availableEmotions.size();
    }
} /* namespace Divisaction */
