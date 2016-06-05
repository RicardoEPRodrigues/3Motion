/*
 * File Confidence.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "Confidence.h"

namespace Divisaction {

    Confidence::Confidence() {
        setName("Confidence");

        std::shared_ptr<TimeProgressiveStage> stage = std::make_shared<TimeProgressiveStage>(
                std::string("shows confidence"), 1000, true);
        stage->setTimeToPerceive(0);
        this->setStage(stage);
    }

}
