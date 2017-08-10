/*
 * File Action.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef ACTION_H_
#define ACTION_H_

#include <vector>
#include <memory>

#include "DExecutable.h"
#include "DStage.h"
#include "DStageType.h"

namespace Divisaction {

    /**
     * @class Action
     */
    class DAction : public DExecutable {
        private:
            bool running;
            std::vector<std::shared_ptr<DStage>> stages;

            DStageType currentStageType;
        public:
            DAction();

            DAction(const DAction& other);

            ~DAction();

            void setStage(DStageType type, std::shared_ptr<DStage> stage);

            std::shared_ptr<DStage> getStage(DStageType type) const;

            std::shared_ptr<DStage> getCurrentStage() const;

            DStageType getCurrentStageType() const;

            /**
             * Executes the action.
             *
             * @return true if the action has finished all it's steps, false otherwise.
             */
            ExecutionState execute();

            void cancel();

            void reset();

            bool isRunning() const;

            bool hasFinished() const;

    };

} /* namespace Divisaction */

#endif /* ACTION_H_ */
