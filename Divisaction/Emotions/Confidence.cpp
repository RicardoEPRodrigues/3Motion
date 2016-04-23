/*
 * File Confidence.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "Confidence.h"

namespace Divisaction {

    Confidence::Confidence() {
        this->emotion = new TimeProgressiveStage(std::string("Show Confidence"), 10, true);
    }

}
