/*
 * File Happiness.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "Happiness.h"

namespace Divisaction {
    Happiness::Happiness() {
        setName("Happiness");

        setReplyText("smiles at ");

        std::shared_ptr <TimeProgressiveStage> stage = std::make_shared<TimeProgressiveStage>(
                std::string("is happy"), 1500, 2000);
        this->setStage(stage);
    }
} /* namespace Divisaction */