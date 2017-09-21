/*
 * File DelayPerceive.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "DDelayPerceive.h"

namespace ThreeMotion {
    void DDelayPerceive::_execute(const std::vector<std::shared_ptr<DEvent>>& events) {
        for (auto eventIter = events.begin(); eventIter != events.end(); eventIter++) {
            double timeToPerceive = (*eventIter)->timeToPerceive();
            std::shared_ptr<DEvent> event = *eventIter;
            wait(timeToPerceive, [this, event]() {
                if (auto mentalState = mentalStateWeak.lock()) {
                    auto eventshr = event;
                    mentalState->update(eventshr);
                }
            });
        }
    }
} /* namespace ThreeMotion */