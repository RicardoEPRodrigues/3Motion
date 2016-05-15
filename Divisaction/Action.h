/*
 * File Action.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef ACTION_H_
#define ACTION_H_

#include <vector>
#include <functional>
#include <memory>

#include "Executable.h"
#include "Stage.h"
#include "Exceptions/NullPointerException.h"
#include "StageType.h"

namespace Divisaction {

    class Action : public Executable {
        private:
            bool running;
            std::vector<std::shared_ptr<Stage>> stages;

            StageType currentStageType;
        protected:
        public:
            // Function for updating listeners
            std::function<void()> started;
            std::function<void(StageType)> changed;
            std::function<void()> finished;

            Action();

            void setStage(StageType type, std::shared_ptr<Stage> stage);

            std::shared_ptr<Stage> getStage(StageType type) const;

            std::shared_ptr<Stage> getCurrentStage() const;

            StageType getCurrentStageType() const;

            /**
             * Executes the action.
             * @return true if the action has finished all it's steps, false otherwise.
             */
            bool execute();

            void cancel();

            void reset();

            bool isRunning() const;
            bool hasFinished() const;
    };

} /* namespace Divisaction */

#endif /* ACTION_H_ */
