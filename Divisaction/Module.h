/*
 * File Module.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_MODULE_H
#define DIVISACTION_MODULE_H

#include <memory>

#include "MentalState.h"

namespace Divisaction {

    template<typename T, typename U>
    class Module {
        protected:
            std::weak_ptr<MentalState> mentalStateWeak;
        public:
            Module() : mentalStateWeak(std::make_shared<MentalState>()) { }

            virtual ~Module() { }

            virtual T execute(U param) = 0;

            void initialize(std::shared_ptr<MentalState> mentalState) {
                this->mentalStateWeak = mentalState;
            };
    };

    template<typename T>
    class Module<T, void> {
        protected:
            std::weak_ptr<MentalState> mentalStateWeak;
        public:
            Module() : mentalStateWeak(std::make_shared<MentalState>()) { }

            virtual ~Module() { }

            virtual T execute() = 0;

            void initialize(std::shared_ptr<MentalState> mentalState) {
                this->mentalStateWeak = mentalState;
            }
    };

    typedef Module<void, const std::vector<std::shared_ptr<Event>>&> PerceiveModule;
    typedef Module<void, void> ReactModule;
    typedef Module<void, void> DecideModule;
    typedef Module<const std::vector<std::shared_ptr<Event>>, std::vector<std::shared_ptr<Event>>&> PerformModule;
} /* namespace Divisaction */

#endif //DIVISACTION_MODULE_H
