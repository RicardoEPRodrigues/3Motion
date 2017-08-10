/*
 * File Event.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "DEvent.h"
#include "MentalRepresentations/DOtherMentalState.h"
#include "MentalRepresentations/DSelfMentalState.h"

namespace Divisaction {

    DEvent::DEvent() : DEvent::DEvent(std::weak_ptr<DIAgent>()) {}

    DEvent::DEvent(std::weak_ptr<class DIAgent> sender) : sender(sender) {}

    DEvent::~DEvent() {}

    void DEvent::update(DSelfMentalState&, DOtherMentalState&) {
        // Empty on purpose
    }
} /* namespace Divisaction */
