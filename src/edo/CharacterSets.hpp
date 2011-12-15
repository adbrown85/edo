/*
 * CharacterSets.hpp
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#ifndef EDO_CHARACTERSETS_HPP
#define EDO_CHARACTERSETS_HPP
#include "edo/common.h"
#include "edo/CharacterSet.hpp"
namespace Edo {


/**
 * Collection of common character sets.
 */
class CharacterSets {
public:
    static CharacterSet& alphabetic();
    static CharacterSet& alphanumeric();
    static CharacterSet& digit();
    static CharacterSet& lowercase();
    static CharacterSet& printable();
    static CharacterSet& punctuation();
    static CharacterSet& uppercase();
    static CharacterSet& whitespace();
    static CharacterSet& word();
private:
    CharacterSets();
    CharacterSets(const CharacterSets&);
    CharacterSets& operator=(const CharacterSets&);
// Nested classes
    class AlphabeticCharacterSet;
    class AlphanumericCharacterSet;
    class DigitCharacterSet;
    class LowercaseCharacterSet;
    class PrintableCharacterSet;
    class PunctuationCharacterSet;
    class UppercaseCharacterSet;
    class WhitespaceCharacterSet;
    class WordCharacterSet;
};


/// Character set with alphabetic characters.
class CharacterSets::AlphabeticCharacterSet : public CharacterSet {
public:
    virtual bool contains(char c) const;
};

/// Character set containing alphanumerics.
class CharacterSets::AlphanumericCharacterSet : public CharacterSet {
public:
    virtual bool contains(char c) const;
};

/// Character set containing digits.
class CharacterSets::DigitCharacterSet : public CharacterSet {
public:
    virtual bool contains(char c) const;
};

/// Character set containing lowercase letters.
class CharacterSets::LowercaseCharacterSet : public CharacterSet {
public:
    virtual bool contains(char c) const;
};

/// Character set containing visible characters and space.
class CharacterSets::PrintableCharacterSet : public CharacterSet {
public:
    virtual bool contains(char c) const;
};

/// Character set containing punctuation.
class CharacterSets::PunctuationCharacterSet : public CharacterSet {
public:
    virtual bool contains(char c) const;
};

/// Character set containing uppercase letters.
class CharacterSets::UppercaseCharacterSet : public CharacterSet {
public:
    virtual bool contains(char c) const;
};

/// Character set containing spaces.
class CharacterSets::WhitespaceCharacterSet : public CharacterSet {
public:
    virtual bool contains(char c) const;
};

/// Character set containing alphanumerics and the underscore.
class CharacterSets::WordCharacterSet : public CharacterSet {
public:
    virtual bool contains(char c) const;
};

} // namespace Edo
#endif
