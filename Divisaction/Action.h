/*
 * File Action.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef ACTION_H_
#define ACTION_H_

#include <vector>
#include "Stage.h"
#include "Exceptions/NullPointerException.h"

namespace Divisaction {

    enum StageType { anticipation, execution, followThrough, cancel, size };

    class Action {
    private:
        std::vector<Stage *> stages;

        StageType currentStageType;
        bool running;

    protected:
        void reset();
    public:

        Action();
        virtual ~Action();

        void setStage(StageType type, Stage * stage);
        Stage * getStage(StageType type);
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
