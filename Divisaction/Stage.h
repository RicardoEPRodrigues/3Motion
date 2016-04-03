/*
 * File Stage.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef STAGE_H_
#define STAGE_H_

#include <string>
#include <chrono>
using namespace std::chrono;

namespace Divisaction {

    class Stage {
    private:
        system_clock::time_point startTime;

        /**
         * Returns the current progress of the stage.
         * @param now Present time
         * @return Progress value between 0 and 1. If the stage hasn't been started it'll return 0. If the stage is complete it'll always return 1.
         */
        double getProgress(system_clock::time_point now);
    public:
        std::string name;
        double durationInMilliseconds;
        bool interuptable;

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
    };

} /* namespace Divisaction */

#endif /* STAGE_H_ */
