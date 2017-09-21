/*
 * File Action.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "DAction.h"

using namespace std;

namespace ThreeMotion {

    DAction::DAction() {
        stages = vector<std::shared_ptr<DStage>>(DStageType::size, nullptr);
        reset();
    }

    DAction::DAction(const DAction& other) : DExecutable(other), running(other.running),
                                          currentStageType(other.currentStageType) {
        stages = vector<std::shared_ptr<DStage>>(DStageType::size, nullptr);
        for (unsigned int stageType = 0; stageType < other.stages.size(); ++stageType) {
            if (other.stages[stageType]) {
                stages[stageType] = other.stages[stageType]->clone();
            }
        }
    }

    DAction::~DAction() {}

    void DAction::reset() {
        this->currentStageType = DStageType::ANTICIPATION_INTERRUPTIBLE;
        this->running = false;
        for (auto stage : stages) {
            if (stage) {
                stage->reset();
            }
        }
    }

    void DAction::setStage(DStageType type, std::shared_ptr<DStage> stage) {
        this->stages[type] = stage;
    }

    std::shared_ptr<DStage> DAction::getStage(DStageType type) const {
        return stages[type];
    }

    DStageType DAction::getCurrentStageType() const {
        return currentStageType;
    }

    std::shared_ptr<DStage> DAction::getCurrentStage() const {
        return stages[currentStageType];
    }

    /**
     * Executes the action.
     * @return true if the action has finished all it's steps, false otherwise.
     */
    DExecutable::ExecutionState DAction::execute() {
        ExecutionState state = ExecutionState::RUNNING;
        if (!running) {
            reset();
            running = true;
        }

        std::shared_ptr<DStage> currentStage = getStage(currentStageType);
        if (!currentStage) {
            do {
                currentStageType = static_cast<DStageType>((int) currentStageType + 1);
            } while (getStage(currentStageType) == nullptr &&
                     (currentStageType != DStageType::FOLLOW_THROUGH ||
                      currentStageType != DStageType::CANCEL));
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
            if (currentStageType == DStageType::FOLLOW_THROUGH ||
                currentStageType == DStageType::CANCEL) {
                running = false;
                state = ExecutionState::ENDED;
            } else {
                currentStageType = static_cast<DStageType>((int) currentStageType + 1);
            }
        }
        return state;
    }

    void DAction::cancel() {
        switch (currentStageType) {
            case DStageType::ANTICIPATION_INTERRUPTIBLE:
                currentStageType = DStageType::CANCEL;
                break;
            default:
                break;
        }
    }

    bool DAction::isRunning() const {
        return this->running;
    }

    bool DAction::hasFinished() const {
        return currentStageType == DStageType::FOLLOW_THROUGH;
    }

} /* namespace ThreeMotion */
