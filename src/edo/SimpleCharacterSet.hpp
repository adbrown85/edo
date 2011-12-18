/*
 * SimpleCharacterSet.hpp
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#ifndef EDO_SIMPLECHARACTERSET_HPP
#define EDO_SIMPLECHARACTERSET_HPP
#include <set>
#include "edo/common.h"
#include "edo/CharacterSet.hpp"
namespace Edo {


/**
 * Basic implementation of CharacterSet.
 */
class SimpleCharacterSet : public CharacterSet {
public:
    SimpleCharacterSet(char c, bool negated=false);
    SimpleCharacterSet(const std::string &str, bool negated=false);
    SimpleCharacterSet(const std::set<char> &characters, bool negated=false);
    virtual bool contains(char c) const;
private:
    std::set<char> characters;
    bool negated;
// Helpers
    static std::set<char> createSetFromCharacter(char c);
    static std::set<char> createSetFromString(const std::string &str);
};

} // namespace Edo
#endif
