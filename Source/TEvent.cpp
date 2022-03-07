/*
 * File Event.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "TEvent.h"

namespace ThreeMotion {

    TEvent::TEvent() : TEvent::TEvent(std::weak_ptr<TIAgent>()) {}

    TEvent::TEvent(std::weak_ptr<TIAgent> const & sender) : sender(sender) {}

    TEvent::~TEvent() = default;
} /* namespace ThreeMotion */
