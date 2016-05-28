/*
* File Executable.h in project Divisaction
*
* Copyright (C) ricardo 2016 - All Rights Reserved
*/

#ifndef EXECUTABLE_H_
#define EXECUTABLE_H_

namespace Divisaction {

    class Executable {
    public:
        virtual ~Executable() {}
        /**
         * Executes the functionality of this executable.
         * @return true if the execution has finished all it's steps, false otherwise.
         */
        virtual bool execute() = 0;
        virtual void reset() = 0;

        virtual bool isRunning() const = 0;
    };

} /* namespace Divisaction */

#endif /* EXECUTABLE_H_ */
