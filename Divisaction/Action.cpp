/*
 * File Action.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Action.h"

namespace Divisaction {

    Action::Action() {
        this->stages = vector<Stage*>(StageType::size, nullptr);
        reset();
    }

    Action::~Action() {
        for (Stage * stage : stages) {
            if (stage) {
                delete stage;
            }
        }
    }

    void Action::reset() {
        this->currentStageType = StageType::anticipation;
        this->running = false;
        for (Stage * stage : stages) {
            stage->reset();
        }
    }

    void Action::setStage(StageType type, Stage* stage) {
        this->stages[type] = stage;
    }

    Stage* Action::getStage(StageType type) {
        return stages[type];
    }

    StageType Action::getCurrentStageType() const {
        return currentStageType;
    }

    bool Action::execute() {
//        for (Stage * stage : stages)
//            if (!stage)
//                throw nullPointerExc;
        if (!running) {
            reset();
            running = true;
        }

        Stage * currentStage = getStage(currentStageType);
        if (!currentStage->hasStarted()) {
            currentStage->start();
        } else if (currentStage->isComplete()) {
            if (currentStageType == StageType::followThrough
                    || currentStageType == StageType::cancel) {
                running = false;
                return true;
            } else {
                currentStageType = static_cast<StageType>((int)currentStageType + 1);
                return execute();
            }
        }

        return false;
    }

    void Action::cancel() {
        switch (currentStageType) {
            case StageType::anticipation:
                currentStageType = StageType::cancel;
                break;
            case StageType::execution:
                // Fall through
            case StageType::followThrough:
                if (getStage(currentStageType)->interuptable) {
                    currentStageType = StageType::cancel;
                }
                break;
            default:
                break;
        }
    }

} /* namespace Divisaction */
