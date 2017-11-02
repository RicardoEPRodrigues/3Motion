/*
* File Executable.h in project Divisaction
*
* Copyright (C) ricardo 2016 - All Rights Reserved
*/

#ifndef EXECUTABLE_H_
#define EXECUTABLE_H_

#include <string>
#include <memory>

namespace ThreeMotion {

    class TExecutable {
        private:
            std::string name;
        public:
            enum ExecutionState {
                RUNNING, CHANGED, ENDED
            };

            TExecutable();

            explicit TExecutable(std::string name);

            TExecutable(const TExecutable& other);

            virtual ~TExecutable();

            const std::string& getName() const;

            void setName(const std::string& name);

            /**
             * Executes the functionality of this executable.
             * @return true if the execution has finished all it's steps, false otherwise.
             */
            virtual ExecutionState Execute() = 0;

            virtual void Reset() = 0;

            virtual bool IsRunning() const = 0;

            inline bool operator==(const TExecutable& other) const {
                return this->getName() == other.getName();
            }

            inline bool operator!=(const TExecutable& other) const {
                return !((*this) == other);
            }

            inline bool operator<(const TExecutable& other) const {
                return this->name < other.getName();
            }

            inline bool operator>(const TExecutable& other) const {
                return this->name > other.getName();
            }
    };

} /* namespace ThreeMotion */

#endif /* EXECUTABLE_H_ */
