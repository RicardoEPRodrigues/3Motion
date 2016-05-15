/*
 * File ActionEvent.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "ActionEvent.h"

namespace Divisaction {

    ActionEvent::ActionEvent() : ActionEvent::ActionEvent(nullptr, nullptr) { }

    ActionEvent::ActionEvent(std::shared_ptr<class IAgent> sender, std::shared_ptr<Action> action)
            : Event::Event(sender), action(action) { }

    double ActionEvent::timeToPerceive() {
        if (action) {
            return action->getCurrentStage()->getTimeToPerceive();
        }
        return 0;
    }

} /* namespace Divisaction */