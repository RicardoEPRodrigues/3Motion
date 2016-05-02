/*
 * File Action.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Action.h"

using namespace std;

namespace Divisaction {

    Action::Action() {
        started = nullptr;
        changed = nullptr;
        finished = nullptr;

        stages = vector<Stage*>(StageType::size, nullptr);
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
        this->currentStageType = StageType::ANTICIPATION;
        this->running = false;
        for (Stage* stage : stages) {
            if (stage) {
                stage->endStage();
            }
        }
    }

    void Action::setStage(StageType type, Stage* stage) {
        this->stages[type] = stage;
    }

    Stage* Action::getStage(StageType type) const {
        return stages[type];
    }

    StageType Action::getCurrentStageType() const {
        return currentStageType;
    }

    Stage* Action::getCurrentStage() const {
        return stages[currentStageType];
    }

    bool Action::execute() {
        if (!running) {
            reset();
            running = true;
            if (started) {
                started(this);
            }
        }

        Stage * currentStage = getStage(currentStageType);
        if (!currentStage->isPlaying()) {
            currentStage->start();
        }
        currentStage->update();
        if (currentStage->isComplete()) {
            if (currentStageType == StageType::FOLLOW_THROUGH
                    || currentStageType == StageType::CANCEL) {
                running = false;
                if (finished) {
                    finished(this);
                }
                return true;
            } else {
                currentStageType = static_cast<StageType>((int) currentStageType
                        + 1);
                if (changed) {
                    changed(this, currentStageType);
                }
//                return execute();
            }
        }

        return false;
    }

    void Action::cancel() {
        switch (currentStageType) {
            case StageType::ANTICIPATION:
                currentStageType = StageType::CANCEL;
                break;
            case StageType::EXECUTION:
                // Fall through
            case StageType::FOLLOW_THROUGH:
                if (getStage(currentStageType)->isInteruptable()) {
                    currentStageType = StageType::CANCEL;
                }
                break;
            default:
                break;
        }
    }

    bool Action::isRunning() const {
        return this->running;
    }

    bool Action::hasFinished() const {
        return !running && (currentStageType == StageType::FOLLOW_THROUGH || currentStageType == StageType::CANCEL);
    }

} /* namespace Divisaction */
