/*
 * File DelayPerceive.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "DDelayPerceive.h"

namespace ThreeMotion {
    void DDelayPerceive::_execute(const std::vector<std::shared_ptr<TEvent>>& events) {
        for (const auto& eventIter : events) {
            milliseconds timeToPerceive = eventIter->timeToPerceive();
            std::shared_ptr<TEvent> event = eventIter;
            wait(timeToPerceive, [this, event]() {
                if (auto mentalState = mentalStateWeak.lock()) {
                    auto eventshr = event;
                    mentalState->Update(eventshr);
                }
            });
        }
    }
} /* namespace ThreeMotion */