/*
 * File NullPointerException.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef EXCEPTIONS_NULLPOINTEREXCEPTION_H_
#define EXCEPTIONS_NULLPOINTEREXCEPTION_H_

#include <exception>

namespace Divisaction {

    class NullPointerException : std::exception {
    public:
        virtual const char* what() const throw()
        {
          return "Variable required variable is null or some of it's contents are null";
        }
    };

    const NullPointerException nullPointerExc;

} /* namespace Divisaction */

#endif /* EXCEPTIONS_NULLPOINTEREXCEPTION_H_ */
