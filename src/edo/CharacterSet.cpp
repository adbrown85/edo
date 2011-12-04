/*
 * CharacterSet.cpp
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "config.h"
#include "edo/CharacterSet.hpp"
using namespace std;
using namespace Edo;

/**
 * Destroys the character set.
 */
CharacterSet::~CharacterSet() {
    ;
}

/**
 * Checks if a character is in the character set.
 *
 * @param c Character to check
 * @return True if character is in character set
 */
bool CharacterSet::contains(char c) const {
    return true;
}
