/*
 * Pattern.hpp
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#ifndef EDO_PATTERN_HPP
#define EDO_PATTERN_HPP
#include "edo/common.h"
namespace Edo {


/**
 * Designation of how elements may be repeated.
 */
enum Quantifier {
    QUANTIFIER_ONE,
    QUANTIFIER_ONE_OR_MORE,
    QUANTIFIER_ZERO_OR_ONE,
    QUANTIFIER_ZERO_OR_MORE
};


/**
 * Arrangement of characters that can be matched against input.
 */
class Pattern {
public:
    Pattern();
    virtual ~Pattern();
    virtual bool matches(std::istream &stream) const = 0;
    virtual std::string match(std::istream &stream) const = 0;
};

} // namespace Edo
#endif
