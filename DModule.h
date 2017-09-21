
/*
 * File DModule.h in project ThreeMotion
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_DIVISACTIONMODULE_H
#define DIVISACTION_DIVISACTIONMODULE_H

#include "TimeUtils/DTimerManager.h"
#include "DTheoryOfMind.h"
#include "Extra/Module.h"

namespace ThreeMotion {

    template<typename T, typename U>
    class DModule : public DTimerManager, public Module<T, U> {
        public:
            DModule() : mentalStateWeak(std::make_shared<DTheoryOfMind>()) {};

            virtual ~DModule() {};

            void initialize(std::shared_ptr<DTheoryOfMind> mentalState) {
                this->mentalStateWeak = mentalState;
            };

            T execute(U param) override {
                timersUpdate();
                return _execute(param);
            }

        protected:
            std::weak_ptr<DTheoryOfMind> mentalStateWeak;

            virtual T _execute(U param) = 0;
    };

    template<typename T>
    class DModule<T, void> : public DTimerManager, public Module<T, void> {
        public:
            DModule() : mentalStateWeak(std::make_shared<DTheoryOfMind>()) {};

            virtual ~DModule() {};

            void initialize(std::shared_ptr<DTheoryOfMind> mentalState) {
                this->mentalStateWeak = mentalState;
            };

            T execute() override {
                timersUpdate();
                return _execute();
            }

        protected:
            std::weak_ptr<DTheoryOfMind> mentalStateWeak;

            virtual T _execute() = 0;
    };

    typedef DModule<void, const std::vector<std::shared_ptr<DEvent>>&> PerceiveModule;
    typedef DModule<void, void> InterpretModule;
    typedef DModule<void, std::vector<std::shared_ptr<DEvent>>&> PerformModule;

} /* namespace ThreeMotion */

#endif //DIVISACTION_DIVISACTIONMODULE_H
