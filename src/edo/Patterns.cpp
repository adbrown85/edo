/*
 * Patterns.cpp
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "config.h"
#include "edo/Patterns.hpp"
using namespace std;
using namespace Edo;

/**
 * Returns a reference to the standard punctuation pattern.
 */
Pattern& Patterns::punctuation() {
    static Pattern *pattern = createPunctuationPattern();
    return *pattern;
}

/**
 * Returns a reference to the standard whitespace pattern.
 */
Pattern& Patterns::whitespace() {
    static Pattern *pattern = createWhitespacePattern();
    return *pattern;
}

/**
 * Returns a reference to the standard word pattern.
 */
Pattern& Patterns::word() {
    static Pattern *pattern = createWordPattern();
    return *pattern;
}

// HELPERS

/**
 * Returns a new punctuation pattern instance.
 */
Pattern* Patterns::createPunctuationPattern() {

    CharacterSet *characters = &CharacterSets::punctuation();
    Quantifier quantifier = QUANTIFIER_ONE;
    Pattern *pattern = new SimplePattern(characters, quantifier);

    return pattern;
}

/**
 * Returns a new whitespace pattern instance.
 */
Pattern* Patterns::createWhitespacePattern() {

    CharacterSet *characters = &CharacterSets::whitespace();
    Quantifier quantifier = QUANTIFIER_ZERO_OR_MORE;
    Pattern *pattern = new SimplePattern(characters, quantifier);

    return pattern;
}

/**
 * Returns a new word pattern instance.
 */
Pattern* Patterns::createWordPattern() {

    CharacterSet *characters = &CharacterSets::word();
    Quantifier quantifier = QUANTIFIER_ONE_OR_MORE;
    Pattern *pattern = new SimplePattern(characters, quantifier);

    return pattern;
}
