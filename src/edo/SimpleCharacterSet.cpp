/*
 * SimpleCharacterSet.cpp
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "config.h"
#include "edo/SimpleCharacterSet.hpp"
using namespace std;
using namespace Edo;

/**
 * Constructs a character set from a single character.
 *
 * @param c Single character to add to set
 * @param negated True to use the opposite character set
 */
SimpleCharacterSet::SimpleCharacterSet(char c, bool negated) {
    this->characters = createSetFromCharacter(c);
    this->negated = negated;
}

/**
 * Constructs a character set from a string.
 *
 * @param str String with characters to add to set
 * @param negated True to use the opposite character set
 */
SimpleCharacterSet::SimpleCharacterSet(const std::string &str, bool negated) {
    this->characters = createSetFromString(str);
    this->negated = negated;
}

/**
 * Constructs a character set from a set of characters.
 *
 * @param characters Set of characters to copy into set
 * @param negated True to use the opposite character set
 */
SimpleCharacterSet::SimpleCharacterSet(const set<char> &characters, bool negated) {
    this->characters = characters;
    this->negated = negated;
}

bool SimpleCharacterSet::contains(char c) const {

    set<char>::iterator it = characters.find(c);
    bool found = characters.find(c) != characters.end();

    return negated ? !found : found;
}

//
// HELPERS
//

set<char> SimpleCharacterSet::createSetFromCharacter(char c) {

    set<char> characters;

    characters.insert(c);
    return characters;
}

set<char> SimpleCharacterSet::createSetFromString(const std::string &str) {

    set<char> characters;
    size_t len = str.length();

    for (int i=0; i<len; ++i) {
        characters.insert(str[i]);
    }
    return characters;
}
