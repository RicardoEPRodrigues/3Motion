/*
 * File DelayPerceive.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "DDelayPerceive.h"

namespace ThreeMotion {
    void DDelayPerceive::_execute(
            std::vector<std::shared_ptr<TEvent>> const& events) {
        for (const auto& eventIter : events) {
            milliseconds timeToPerceive = eventIter->timeToPerceive();
            const std::shared_ptr<TEvent>& event = eventIter;
            Wait(timeToPerceive, [this, event]() {
                if (auto mentalState = theoryOfMindWeak.lock()) {
                    auto eventshr = event;
                    mentalState->Update(eventshr);
                }
            });
        }
    }
} /* namespace ThreeMotion */