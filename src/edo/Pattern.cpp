/*
 * Pattern.cpp
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "config.h"
#include "edo/Pattern.hpp"
using namespace std;
using namespace Edo;

/**
 * Constructs a pattern.
 */
Pattern::Pattern() {
    ;
}

/**
 * Destroys a pattern.
 */
Pattern::~Pattern() {
    ;
}

/**
 * Checks if the pattern is at the beginning of a stream.
 *
 * @param stream Stream to check for pattern
 * @return True if pattern is at head of stream
 */
bool Pattern::matches(istream &stream) const {
    return false;
}

/**
 * Takes input from the begining of a stream matching the pattern.
 *
 * @param stream Stream to take pattern from
 * @return Input from stream matching pattern
 * @throws std::exception if input does not match pattern
 */
string Pattern::match(istream &stream) const {
    return "";
}
