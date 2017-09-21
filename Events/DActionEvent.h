/*
 * File ActionEvent.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_ACTIONEVENT_H
#define DIVISACTION_ACTIONEVENT_H

#include "../DEvent.h"
#include "../DAction.h"

namespace ThreeMotion {

    struct DActionEvent : public DEvent {

        // Action
        std::shared_ptr<DAction> action;

        DStageType stage;

        DActionEvent();

        DActionEvent(std::weak_ptr<class DIAgent> sender, std::shared_ptr<DAction> action);

        DActionEvent(std::weak_ptr<class DIAgent> sender, std::shared_ptr<DAction> action,
                     DStageType stage);

        virtual double timeToPerceive();

        virtual void update(class DSelfMentalState&, class DOtherMentalState& state) override;

    };

} /* namespace ThreeMotion */

#endif //DIVISACTION_ACTIONEVENT_H
