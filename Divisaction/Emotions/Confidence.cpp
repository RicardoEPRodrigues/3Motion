/*
 * File Confidence.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "Confidence.h"

namespace Divisaction {

    Confidence::Confidence() {
        this->setEmotion(new TimeProgressiveStage(std::string("show confidence"), 10, true));
    }

}
