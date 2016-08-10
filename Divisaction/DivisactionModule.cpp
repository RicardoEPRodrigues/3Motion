/*
 * File DivisactionModule.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "DivisactionModule.h"

namespace Divisaction {

    DivisactionModule::DivisactionModule() : mentalStateWeak(std::make_shared<MentalState>()) {}

    DivisactionModule::~DivisactionModule() {}

    void DivisactionModule::initialize(std::shared_ptr<MentalState> mentalState) {
        this->mentalStateWeak = mentalState;
    }

    bool DivisactionModule::selfInActionStage(std::shared_ptr<MentalState>& mentalState, StageType stageType) const {
        return mentalState->self.action && mentalState->self.action->getCurrentStageType() == stageType;
    }

    bool DivisactionModule::otherHasName(std::shared_ptr<IAgent>& otherAgent, std::string name) const {
        return otherAgent->getName().compare(name) == 0;
    }

    bool DivisactionModule::otherInActionStage(OthersMentalRepresentation& other,
                                               StageType stageType) const {
        return other.action && other.state == stageType;
    }

} /* namespace Divisaction */