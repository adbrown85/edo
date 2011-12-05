/*
 * SimplePattern.hpp
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#ifndef EDO_SIMPLEPATTERN_HPP
#define EDO_SIMPLEPATTERN_HPP
#include <sstream>
#include "edo/common.h"
#include "edo/CharacterSet.hpp"
#include "edo/Exception.hpp"
#include "edo/Pattern.hpp"
namespace Edo {


/**
 * Basic pattern consisting of a character set that may be repeated.
 */
class SimplePattern : public Pattern {
public:
    SimplePattern(CharacterSet *characters, Quantifier quantifier);
    virtual bool matches(std::istream &stream) const;
    virtual std::string match(std::istream &stream) const;
// Getters
    CharacterSet* getCharacterSet();
    Quantifier getQuantifier();
private:
    CharacterSet *characters;
    Quantifier quantifier;
// Helpers
    static bool isSupported(Quantifier quantifier);
    std::string matchQuantifierOne(std::istream &stream) const;
    std::string matchQuantifierOneOrMore(std::istream &stream) const;
    std::string matchQuantifierZeroOrOne(std::istream &stream) const;
    std::string matchQuantifierZeroOrMore(std::istream &stream) const;
    std::string takeCharacterFromStream(std::istream &stream) const;
    std::string takeCharactersFromStream(std::istream &stream) const;
};

} // namespace Edo
#endif
