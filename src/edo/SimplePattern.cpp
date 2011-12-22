/*
 * SimplePattern.cpp
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "config.h"
#include "edo/SimplePattern.hpp"
using namespace std;
using namespace Edo;

/**
 * Constructs a simple pattern.
 *
 * @param characters Set of characters pattern will match
 * @param quantifier Cardinality and repetition of character set
 * @param negated True to match all characters not in character set
 * @throws std::exception if character set is NULL
 */
SimplePattern::SimplePattern(CharacterSet *characters, Quantifier quantifier, bool negated) {

    if (characters == NULL) {
        throw Exception("[SimplePattern] Character set is NULL!");
    } else if (!isSupported(quantifier)) {
        throw Exception("[Quantifier] Quantifier not recognized!");
    }

    this->characters = characters;
    this->quantifier = quantifier;
    this->negated = negated;
}

bool SimplePattern::matches(std::istream &stream) const {
    switch (quantifier) {
    case QUANTIFIER_ONE:
    case QUANTIFIER_ONE_OR_MORE:
        return contains(stream.peek());
    case QUANTIFIER_ZERO_OR_ONE:
    case QUANTIFIER_ZERO_OR_MORE:
        return true;
    default:
        throw Exception("[SimplePattern] Unexpected quantifier!");
    }
}

string SimplePattern::match(std::istream &stream) const {
    switch (quantifier) {
    case QUANTIFIER_ONE:
        return matchQuantifierOne(stream);
    case QUANTIFIER_ONE_OR_MORE:
        return matchQuantifierOneOrMore(stream);
    case QUANTIFIER_ZERO_OR_ONE:
        return matchQuantifierZeroOrOne(stream);
    case QUANTIFIER_ZERO_OR_MORE:
        return matchQuantifierZeroOrMore(stream);
    default:
        throw Exception("[SimplePattern] Unexpected quantifier!");
    }
}

// GETTERS

/**
 * Returns True if the pattern matches everything not in character set.
 */
bool SimplePattern::isNegated() const {
    return negated;
}

// HELPERS

bool SimplePattern::contains(char c) const {
    return negated ? !characters->contains(c) : characters->contains(c);
}

bool SimplePattern::isSupported(Quantifier quantifier) {
    switch (quantifier) {
    case QUANTIFIER_ONE:
    case QUANTIFIER_ONE_OR_MORE:
    case QUANTIFIER_ZERO_OR_ONE:
    case QUANTIFIER_ZERO_OR_MORE:
        return true;
    default:
        return false;
    }
}

string SimplePattern::matchQuantifierOne(istream &stream) const {
    if (!contains(stream.peek())) {
        throw Exception("[SimplePattern] Input does not match!");
    } else {
        return takeCharacterFromStream(stream);
    }
}

string SimplePattern::matchQuantifierOneOrMore(istream &stream) const {
    if (!contains(stream.peek())) {
        throw Exception("[SimplePattern] Input does not match!");
    } else {
        return takeCharactersFromStream(stream);
    }
}

string SimplePattern::matchQuantifierZeroOrOne(istream &stream) const {
    if (!contains(stream.peek())) {
        return "";
    } else {
        return takeCharacterFromStream(stream);
    }
}

string SimplePattern::matchQuantifierZeroOrMore(istream &stream) const {
    if (!contains(stream.peek())) {
        return "";
    } else {
        return takeCharactersFromStream(stream);
    }
}

/**
 * Takes a single matching character from a stream.
 *
 * @param stream Stream to take character from
 * @return Matching character from stream
 */
string SimplePattern::takeCharacterFromStream(istream &stream) const {

    char c[2];

    c[0] = stream.get();
    c[1] = '\0';
    return string(c);
}

/**
 * Takes multiple matching characters from a stream.
 *
 * @param stream Stream to take characters from
 * @return Matching characters from stream
 */
string SimplePattern::takeCharactersFromStream(istream &stream) const {

    stringstream buf;
    char c;

    while (contains(stream.peek())) {
        c = stream.get();
        buf << c;
    }
    return buf.str();
}
