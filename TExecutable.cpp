/*
 * File Executable.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */

#include "TExecutable.h"

namespace ThreeMotion {


    TExecutable::TExecutable() = default;

    TExecutable::TExecutable(std::string name) : name(std::move(name)) {}

    TExecutable::TExecutable(const TExecutable& other) = default;

    TExecutable::~TExecutable() = default;

    const std::string& TExecutable::getName() const {
        return name;
    }

    void TExecutable::setName(const std::string& name) {
        TExecutable::name = name;
    }
}