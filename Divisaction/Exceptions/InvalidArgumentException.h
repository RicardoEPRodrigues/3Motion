/*
 * File InvalidArgumentException.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef EXCEPTIONS_INVALIDARGUMENTEXCEPTION_H_
#define EXCEPTIONS_INVALIDARGUMENTEXCEPTION_H_

#include <exception>

namespace Divisaction {

    class InvalidArgumentException : std::exception {
    public:
        virtual const char* what() const throw()
        {
          return "Variable required variable is invalid or some of it's contents are invalid";
        }
    } invalidArgumentExc;

} /* namespace Divisaction */

#endif /* EXCEPTIONS_INVALIDARGUMENTEXCEPTION_H_ */
