/*
 * File SingleEmotionReact.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "SingleEmotionReact.h"

namespace Divisaction {

    void SingleEmotionReact::_execute() {
        if (auto mentalState = mentalStateWeak.lock()) {
            if (!alreadyFelt && mentalState->self.availableEmotions.size() > 0) {
                if (mentalState->self.emotion) {
                    mentalState->self.emotion->reset();
                }

                mentalState->self.emotion = mentalState->self.availableEmotions[0];
                mentalState->self.emotion->setThrowEvents(true);
                alreadyFelt = true;
            }
        }
    }

} /* namespace Divisaction */