/*
 * Scanner.hpp
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#ifndef EDO_SCANNER_HPP
#define EDO_SCANNER_HPP
#include "edo/common.h"
#include "edo/CharacterSets.hpp"
#include "edo/Exception.hpp"
#include "edo/Path.hpp"
#include "edo/Pattern.hpp"
#include "edo/SimplePattern.hpp"
namespace Edo {


/**
 * Utility for parsing input using patterns.
 *
 * @see Pattern
 * @see Patterns
 * @see SimplePattern
 */
class Scanner {
public:
    Scanner(const Path &path);
    Scanner(const std::string &str);
    virtual ~Scanner();
    virtual bool hasNext(Pattern *pattern);
    virtual std::string next(Pattern *pattern);
    virtual Pattern* getDelimiter() const;
    virtual void setDelimiter(Pattern *pattern);
    virtual void close();
private:
    Scanner(const Scanner &scanner);
    Scanner& operator=(const Scanner &scanner);
// Instance variables
    std::istream *stream;
    Pattern *delimiter;
// Helpers
    static Pattern* createDefaultDelimiter();
    static std::istream* createStreamFromPath(const Path &path);
    static std::istream* createStreamFromString(const std::string &str);
// Constants
    static Pattern *DEFAULT_DELIMITER;
};

} // namespace Edo
#endif
