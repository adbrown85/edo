/*
 * Patterns.hpp
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#ifndef EDO_PATTERNS_HPP
#define EDO_PATTERNS_HPP
#include "edo/common.h"
#include "edo/CharacterSets.hpp"
#include "edo/SimplePattern.hpp"
namespace Edo {


/**
 * Collection of commonly-used patterns.
 */
class Patterns {
public:
    static Pattern& punctuation();
    static Pattern& whitespace();
    static Pattern& word();
private:
    Patterns();
    Patterns(const Patterns &patterns);
    Patterns& operator=(const Patterns &patterns);
// Helpers
    static Pattern* createPunctuationPattern();
    static Pattern* createWhitespacePattern();
    static Pattern* createWordPattern();
};

} // namespace Edo
#endif
