/*
 * File ChronoTimeCalculator.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_CHRONOTIMECALCULATOR_H
#define DIVISACTION_CHRONOTIMECALCULATOR_H

#include <chrono>

#include "../TimeCalculator.h"

class ChronoTimeCalculator : public TimeCalculator {
    private:
        bool started;
        double _now;
        double realtimeNow;
        double _startTime;
        double _delta;
        bool _pause;
    public:

        ChronoTimeCalculator();

        virtual void update() override;

        virtual double now() override;

        virtual double delta() override;

        double startTime() override;

        void play() {
            _pause = false;
        }

        void pause() {
            _pause = true;
        }

};


#endif //DIVISACTION_CHRONOTIMECALCULATOR_H
