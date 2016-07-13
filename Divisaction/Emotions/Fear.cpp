/*
 * File Fear.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "../Stages/TimeProgressiveStage.h"
#include "Fear.h"

namespace Divisaction {
    Fear::Fear() {
        setName("Fear");

        setReplyText("gives a terrifying look at ");

        std::shared_ptr<TimeProgressiveStage> stage = std::make_shared<TimeProgressiveStage>(
                std::string("is afraid"), 1500, 2000);
        this->setStage(stage);
    }
} /* namespace Divisaction */