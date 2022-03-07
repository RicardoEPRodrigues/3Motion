/*
 * File Action.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "TAction.h"

using namespace std;

namespace ThreeMotion {

    TAction::TAction() : TExecutable("Action"), running(false),
                         stages(TStageType::size, nullptr),
                         currentStageType() {
        Reset();
    }

    TAction::TAction(const TAction& other) : TExecutable(other),
                                             running(other.running),
                                             stages(TStageType::size, nullptr),
                                             currentStageType(
                                                     other.currentStageType) {
        for (unsigned int stageType = 0;
             stageType < other.stages.size(); ++stageType) {
            if (other.stages[stageType]) {
                stages[stageType] = other.stages[stageType]->Clone();
            }
        }
    }

    TAction::~TAction() = default;

    void TAction::Reset() {
        this->currentStageType = TStageType::ANTICIPATION_INTERRUPTIBLE;
        this->running = false;
        for (auto stage : stages) {
            if (stage) {
                stage->Reset();
            }
        }
    }

    void TAction::SetStage(TStageType type, std::shared_ptr<TStage> stage) {
        this->stages[type] = stage;
    }

    std::shared_ptr<TStage> TAction::GetStage(TStageType type) const {
        return stages[type];
    }

    TStageType TAction::GetCurrentStageType() const {
        return currentStageType;
    }

    std::shared_ptr<TStage> TAction::GetCurrentStage() const {
        return stages[currentStageType];
    }

    /**
     * Executes the action.
     * @return true if the action has finished all it's steps, false otherwise.
     */
    TExecutable::ExecutionState TAction::Execute() {
        ExecutionState state = ExecutionState::RUNNING;
        // If not running start running
        if (!running) {
            Reset();
            running = true;
        }

        // Get current stage.
        std::shared_ptr<TStage> currentStage = GetCurrentStage();
        if (!currentStage) {
            // If stage is null then skip ahead.
            do {
                NextStageType();
            } while ((currentStage = GetStage(currentStageType)) == nullptr &&
                     !IsEndState(currentStageType));
            // If no stage is found consider action finished.
            if (!currentStage) {
                running = false;
                return ExecutionState::ENDED;
            }
        }

        if (!currentStage->IsRunning()) {
            currentStage->Start();
            state = ExecutionState::CHANGED;
        }
        currentStage->Execute();
        if (currentStage->IsComplete()) {
            if (IsEndState(currentStageType)) {
                running = false;
                state = ExecutionState::ENDED;
            } else {
                NextStageType();
            }
        }
        return state;
    }

    void TAction::Cancel() {
        switch (currentStageType) {
            case TStageType::ANTICIPATION_INTERRUPTIBLE:
                currentStageType = TStageType::CANCEL;
                break;
            default:
                break;
        }
    }

    bool TAction::IsRunning() const {
        return this->running;
    }

    bool TAction::HasFinished() const {
        return currentStageType == TStageType::FOLLOW_THROUGH;
    }

    bool TAction::IsEndState(TStageType type) {
        return type == TStageType::FOLLOW_THROUGH ||
               type == TStageType::CANCEL;
    }

    void TAction::NextStageType() {
        currentStageType = static_cast<TStageType>(
                (int) currentStageType + 1);
    }

} /* namespace ThreeMotion */
