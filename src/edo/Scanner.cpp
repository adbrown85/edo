/*
 * Scanner.cpp
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "config.h"
#include <cassert>
#include <fstream>
#include <sstream>
#include "edo/Scanner.hpp"
using namespace std;
using namespace Edo;

Pattern *Scanner::DEFAULT_DELIMITER = createDefaultDelimiter();

/**
 * Constructs a scanner from a path.
 *
 * @param path Path to the file to scan
 * @throw std::exception if path is empty
 * @throw std::exception if file cannot be opened
 */
Scanner::Scanner(const Path &path) {
    this->stream = createStreamFromPath(path);
    this->delimiter = DEFAULT_DELIMITER;
}

/**
 * Constructs a scanner from a string.
 *
 * @param str String to scan
 */
Scanner::Scanner(const string &str) {
    this->stream = createStreamFromString(str);
    this->delimiter = DEFAULT_DELIMITER;
}

/**
 * Destroys a scanner.
 */
Scanner::~Scanner() {
    delete stream;
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

/**
 * Closes any resources used by the scanner.
 */
void Scanner::close() {

    ifstream *fs = dynamic_cast<ifstream*>(stream);

    if (fs != NULL) {
        if (fs->is_open()) {
            fs->close();
        }
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

/**
 * Makes a stream from a path.
 *
 * @param Path to file to create stream from
 * @return Resulting stream
 * @throw std::exception if path is empty
 * @throw std::exception if file cannot be opened
 */
istream* Scanner::createStreamFromPath(const Path &path) {

    string str = path.toString();
    ifstream *stream = new ifstream(str.c_str());

    if (stream->fail()) {
        throw Exception("[Scanner] Could not open file!");
    }
    return stream;
}

/**
 * Makes a stream from a string.
 *
 * @param str String to create stream from
 * @return Resulting stream
 */
istream* Scanner::createStreamFromString(const std::string &str) {
    return new istringstream(str);
}
