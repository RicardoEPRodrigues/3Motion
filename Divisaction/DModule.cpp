/*
 * File DivisactionModule.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "DModule.h"

namespace Divisaction {

    DModule::DModule() : mentalStateWeak(std::make_shared<MentalState>()) {}

    DModule::~DModule() {}

    void DModule::initialize(std::shared_ptr<MentalState> mentalState) {
        this->mentalStateWeak = mentalState;
    }

} /* namespace Divisaction */