/*
 * File Action.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Action.h"

using namespace std;

namespace Divisaction {

    Action::Action() {
        stages = vector<std::shared_ptr<Stage>>(StageType::size, nullptr);
        reset();
    }

    Action::Action(const Action& other) : Executable(other), running(other.running),
                                          currentStageType(other.currentStageType) {
        stages = vector<std::shared_ptr<Stage>>(StageType::size, nullptr);
        for (unsigned int stageType = 0; stageType < other.stages.size(); ++stageType) {
            if (other.stages[stageType]) {
                stages[stageType] = other.stages[stageType]->clone();
            }
        }
    }

    Action::~Action() {}

    void Action::reset() {
        this->currentStageType = StageType::ANTICIPATION_INTERRUPTIBLE;
        this->running = false;
        for (auto stage : stages) {
            if (stage) {
                stage->reset();
            }
        }
    }

    void Action::setStage(StageType type, std::shared_ptr<Stage> stage) {
        this->stages[type] = stage;
    }

    std::shared_ptr<Stage> Action::getStage(StageType type) const {
        return stages[type];
    }

    StageType Action::getCurrentStageType() const {
        return currentStageType;
    }

    std::shared_ptr<Stage> Action::getCurrentStage() const {
        return stages[currentStageType];
    }

    /**
     * Executes the action.
     * @return true if the action has finished all it's steps, false otherwise.
     */
    Executable::ExecutionState Action::execute() {
        ExecutionState state = ExecutionState::RUNNING;
        if (!running) {
            reset();
            running = true;
        }

        std::shared_ptr<Stage> currentStage = getStage(currentStageType);
        if (!currentStage) {
            do {
                currentStageType = static_cast<StageType>((int) currentStageType + 1);
            } while (getStage(currentStageType) == nullptr &&
                     (currentStageType != StageType::FOLLOW_THROUGH ||
                      currentStageType != StageType::CANCEL));
            currentStage = getStage(currentStageType);
            if (!currentStage) {
                return ExecutionState::ENDED;
            }
        }

        if (!currentStage->isRunning()) {
            currentStage->start();
            state = ExecutionState::CHANGED;
        }
        currentStage->execute();
        if (currentStage->isComplete()) {
            if (currentStageType == StageType::FOLLOW_THROUGH ||
                currentStageType == StageType::CANCEL) {
                running = false;
                state = ExecutionState::ENDED;
            } else {
                currentStageType = static_cast<StageType>((int) currentStageType + 1);
            }
        }
        return state;
    }

    void Action::cancel() {
        switch (currentStageType) {
            case StageType::ANTICIPATION_INTERRUPTIBLE:
                currentStageType = StageType::CANCEL;
                break;
            default:
                break;
        }
    }

    bool Action::isRunning() const {
        return this->running;
    }

    bool Action::hasFinished() const {
        return currentStageType == StageType::FOLLOW_THROUGH;
    }

} /* namespace Divisaction */
