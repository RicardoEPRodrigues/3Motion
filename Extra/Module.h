/*
 * File Module.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_MODULE_H
#define DIVISACTION_MODULE_H

#include <memory>

namespace ThreeMotion {

    template<typename T, typename U>
    class Module {
        public:
            Module() {}

            virtual ~Module() {}

            virtual T Execute(U param) = 0;
    };

    template<typename T>
    class Module<T, void> {
        public:
            Module() {}

            virtual ~Module() {}

            virtual T Execute() = 0;
    };
} /* namespace ThreeMotion */

#endif //DIVISACTION_MODULE_H
