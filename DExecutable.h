/*
* File Executable.h in project Divisaction
*
* Copyright (C) ricardo 2016 - All Rights Reserved
*/

#ifndef EXECUTABLE_H_
#define EXECUTABLE_H_

#include <string>
#include <memory>

namespace Divisaction {

    class DExecutable {
        private:
            std::string name;
        public:
            enum ExecutionState { RUNNING, CHANGED, ENDED };

            DExecutable();

            DExecutable(std::string name);

            DExecutable(const DExecutable& other);

            virtual ~DExecutable();

            const std::string& getName() const;

            void setName(const std::string& name);

            /**
             * Executes the functionality of this executable.
             * @return true if the execution has finished all it's steps, false otherwise.
             */
            virtual ExecutionState execute() = 0;

            virtual void reset() = 0;

            virtual bool isRunning() const = 0;

            inline bool operator==(const DExecutable& other) const {
                return this->getName() == other.getName();
            }

            inline bool operator!=(const DExecutable& other) const {
                return !((*this) == other);
            }

            inline bool operator<(const DExecutable& other) const {
                return this->name < other.getName();
            }

            inline bool operator>(const DExecutable& other) const {
                return this->name > other.getName();
            }
    };

} /* namespace Divisaction */

#endif /* EXECUTABLE_H_ */
