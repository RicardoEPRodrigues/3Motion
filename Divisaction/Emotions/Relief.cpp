/*
 * File Relief.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "Relief.h"

namespace Divisaction {

    Relief::Relief() {
        setName("Relief");

        std::shared_ptr<TimeProgressiveStage> stage = std::make_shared<TimeProgressiveStage>(
                std::string("is relieved"), 1500, 2000);
        this->setStage(stage);
    }

} /* namespace Divisaction */