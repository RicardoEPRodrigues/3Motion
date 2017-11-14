/*
 * File EmotionEvent.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "TEmotionEvent.h"
#include "../MentalStates/TOtherMentalState.h"
#include "../MentalStates/TSelfMentalState.h"

using namespace std;

namespace ThreeMotion {

    TEmotionEvent::TEmotionEvent() : TEmotionEvent::TEmotionEvent(std::weak_ptr<TIAgent>(),
                                                                  nullptr) { }

    TEmotionEvent::TEmotionEvent(std::weak_ptr<TIAgent> sender,
                                 std::shared_ptr<TEmotion> const& emotion)
            : TEvent::TEvent(sender), emotion(emotion) { }

    milliseconds TEmotionEvent::timeToPerceive() {
        if (!this->emotion) {
            return 0;
        }
        return emotion->stage->GetTimeToPerceive();
    }

    void TEmotionEvent::update(TSelfMentalState& self, TOtherMentalState& state) {
        if (shared_ptr<TIAgent> replyAgent = this->emotion->replyToAgent.lock()) {
            if (auto selfAgent = self.agent.lock()) {
                if (replyAgent == selfAgent) {
                    self.replies.push_back(shared_from_this());
                    self.updateReplies = true;
                }
            }
        } else {
            state.emotion = this->emotion;
            state.UpdateEmotion = true;
        }
    }
} /* namespace ThreeMotion */