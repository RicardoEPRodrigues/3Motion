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

        std::shared_ptr<TimeProgressiveStage> stage = std::make_shared<TimeProgressiveStage>(
                std::string("shows fear"), 1000);
        stage->setTimeToPerceive(0);
        this->setStage(stage);
    }
} /* namespace Divisaction */