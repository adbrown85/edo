/*
 * Assert.hpp
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#ifndef EDO_ASSERT_HPP
#define EDO_ASSERT_HPP
#include <cmath>
#include <sstream>
#include "edo/common.h"
#include "edo/Exception.hpp"
namespace Edo {

void assertEquals(bool, bool);
void assertEquals(float x, float y, float epsilon=1e-4);
void assertEquals(int x, int y);
void assertEquals(const std::string &s1, const std::string &s2);

} /* namespace Edo */
#endif
