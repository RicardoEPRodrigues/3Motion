/*
 * File Stage.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */
/**
 * @file Stage.h
 */
#ifndef STAGE_H_
#define STAGE_H_

#include <string>

namespace Divisaction {

    class Stage {
    private:
        std::string name;
        bool complete;
        bool playing;
        /**
         * Determines if this stage is interruptible.
         * @note interruptibility in only important if the stage is an Execution or Follow Through stage
         * @see Action()
         */
        bool interuptable;
    protected:
        virtual void onStart() = 0;
        virtual void onUpdate() = 0;
    public:

        Stage();
        Stage(std::string name, bool interuptable = true);
        virtual ~Stage();

        void start();
        /**
         * Updates the current stage
         * @return Progress value between 0 and 1. If the stage hasn't been started it'll return 0. If the stage is complete it'll always return 1.
         */
        void update();

        void endStage();
        bool isPlaying() const;
        bool isComplete() const;

        bool isInteruptable() const;
        void setInteruptable(bool interuptable);
        const std::string& getName() const;
        void setName(const std::string& name);
        inline bool operator==(const Stage& other);
        inline bool operator!=(const Stage& other);
        inline bool operator<(const Stage& other);
        inline bool operator>(const Stage& other);
    };

} /* namespace Divisaction */

#endif /* STAGE_H_ */
