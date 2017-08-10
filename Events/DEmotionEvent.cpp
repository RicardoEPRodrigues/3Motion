/*
 * File EmotionEvent.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "DEmotionEvent.h"
#include "../MentalRepresentations/DOtherMentalState.h"
#include "../MentalRepresentations/DSelfMentalState.h"

using namespace std;

namespace Divisaction {

    DEmotionEvent::DEmotionEvent() : DEmotionEvent::DEmotionEvent(std::weak_ptr<DIAgent>(),
                                                                  nullptr) {}

    DEmotionEvent::DEmotionEvent(std::weak_ptr<DIAgent> sender, std::shared_ptr<DEmotion> emotion)
            : DEvent::DEvent(sender), emotion(emotion) {}

    double DEmotionEvent::timeToPerceive() {
        if (this->emotion) {
            return emotion->getStage()->getTimeToPerceive();
        }
        return 0;
    }

    void DEmotionEvent::update(DSelfMentalState& self, DOtherMentalState& state) {
        if (shared_ptr<DIAgent> replyAgent = this->emotion->getReplyAgent().lock()) {
            if (auto selfAgent = self.agent.lock()) {
                if (replyAgent == selfAgent) {
                    self.replies.push_back(shared_from_this());
                    self.updateReplies = true;
                }
            }
        } else {
            state.emotion = this->emotion;
            state.updateEmotion = true;
        }
    }
} /* namespace Divisaction */