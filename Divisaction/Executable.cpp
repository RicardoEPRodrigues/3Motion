/*
 * File Executable.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */

#include "Executable.h"

namespace Divisaction {


    Executable::Executable() {}

    Executable::Executable(std::string name) : name(name) {}

    Executable::Executable(const Executable& other) : name(other.name) {}

    Executable::~Executable() {}

    const std::string& Executable::getName() const {
        return name;
    }

    void Executable::setName(const std::string& name) {
        Executable::name = name;
    }
}