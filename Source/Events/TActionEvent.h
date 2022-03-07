/*
 * File ActionEvent.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_ACTIONEVENT_H
#define DIVISACTION_ACTIONEVENT_H

#include "../TEvent.h"
#include "../TAction.h"

namespace ThreeMotion {

    struct TActionEvent : public TEvent {

        // Action
        std::shared_ptr<TAction> action;

        TStageType stage;

        TActionEvent();

        TActionEvent(std::weak_ptr<class TIAgent> sender, std::shared_ptr<TAction> action);

        TActionEvent(std::weak_ptr<class TIAgent> sender, std::shared_ptr<TAction> action,
                     TStageType stage);

        milliseconds timeToPerceive() override;

        void update(class TSelfMentalState&, class TOtherMentalState& state) override;

    };

} /* namespace ThreeMotion */

#endif //DIVISACTION_ACTIONEVENT_H
