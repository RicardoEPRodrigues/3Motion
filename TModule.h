
/*
 * File DModule.h in project ThreeMotion
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_DIVISACTIONMODULE_H
#define DIVISACTION_DIVISACTIONMODULE_H

#include "TimeUtils/DTimerManager.h"
#include "TTheoryOfMind.h"
#include "Extra/Module.h"

namespace ThreeMotion {

    template<typename T, typename U>
    class TModule : public DTimerManager, public Module<T, U> {
        protected:
            std::weak_ptr<TTheoryOfMind> mentalStateWeak;

            virtual T _execute(U param) = 0;

        public:
            TModule() : mentalStateWeak(std::make_shared<TTheoryOfMind>()) {};

            ~TModule() override = default;

            void Initialize(std::shared_ptr<TTheoryOfMind> mentalState) {
                this->mentalStateWeak = mentalState;
            };

            T Execute(U param) override {
                timersUpdate();
                return _execute(param);
            }

    };

    template<typename T>
    class TModule<T, void> : public DTimerManager, public Module<T, void> {
        protected:
            std::weak_ptr<TTheoryOfMind> mentalStateWeak;

            virtual T _execute() = 0;
        public:
            TModule() : mentalStateWeak(std::make_shared<TTheoryOfMind>()) {};

            ~TModule() override = default;

            void Initialize(std::shared_ptr<TTheoryOfMind> mentalState) {
                this->mentalStateWeak = mentalState;
            };

            T Execute() override {
                timersUpdate();
                return _execute();
            }

    };

    typedef TModule<void, const std::vector<std::shared_ptr<TEvent>>&> PerceiveModule;
    typedef TModule<void, void> InterpretModule;
    typedef TModule<void, std::vector<std::shared_ptr<TEvent>>&> PerformModule;

} /* namespace ThreeMotion */

#endif //DIVISACTION_DIVISACTIONMODULE_H
