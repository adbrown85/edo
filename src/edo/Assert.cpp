/*
 * Assert.cpp
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "config.h"
#include "edo/Assert.hpp"
using namespace std;
namespace Edo {

// HELPERS

/**
 * Makes a message for an exception.
 * 
 * @param a Expected value
 * @param b Actual value
 * @return Message listing both values
 */
static string createMessage(bool a, bool b) {
    
    stringstream ss;

    ss << boolalpha;
    ss << "Expected [" << a << "] but was [" << b << "]!";
    return ss.str();
}

/**
 * Makes a message for an exception.
 * 
 * @param x Expected value
 * @param y Actual value
 * @return Message listing both values
 */
static string createMessage(float x, float y) {
    
    stringstream ss;
    
    ss << "Expected [" << x << "] but was [" << y << "]!";
    return ss.str();
}

/**
 * Makes a message for an exception.
 * 
 * @param x Expected value
 * @param y Actual value
 * @return Message listing both values
 */
static string createMessage(int x, int y) {
    
    stringstream ss;
    
    ss << "Expected [" << x << "] but was [" << y << "]!";
    return ss.str();
}

/**
 * Makes a message for an exception.
 * 
 * @param s1 Expected value
 * @param s2 Actual value
 * @return Message listing both values
 */
static string createMessage(const string &s1, const string &s2) {
    
    stringstream ss;
    
    ss << "Expected [" << s1 << "] but was [" << s2 << "]!";
    return ss.str();
}

// FUNCTIONS

/**
 * Checks to see if two boolean values are equal.
 * 
 * @param a First value
 * @param b Second value
 * @throw std::exception if values are not equal
 */
void assertEquals(bool a, bool b) {
    if (a != b) {
        throw Exception(createMessage(a, b));
    }
}

/**
 * Checks to see if two float values are approximately equal.
 * 
 * @param x First value
 * @param y Second value
 * @param epsilon Margin of error
 * @throw std::exception if values are not approximately equal
 */
void assertEquals(float x, float y, float epsilon) {
    if (fabs(x - y) > epsilon) {
        throw Exception(createMessage(x, y));
    }
}

/**
 * Checks to see if two integer values are equal.
 * 
 * @param x First value
 * @param y Second value
 * @throw std::exception if values are not equal
 */
void assertEquals(int x, int y) {
    if (x != y) {
        throw Exception(createMessage(x, y));
    }
}

/**
 * Checks to see if two strings are equal.
 * 
 * @param s1 First string
 * @param s2 Second string
 * @throw std::exception if strings are not equal
 */
void assertEquals(const string &s1, const string &s2) {
    if (s1 != s2) {
        throw Exception(createMessage(s1, s2));
    }
}

} /* namespace Edo */
