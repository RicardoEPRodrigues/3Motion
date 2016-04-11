/*
 * File Action.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef ACTION_H_
#define ACTION_H_

#include <vector>
#include <functional>

#include "Stage.h"
#include "Exceptions/NullPointerException.h"
#include "StageType.h"

namespace Divisaction {

    class Action {
    private:
        std::vector<Stage *> stages;

        StageType currentStageType;
        bool running;
    protected:
        void reset();
    public:
        // Function for updating listeners
        std::function<void(Action*)> started;
        std::function<void(Action*, StageType)> changed;
        std::function<void(Action*)> finished;

        Action();
        virtual ~Action();

        void setStage(StageType type, Stage * stage);
        Stage * getStage(StageType type) const;
        Stage * getCurrentStage() const;
        StageType getCurrentStageType() const;

        /**
         * Executes the action.
         * @return true if the action has finished all it's steps, false otherwise.
         */
        bool execute();
        void cancel();
    };

} /* namespace Divisaction */

#endif /* ACTION_H_ */
