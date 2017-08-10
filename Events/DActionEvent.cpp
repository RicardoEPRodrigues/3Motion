/*
 * File ActionEvent.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "DActionEvent.h"
#include "../MentalRepresentations/DOtherMentalState.h"
#include "../MentalRepresentations/DSelfMentalState.h"

namespace Divisaction {

    DActionEvent::DActionEvent() : DActionEvent::DActionEvent(std::weak_ptr<DIAgent>(), nullptr,
                                                          DStageType::ANTICIPATION_INTERRUPTIBLE) {}

    DActionEvent::DActionEvent(std::weak_ptr<DIAgent> sender, std::shared_ptr<DAction> action)
            : DActionEvent::DActionEvent(sender, action, action->getCurrentStageType()) {}

    DActionEvent::DActionEvent(std::weak_ptr<DIAgent> sender, std::shared_ptr<DAction> action,
                             DStageType stage)
            : DEvent::DEvent(sender), action(action), stage(stage) {}

    double DActionEvent::timeToPerceive() {
        if (action) {
            return action->getCurrentStage()->getTimeToPerceive();
        }
        return 0;
    }

    void DActionEvent::update(DSelfMentalState&, DOtherMentalState& state) {
        state.action = this->action;
        state.stage = this->stage;
        state.updateAction = true;
    }

} /* namespace Divisaction */