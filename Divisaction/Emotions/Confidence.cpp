/*
 * File Confidence.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "Confidence.h"

namespace Divisaction {

    Confidence::Confidence() {
        setName("Confidence");

        setReplyText("winks at ");

        std::shared_ptr<TimeProgressiveStage> stage = std::make_shared<TimeProgressiveStage>(
                std::string("shows confidence"), 1500, 2000);
        this->setStage(stage);
    }

}
