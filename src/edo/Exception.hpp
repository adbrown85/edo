/*
 * Exception.hpp
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#ifndef EDO_EXCEPTION_HPP
#define EDO_EXCEPTION_HPP
#include "edo/common.h"
namespace Edo {


/**
 * Basic implementation of exception.
 */
class Exception : public std::exception {
public:
    Exception(const std::string &message) throw();
    virtual ~Exception() throw();
    virtual const char* what() const throw();
private:
    std::string message;
};

}
#endif
