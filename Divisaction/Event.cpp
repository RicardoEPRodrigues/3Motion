/*
 * File Event.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Event.h"

namespace Divisaction {

    Event::Event() : Event::Event(std::weak_ptr<IAgent>()) { }

    Event::Event(std::weak_ptr<class IAgent> sender) : sender(sender) { }

    Event::~Event() { }

} /* namespace Divisaction */
