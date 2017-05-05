/*
 * File SingleEmotionReact.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "SingleEmotionReact.h"

namespace Divisaction {

    void SingleEmotionReact::_execute() {
        if (auto mentalState = mentalStateWeak.lock()) {
            if (!alreadyFelt && mentalState->self.countEmotions() > 0) {
                if (mentalState->self.emotion) {
                    mentalState->self.emotion->reset();
                }

                mentalState->self.emotion = mentalState->self.getEmotion(0);
                alreadyFelt = true;
            }
        }
    }

} /* namespace Divisaction */