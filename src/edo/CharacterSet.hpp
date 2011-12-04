/*
 * CharacterSet.hpp
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#ifndef EDO_CHARACTERSET_HPP
#define EDO_CHARACTERSET_HPP
#include "edo/common.h"
namespace Edo {


/**
 * Collection of characters in a pattern.
 */
class CharacterSet {
public:
    virtual ~CharacterSet();
    virtual bool contains(char c) const = 0;
};

} // namespace Edo
#endif
