/*
 * Scanner.cpp
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "config.h"
#include "edo/Scanner.hpp"
using namespace std;
using namespace Edo;

Pattern *Scanner::DEFAULT_DELIMITER = createDefaultDelimiter();

/**
 * Constructs a scanner from a stream.
 *
 * @param str Stream to scan
 */
Scanner::Scanner(istream &stream) {
    this->stream = &stream;
    this->delimiter = DEFAULT_DELIMITER;
}

/**
 * Destroys a scanner.
 */
Scanner::~Scanner() {
    ;
}

/**
 * Checks if a pattern is contained in the stream.
 *
 * @param pattern Pattern to look for in stream
 * @return True if stream matches pattern
 * @throw std::exception if pattern is NULL
 */
bool Scanner::hasNext(Pattern *pattern) {

    if (pattern == NULL) {
        throw Exception("[Scanner] Pattern is NULL!");
    } else if (stream->fail()) {
        return false;
    }

    bool matched;
    string tok;
    int len;
    int last;

    // Take delimiter token if it matches
    if (delimiter->matches(*stream)) {
        tok = delimiter->match(*stream);
    }

    // Check if pattern matches
    matched = pattern->matches(*stream);

    // Put the characters back from delimiter
    len = tok.length();
    last = len - 1;
    for (int i = last; i >= 0; --i) {
        stream->putback(tok[i]);
    }

    // Return whether pattern matched
    return matched;
}

/**
 * Takes input matching a pattern from the stream.
 *
 * @param pattern Pattern to take
 * @return Input matching pattern
 */
string Scanner::next(Pattern *pattern) {

    if (pattern == NULL) {
        throw Exception("[Scanner] Pattern is NULL!");
    }

    // Take delimiter if it matches
    if (delimiter->matches(*stream)) {
        delimiter->match(*stream);
    }

    // Take pattern
    return pattern->match(*stream);
}

/**
 * Returns the pattern the scanner will automatically skip over.
 */
Pattern* Scanner::getDelimiter() const {
    return delimiter;
}

/**
 * Changes the delimiter the scanner will automatically skip over.
 *
 * @param pattern Pattern scanner will automatically ignore
 * @throw std::exception if pattern is NULL
 */
void Scanner::setDelimiter(Pattern *pattern) {
    if (pattern == NULL) {
        throw Exception("[Scanner] Pattern is NULL!");
    } else {
        this->delimiter = pattern;
    }
}

// HELPERS

/**
 * Makes the default delimiter.
 */
Pattern* Scanner::createDefaultDelimiter() {

    CharacterSet *characters = &CharacterSets::whitespace();
    Quantifier quantifier = QUANTIFIER_ZERO_OR_MORE;
    Pattern *pattern = new SimplePattern(characters, quantifier);

    return pattern;
}
