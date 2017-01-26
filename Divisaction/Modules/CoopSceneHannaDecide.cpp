/*
 * File CoopSceneHannaDecide.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "CoopSceneHannaDecide.h"

namespace Divisaction {

    CoopSceneHannaDecide::CoopSceneHannaDecide() : DecideModule(), interval(2000), timer(nullptr) {}

    void CoopSceneHannaDecide::_execute() {
//        if (mentalState->self.emotionHasName("Fear")) {
//            return; // Frozen in fear
//        }
        if (!alreadyActed) {
            if (auto mentalState = mentalStateWeak.lock()) {
                if (mentalState->self.emotionHasName("Fear")) {
                    alreadyActed = true; // Frozen in fear
                } else {
                    // Follow Bob if he's walking.
                    if (!timer) {
                        OtherMentalRepresentation* bobMentalRep;
                        if ((bobMentalRep = mentalState->getOther("Bob"))) {
                            if (bobMentalRep->actionHasName("Long Walk")) {
                                timer = wait(interval, [this]() {
                                    if (auto innerMentalState = mentalStateWeak.lock()) {
                                        innerMentalState->self.action = innerMentalState->self.getAction(
                                                "Follow");
                                        alreadyActed = true;
                                    }
                                });
                            }
                        }
                    }
                }
            }
        }
    }
} /* namespace Divisaction */