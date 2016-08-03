/*
 * File DelayPerceive.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "DelayPerceive.h"

namespace Divisaction {
    void DelayPerceive::execute(const std::vector<std::shared_ptr<Event>>& events) {
        for (auto event = eventsBeingPerceived.begin(); event != eventsBeingPerceived.end();) {
            milliseconds time = event->first - Time::delta();
            if (time <= 0) {
                if (auto mentalStatePtr = mentalStateWeak.lock()) {
                    mentalStatePtr->update(event->second);
                    event = eventsBeingPerceived.erase(event);
                }
            } else {
                event->first = time;
                ++event;
            }
        }
        for (auto event = events.begin(); event != events.end(); event++) {
            double timeToPerceive = (*event)->timeToPerceive();
            eventsBeingPerceived.push_back(std::pair<double, std::shared_ptr<Event>>(timeToPerceive, *event));
        }
    }
} /* namespace Divisaction */