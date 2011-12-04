/*
 * CharacterSets.cpp
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "config.h"
#include "edo/CharacterSets.hpp"
using namespace std;
using namespace Edo;

/// Returns a reference to the standard alphabetic character set.
CharacterSet& CharacterSets::alphabetic() {
    static CharacterSet *cs = new AlphabeticCharacterSet();
    return *cs;
}

/// Returns a reference to the standard alphanumeric character set.
CharacterSet& CharacterSets::alphanumeric() {
    static CharacterSet *cs = new AlphanumericCharacterSet();
    return *cs;
}

/// Returns a reference to the standard digit character set.
CharacterSet& CharacterSets::digit() {
    static CharacterSet *cs = new DigitCharacterSet();
    return *cs;
}

/// Returns a reference to the standard lowercase character set.
CharacterSet& CharacterSets::lowercase() {
    static CharacterSet *cs = new LowercaseCharacterSet();
    return *cs;
}

/// Returns a reference to the standard punctuation character set.
CharacterSet& CharacterSets::punctuation() {
    static CharacterSet *cs = new PunctuationCharacterSet();
    return *cs;
}

/// Returns a reference to the standard uppercase character set.
CharacterSet& CharacterSets::uppercase() {
    static CharacterSet *cs = new UppercaseCharacterSet();
    return *cs;
}

/// Returns a reference to the standard space character set.
CharacterSet& CharacterSets::whitespace() {
    static CharacterSet *cs = new WhitespaceCharacterSet();
    return *cs;
}

/// Returns a reference to the standard word character set.
CharacterSet& CharacterSets::word() {
    static CharacterSet *cs = new WordCharacterSet();
    return *cs;
}

// NESTED CLASSES

bool CharacterSets::AlphabeticCharacterSet::contains(char c) const {
    return isalpha(c);
}

bool CharacterSets::AlphanumericCharacterSet::contains(char c) const {
    return isalnum(c);
}

bool CharacterSets::DigitCharacterSet::contains(char c) const {
    return isdigit(c);
}

bool CharacterSets::LowercaseCharacterSet::contains(char c) const {
    return islower(c);
}

bool CharacterSets::PunctuationCharacterSet::contains(char c) const {
    return ispunct(c);
}

bool CharacterSets::UppercaseCharacterSet::contains(char c) const {
    return isupper(c);
}

bool CharacterSets::WhitespaceCharacterSet::contains(char c) const {
    return isspace(c);
}

bool CharacterSets::WordCharacterSet::contains(char c) const {
    return isalnum(c) || c == '_';
}
