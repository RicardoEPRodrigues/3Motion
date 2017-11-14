
/*
 * File DModule.h in project ThreeMotion
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_DIVISACTIONMODULE_H
#define DIVISACTION_DIVISACTIONMODULE_H

#include "TimeUtils/TTimerManager.h"
#include "TTheoryOfMind.h"
#include "IModule.h"

namespace ThreeMotion {

    template<typename T, typename U>
    class TModule : public TTimerManager, public IModule<T, U> {
        protected:
            std::weak_ptr<TTheoryOfMind> theoryOfMindWeak;

            virtual T _execute(U param) = 0;

        public:
            TModule()
                    : TTimerManager(), IModule<void, U>(),
                      theoryOfMindWeak() { };

            ~TModule() override = default;

            void Initialize(std::shared_ptr<TTheoryOfMind> const& mentalState) {
                this->theoryOfMindWeak = mentalState;
            };

            T Execute(U param) override {
                UpdateTimers();
                return _execute(param);
            }

    };

    template<typename T>
    class TModule<T, void> : public TTimerManager, public IModule<T, void> {
        protected:
            std::weak_ptr<TTheoryOfMind> theoryOfMindWeak;

            virtual T _execute() = 0;

        public:
            TModule()
                    : TTimerManager(), IModule<void, void>(),
                      theoryOfMindWeak() { };

            ~TModule() override = default;

            void Initialize(std::shared_ptr<TTheoryOfMind> const& mentalState) {
                this->theoryOfMindWeak = mentalState;
            };

            T Execute() override {
                UpdateTimers();
                return _execute();
            }
    };

    typedef TModule<void, std::vector<std::shared_ptr<TEvent>> const&> PerceiveModule;
    typedef TModule<void, void> InterpretModule;
    typedef TModule<void, std::vector<std::shared_ptr<TEvent>>&> PerformModule;

} /* namespace ThreeMotion */

#endif //DIVISACTION_DIVISACTIONMODULE_H
