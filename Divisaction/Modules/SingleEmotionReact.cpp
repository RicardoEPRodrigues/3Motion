/*
 * File SingleEmotionReact.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "SingleEmotionReact.h"

namespace Divisaction {

    void SingleEmotionReact::execute() {
        if (auto mentalState = mentalStateWeak.lock()) {
            if (!alreadyFelt && !mentalState->self.emotion && mentalState->self.availableEmotions.size() > 0) {
                mentalState->self.emotion = mentalState->self.availableEmotions[0];
                alreadyFelt = true;
            }
        }
    }

} /* namespace Divisaction */