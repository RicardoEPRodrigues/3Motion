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
#include <chrono>
#include <math.h>

using namespace std;
using namespace std::chrono;

namespace Divisaction {

    class Stage {
    private:
        system_clock::time_point startTime;

        bool complete;
        bool started;
        std::string name;
        double durationInMilliseconds;
        /**
         * Determines if this stage is interruptible.
         * @note interruptibility in only important if the stage is an Execution or Follow Through stage
         * @see Action()
         */
        bool interuptable;
    public:

        Stage();
        Stage(std::string name, double durationInMilliseconds = 0,
                bool interuptable = true);
        virtual ~Stage();

        void start();

        /**
         * Returns the current progress of the stage.
         * @return Progress value between 0 and 1. If the stage hasn't been started it'll return 0. If the stage is complete it'll always return 1.
         */
        double getProgress();

        /**
         * Returns the progress of an stage.
         * @param start Time in which the stage started
         * @param now Present time
         * @param durationInMilliseconds Time duration of the stage
         * @return Progress value between 0 and 1. If the stage hasn't been started it'll return 0. If the stage is complete it'll always return 1.
         */
        static double getProgress(system_clock::time_point start,
                system_clock::time_point now, double durationInMilliseconds);

        bool isComplete();
        void endStage();
        bool hasStarted() const;

        void reset();

        inline bool operator==(const Stage& other);
        inline bool operator!=(const Stage& other);
        inline bool operator<(const Stage& other);
        inline bool operator>(const Stage& other);
        double getDurationInMilliseconds() const;
        void setDurationInMilliseconds(double durationInMilliseconds);
        bool isInteruptable() const;
        void setInteruptable(bool interuptable);
        const std::string& getName() const;
        void setName(const std::string& name);
    };

} /* namespace Divisaction */

#endif /* STAGE_H_ */
