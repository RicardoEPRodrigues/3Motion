/*
 * File DelayPerceive.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "DelayPerceive.h"

namespace Divisaction {
    void DelayPerceive::_execute(const std::vector<std::shared_ptr<Event>>& events) {
        for (auto eventIter = events.begin(); eventIter != events.end(); eventIter++) {
            double timeToPerceive = (*eventIter)->timeToPerceive();
            std::shared_ptr<Event> event = *eventIter;
            wait(timeToPerceive, [this, event]() {
                if (auto mentalState = mentalStateWeak.lock()) {
                    auto eventshr = event;
                    mentalState->update(eventshr);
                }
            });
        }
    }
} /* namespace Divisaction */