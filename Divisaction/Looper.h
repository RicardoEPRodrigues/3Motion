/*
 * File Looper.h in project DivisactionCommandLine
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef LOOPER_H_
#define LOOPER_H_

#include <functional>
#include <chrono>
#include <thread>

#include "Exceptions/NullPointerException.h"
#include "Exceptions/InvalidArgumentException.h"

namespace Divisaction {

    class Looper {
    private:
        bool continueLoop;
        std::function<void()> callback;
        /**
         * interval in which the loop will run in milliseconds.
         * It's default value is 250 milliseconds.
         */
        long int interval;

    public:
        Looper();
        Looper(std::function<void()> callback, long int interval = 250);
        virtual ~Looper();

        void setCallback(std::function<void()> callback);
        void setInterval(long int interval);

        void start();

        /**
         * Starts the loop and on each loop it calls the function callback.
         *
         * @param callback function, it is called at each loop of the looper.
         */
        void start(std::function<void()> callback);

        bool isRunning();

        void stop();
    };

} /* namespace Divisaction */

#endif /* LOOPER_H_ */
