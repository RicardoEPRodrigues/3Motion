/*
 * File Stage.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */
#ifndef STAGE_H_
#define STAGE_H_

#include <string>
#include <memory>
#include "TExecutable.h"
#include "TDefine.h"

namespace ThreeMotion {

    class TStage : public TExecutable {
        public:

            TStage();

            TStage(std::string name, milliseconds timeToPerceive);

            TStage(const TStage& other);

            ~TStage() override;

            virtual std::shared_ptr<TStage> clone() const = 0;

            void Start();

            /**
             * Updates the current stage
             */
            ExecutionState Execute() override;

            void Reset() override;

            bool IsRunning() const override;

            bool IsComplete() const;

            milliseconds GetTimeToPerceive() const;

            void SetTimeToPerceive(milliseconds timeToPerceive);

        protected:
            virtual void OnStart() = 0;

            virtual ExecutionState onUpdate() = 0;

        private:
            bool complete;
            bool playing;
            milliseconds timeToPerceive;
    };

} /* namespace ThreeMotion */

#endif /* STAGE_H_ */
