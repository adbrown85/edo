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
 */
SimpleCharacterSet::SimpleCharacterSet(char c) {
    this->characters = createSetFromCharacter(c);
}

/**
 * Constructs a character set from a string.
 *
 * @param str String with characters to add to set
 */
SimpleCharacterSet::SimpleCharacterSet(const std::string &str) {
    this->characters = createSetFromString(str);
}

/**
 * Constructs a character set from a set of characters.
 *
 * @param characters Set of characters to copy into set
 */
SimpleCharacterSet::SimpleCharacterSet(const std::set<char> &characters) {
    this->characters = characters;
}

bool SimpleCharacterSet::contains(char c) const {

    set<char>::iterator it = characters.find(c);
    bool found = characters.find(c) != characters.end();

    return found;
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
