/*
 * File Executable.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */

#include "DExecutable.h"

namespace ThreeMotion {


    DExecutable::DExecutable() {}

    DExecutable::DExecutable(std::string name) : name(name) {}

    DExecutable::DExecutable(const DExecutable& other) : name(other.name) {}

    DExecutable::~DExecutable() {}

    const std::string& DExecutable::getName() const {
        return name;
    }

    void DExecutable::setName(const std::string& name) {
        DExecutable::name = name;
    }
}