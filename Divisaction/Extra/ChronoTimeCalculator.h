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
        double _startTime;
        double _delta;

    public:
        ChronoTimeCalculator();

        virtual void update() override;

        virtual double now() override;

        virtual double delta() override;

        double startTime() override;

};


#endif //DIVISACTION_CHRONOTIMECALCULATOR_H
