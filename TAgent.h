/*
 * File Agent.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */

#ifndef AGENT_H_
#define AGENT_H_

#include "TIAgent.h"

#include <vector>
#include <algorithm>    // std::find_if

#include "TAction.h"
#include "TEvent.h"
#include "TEmotion.h"
#include "Events/TActionEvent.h"
#include "TTheoryOfMind.h"
#include "TModule.h"

namespace ThreeMotion {

    class TAgent : public TIAgent {
        public:
            std::shared_ptr<TTheoryOfMind> theoryOfMind;

            std::vector<std::unique_ptr<PerceiveModule>> perceiveModules;
            std::vector<std::unique_ptr<InterpretModule>> interpretModules;
            std::vector<std::unique_ptr<PerformModule>> performModules;

            TAgent();

            ~TAgent() override;

            virtual void
            AddAvailableAction(std::shared_ptr<TAction> const& action);

            virtual void
            RemoveAvailableAction(std::shared_ptr<TAction> const& action);

            virtual void
            AddAvailableEmotion(std::shared_ptr<TEmotion> const& emotion);

            virtual void
            RemoveAvailableEmotion(std::shared_ptr<TEmotion> const& emotion);

            void Initialize() override;

            void Perceive(
                    const std::vector<std::shared_ptr<TEvent>>& events) override;

            void Interpret() override;

            const std::vector<std::shared_ptr<TEvent>> Perform() override;
    };

} /* namespace ThreeMotion */

#endif /* AGENT_H_ */
