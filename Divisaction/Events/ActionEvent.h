/*
 * File ActionEvent.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_ACTIONEVENT_H
#define DIVISACTION_ACTIONEVENT_H

#include "../Event.h"
#include "../Action.h"

namespace Divisaction {

    struct ActionEvent : public Event {

        // Action
        std::shared_ptr<Action> action;

        StageType stage;

        ActionEvent();

        ActionEvent(std::shared_ptr<class IAgent> sender, std::shared_ptr<Action> action);

        ActionEvent(std::shared_ptr<class IAgent> sender, std::shared_ptr<Action> action, StageType stage);

        virtual double timeToPerceive();

    };

} /* namespace Divisaction */

#endif //DIVISACTION_ACTIONEVENT_H
