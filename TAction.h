/*
 * File Action.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef ACTION_H_
#define ACTION_H_

#include <vector>
#include <memory>

#include "TExecutable.h"
#include "TStage.h"
#include "TStageType.h"

namespace ThreeMotion {

    /**
     * @class Action
     */
    class TAction : public TExecutable {
        private:
            bool running;
            std::vector<std::shared_ptr<TStage>> stages;

            TStageType currentStageType;

            bool IsEndState(TStageType type);

            void NextStageType();
        public:
            TAction();

            TAction(const TAction& other);

            ~TAction() override;

            void Reset() override;

            void SetStage(TStageType type, std::shared_ptr<TStage> stage);

            std::shared_ptr<TStage> GetStage(TStageType type) const;

            std::shared_ptr<TStage> GetCurrentStage() const;

            TStageType GetCurrentStageType() const;

            /**
             * Executes the action.
             *
             * @return true if the action has finished all it's steps, false otherwise.
             */
            ExecutionState Execute() override;

            void Cancel();

            bool IsRunning() const override;

            bool HasFinished() const;

    };

} /* namespace ThreeMotion */

#endif /* ACTION_H_ */
