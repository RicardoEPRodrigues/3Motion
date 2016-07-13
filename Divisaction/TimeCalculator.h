/*
 * File TimeCalculator.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_TIMECALCULATOR_H
#define DIVISACTION_TIMECALCULATOR_H


class TimeCalculator {
    public:
        virtual void update() = 0;

        virtual double startTime() = 0;

        virtual double now() = 0;

        virtual double delta() = 0;

        virtual void play() = 0;

        virtual void pause() = 0;
};


#endif //DIVISACTION_TIMECALCULATOR_H
