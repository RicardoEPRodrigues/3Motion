/*
 * File Module.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_MODULE_H
#define DIVISACTION_MODULE_H

#include <memory>

#include "MentalState.h"
#include "DivisactionModule.h"

namespace Divisaction {

    template<typename T, typename U>
    class Module : public DivisactionModule {
        public:
            Module() : DivisactionModule() {}

            virtual ~Module() {}

            T execute(U param) {
                timersUpdate();
                return _execute(param);
            }

        protected:
            virtual T _execute(U param) = 0;
    };

    template<typename T>
    class Module<T, void> : public DivisactionModule {
        public:
            Module() : DivisactionModule() {}

            virtual ~Module() {}

            T execute() {
                timersUpdate();
                return _execute();
            }

        protected:
            virtual T _execute() = 0;
    };

    typedef Module<void, const std::vector<std::shared_ptr<Event>>&> PerceiveModule;
    typedef Module<void, void> ReactModule;
    typedef Module<void, void> DecideModule;
    typedef Module<void, std::vector<std::shared_ptr<Event>>&> PerformModule;
} /* namespace Divisaction */

#endif //DIVISACTION_MODULE_H
