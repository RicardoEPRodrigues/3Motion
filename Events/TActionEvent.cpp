/*
 * File ActionEvent.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "TActionEvent.h"
#include "../MentalStates/TOtherMentalState.h"
#include "../MentalStates/TSelfMentalState.h"

namespace ThreeMotion {

    TActionEvent::TActionEvent() : TActionEvent::TActionEvent(std::weak_ptr<TIAgent>(), nullptr,
                                                          TStageType::ANTICIPATION_INTERRUPTIBLE) {}

    TActionEvent::TActionEvent(std::weak_ptr<TIAgent> sender, std::shared_ptr<TAction> action)
            : TActionEvent::TActionEvent(sender, action, action->GetCurrentStageType()) {}

    TActionEvent::TActionEvent(std::weak_ptr<TIAgent> sender, std::shared_ptr<TAction> action,
                             TStageType stage)
            : TEvent::TEvent(sender), action(action), stage(stage) {}

    milliseconds TActionEvent::timeToPerceive() {
        if (!action) {
            return 0;
        }
        return action->GetCurrentStage()->GetTimeToPerceive();
    }

    void TActionEvent::update(TSelfMentalState&, TOtherMentalState& state) {
        state.action = this->action;
        state.stage = this->stage;
        state.updateAction = true;
    }

} /* namespace ThreeMotion */