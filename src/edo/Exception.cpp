/*
 * Exception.cpp
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "config.h"
#include "edo/Exception.hpp"
using namespace Edo;
using namespace std;

/**
 * Creates a basic exception.
 *
 * @param message Explanation shown to the user
 */
Exception::Exception(const string &message) throw() {
    this->message = message;
}

/**
 * Destroys the exception.
 */
Exception::~Exception() throw() {
    ;
}

/**
 * Returns the explanation that will be shown to the user.
 */
const char* Exception::what() const throw() {
    return message.c_str();
}
